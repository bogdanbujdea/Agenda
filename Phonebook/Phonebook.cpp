#include "Phonebook.h"
#include <sstream>

bool Phonebook::mInstanceFlag = false;
Phonebook *Phonebook::mInstance = NULL;

string oldDB;

Phonebook::Phonebook()
{
	Changed = false;
	ContactDB = new Database(mDbName);
}

int Phonebook::loadPhonebook()
{
	ifstream phb;//("c:\\l.txt",ios::app);
	if(!ContactDB->openDB())
	{
		MessageBox(0, "Can't open database", "ERROR", 0);
		return 0;
	}
	//ZeroMemory(&ContactList, sizeof(ContactList));
	ContactList.erase(ContactList.begin(), ContactList.end());
	vector<vector<string>> retVal;
	char Query[500];
	try
	{
		cout<<"\npb to be opened="<<mPbName<<endl;
		sprintf(Query, "SELECT * FROM %s;", mPbName.c_str());
		retVal = ContactDB->query(Query);
		int i, j;
		string info[20];
		string type;
		cout<<"\nretval size()="<<retVal.size()<<endl;
		
		for(i = 0; i < (int) retVal.size(); i++)
		{
			for(int j = 0; j < (int) retVal.at(i).size(); j++)
				cout<<"at["<<i<<"]["<<j<<"]="<<retVal.at(i).at(j)<<endl;
			cout<<endl;
		}
		for(i = 0; i < (int) retVal.size(); i++)
		{
			for(int j = 0; j < (int) retVal.at(i).size(); j++)
				info[j] = retVal.at(i).at(j);
			
			cout<<"\nctc type="<<info[1]<<endl;
			
			if(info[1].compare("acquaintance") == 0)
				addAcquaintance(info);
			else if(info[1].compare("colleague") == 0)
					addColleague(info);
			else if(info[1].compare("friend") == 0)
					addFriend(info);
			else 
				{
					cout<<info[1]<<"\nThe phonebook file is corrupt\n";
					ContactDB->close();
					return 0;
			}
			info->clear();
		}
		//for(int i = 0; i < ContactList.size(); i++)
		//{
		//	cout<<"\ni="<<i<<" contact name="<<ContactList[i].getFirstName()<<endl;
		//}
	/*			cout<<"\nat["<<i<<"]["<<j<<"]="<<retVal.at(i).at(j);
			cout<<endl;
		}*/
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
	cout<<"\ntmp db="<<tmp<<endl;
	if(!CopyFile(ContactDB->getDbName().c_str(), tmp.c_str(), 0))
		MessageBox(0, "Can't create tmp database", 0, 0);
	else
		ContactDB->setDbName(tmp);
	return 1;
}

string Phonebook::getOwner() { return mOwner; }

void Phonebook::setOwner(string owner) { mOwner = owner; }

int Phonebook::addAcquaintance(string *s)
{
	Acquaintance tmp(s);
	ContactList.push_back(tmp);
	return 1;
}

int Phonebook::addColleague(string *s)
{
	Colleague col(s);
	ContactList.push_back(col);
	return 0;
}

int Phonebook::addFriend(string *s)
{
	Friend fr(s);
	ContactList.push_back(fr);
	return 0;
}

int Phonebook::displayContacts(deque<Contact> list)
{
	cout<<"\n\nContacts:\n\n";
	cout<<"size="<<list.size();
	for(int i = 0; i < (int)list.size(); i++)
	{
		cout<<"\nFirst Name:"<<list[i].getFirstName();
		cout<<"\nLast Name:"<<list[i].getLastName();
		cout<<"\nPhone number:"<<list[i].getPhoneNumber();
		cout<<"\nGender:"<<list[i].getGender()<<endl<<endl;
	}
	return 0;
}

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
//List Phonebook::search(string attribute, string crt, string contactType)
//{
//	List tmpList;
//	stringstream str;
//	int age;
//	str<<crt;
//str>>age;
//	for(int i = 0; i < ContactList.getSize(); i++)
//	{
//		if(attribute == "occupation" && ContactList[i].getOccupation().find(crt) != string::npos)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "lastname" && ContactList[i].getLastName().find(crt) != string::npos)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "firstname" && ContactList[i].getFirstName().find(crt) != string::npos)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "gender" && ContactList[i].getGender().find(crt) != string::npos)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "birth date" && ContactList[i].getBirthDate().toString() == crt)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "number" && ContactList[i].getPhoneNumber().find(crt) != string::npos)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "email" && ContactList[i].getEmailAddress().find(crt) != string::npos)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "address" && ContactList[i].getHomeAddress().find(crt) != string::npos)
//			tmpList.add(ContactList[i]);
//		else if(attribute == "age" && ContactList[i].getAge() == age)
//			tmpList.add(ContactList[i]);
//	}
//	return getContacts(tmpList, contactType);
//}





bool sortByLastName (Contact c1, Contact c2)
{
    /* a person is less than another person
     * - if the last name is less
     * - if the last name is equal and the first name is less
     */
    return c1.getLastName() < c2.getLastName();
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
		cout<<"\nerror="<<GetLastError()<<endl;
	}
	
	return 0;
}

Phonebook::~Phonebook()
{
	//savePhonebook(1);
}

Iterator *Phonebook::createIterator() 
{
	return new Iterator(this);
}