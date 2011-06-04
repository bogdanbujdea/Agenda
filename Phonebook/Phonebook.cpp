#include "Phonebook.h"
#include <sstream>
#pragma warning( disable : 4290 )

bool Phonebook::mInstanceFlag = false;
Phonebook *Phonebook::mInstance = NULL;

string oldDB;

Phonebook::Phonebook()
{
	Changed = false;
	ContactDB = new Database(mDbName);
}

Contact* Contact::factory(const string& type, string *val)
	throw(Contact::WrongContactCreation)
{
	if(type == "acquaintance") return new Acquaintance(val);
	if(type == "colleague") return new Colleague(val);
	if(type == "friend") return new Friend(val);
	throw WrongContactCreation(type);
}

int Phonebook::loadPhonebook()
{
	if(!ContactDB->openDB())
	{
		MessageBox(0, "Can't open database", "ERROR", 0);
		return 0;
	}
	ContactList.erase(ContactList.begin(), ContactList.end());
	vector<vector<string>> retVal;
	char Query[500];
	try
	{
		sprintf(Query, "SELECT * FROM %s;", mPbName.c_str());
		retVal = ContactDB->query(Query);
		int i, j;
		string info[20];
		string type;
		
		for(i = 0; i < (int) retVal.size(); i++)
		{
			for(int j = 0; j < (int) retVal.at(i).size(); j++)
				info[j] = retVal.at(i).at(j);
			try
			{
				ContactList.push_back(*Contact::factory(info[1], info));
			}
			catch(Contact::WrongContactCreation ct)
			{
				MessageBox(0, ct.what(), "Wrong Contact Type", MB_ICONWARNING);
				return 0;
			}
			info->clear();
		}
	
	}
	catch(string error)
	{
		MessageBox(0, error.c_str(), "exception load pb", 0);
		ContactDB->close();
	}
	ContactDB->close();
	string tmp = mPbName;
	tmp = mPbFolderPath;
	tmp += "\\";
	tmp += mPbName;
	tmp += ".db~";
	oldDB = ContactDB->getDbName();
	if(!CopyFile(ContactDB->getDbName().c_str(), tmp.c_str(), 0))
		MessageBox(0, "Can't create tmp database", 0, 0);
	else
		ContactDB->setDbName(tmp);
	return 1;
}

string Phonebook::getOwner() { return mOwner; }

void Phonebook::setOwner(string owner) { mOwner = owner; }


void Phonebook::deleteContact(int nIndex)
{
	if(nIndex < 0 || nIndex > (int)ContactList.size())
		throw("Index out of range");
	else
	ContactList.erase(ContactList.begin() + nIndex);
}

deque<Contact> Phonebook::getContacts(deque<Contact> list, string contactType)
{
	if(!contactType.compare("all"))
		return list;
	deque<Contact> tmpList;
	for(int i = 0; i < (int)list.size(); i++)
		if(list[i].getContactType() == contactType)
			tmpList.push_back(list[i]);
	return tmpList;
}
//
deque<Contact> Phonebook::search(string attribute, string crt, string contactType)
{
	deque<Contact> tmpList;
	Iterator *it = createIterator();
	it->first();
	stringstream str;
	int age;
	str<<crt;
	str>>age;
	for(it->first(); !it->isDone(); it->next())
	{
		if(attribute == "firstname" && it->currentItem()->getFirstName().find(crt) != string::npos)
			tmpList.push_back(*it->currentItem());
		if(attribute == "occupation" && it->currentItem()->getOccupation().find(crt) != string::npos)
			tmpList.push_back(*it->currentItem());
		else if(attribute == "lastname" && it->currentItem()->getLastName().find(crt) != string::npos)
			tmpList.push_back(*it->currentItem());
		else if(attribute == "gender" && it->currentItem()->getGender().find(crt) != string::npos)
			tmpList.push_back(*it->currentItem());
		else if(attribute == "birth date" && it->currentItem()->getBirthDate().toString() == crt)
			tmpList.push_back(*it->currentItem());
		else if(attribute == "number" && it->currentItem()->getPhoneNumber().find(crt) != string::npos)
			tmpList.push_back(*it->currentItem());
		else if(attribute == "email" && it->currentItem()->getEmailAddress().find(crt) != string::npos)
			tmpList.push_back(*it->currentItem());
		else if(attribute == "address" && it->currentItem()->getHomeAddress().find(crt) != string::npos)
			tmpList.push_back(*it->currentItem());
		else if(attribute == "age" && it->currentItem()->getAge() == age)
			tmpList.push_back(*it->currentItem());
	}
	return getContacts(tmpList, contactType);
}





bool sortByLastName (Contact c1, Contact c2)
{
   
    return c1.getLastName() < c2.getLastName();
}

bool sortByID (Contact c1, Contact c2)
{
   
    return c1.getID() < c2.getID();
}


bool sortByFirstName (Contact c1, Contact c2)
{
    return c1.getFirstName() < c2.getFirstName();
}

void Phonebook::Sort(int SortType)
{
	switch(SortType)
	{
	case SORT_BY_FIRST_NAME:
		sort(ContactList.begin(), ContactList.end(), sortByFirstName);
		break;
	case SORT_BY_LAST_NAME:
		sort(ContactList.begin(), ContactList.end(), sortByLastName);
	case SORT_BY_ID:
		sort(ContactList.begin(), ContactList.end(), sortByID);
		break;
	default:
		throw("Invalid type of sort");
	}
}

int Phonebook::savePhonebook(int save)
{
	if(!save)
		DeleteFile(ContactDB->getDbName().c_str()); 
	else
	{
		if(!CopyFile(ContactDB->getDbName().c_str(), oldDB.c_str(), 0) || !DeleteFile(ContactDB->getDbName().c_str()))
			MessageBox(0, "Can't save the phone book!", "Error save", 0);
	}
	
	return 0;
}

Phonebook::~Phonebook()
{
	savePhonebook(1);
}

Iterator *Phonebook::createIterator() 
{
	return new Iterator(this);
}