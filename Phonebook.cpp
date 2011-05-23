#include "Phonebook.h"
#include <sstream>

bool Phonebook::mInstanceFlag = false;
Phonebook *Phonebook::mInstance = NULL;


Phonebook::Phonebook()
{
}

int Phonebook::loadPhonebook()
{
	ifstream phb(mFile,ios::app);
	if(!phb)
	{
		cout<<"\nCould not open phonebook file";
		return 0;
	}
	ZeroMemory(&ContactList, sizeof(ContactList));
	int i, k = 0;
	string str, tmp;
	string infs[100];
	while(phb)
	{
		getline(phb,str);
		if(str.size() <= 0) 
			continue;
		i = 0;
		k = 0;
		for(i = 0; i <= (int)str.size(); i++)
		{
			tmp.clear();
			while(i < (int)str.size() && str[i] != '|')
			{
				tmp += str[i++];
			}
			infs[k++]=tmp;
			
		}
		if(infs[0].compare("acquaintance") == 0)
			addAcquaintance(infs);
		else if(infs[0].compare("colleague") == 0)
				addColleague(infs);
		else if(infs[0].compare("friend") == 0)
				addFriend(infs);
		else cout<<infs[0]<<"\nThe phonebook file is corrupt\n";
		infs->clear();
		str.clear();
	}
	phb.close();
	memcpy(&tmpList, &ContactList, sizeof(ContactList));
	mData.open(mFile);
	if(!mData)
		return 0;
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

//int Phonebook::displayContacts(List list)
//{
//	cout<<"\n\nContacts:\n\n";
//	cout<<"size="<<list.getSize();
//	list.Show();
//	return 0;
//}

void Phonebook::deleteContact(int nIndex)
{
	ContactList.erase(ContactList.begin() + nIndex);
}

//List Phonebook::getContacts(List list, string contactType)
//{
//	if(contactType == "all")
//		return list;
//	List tmpList;
//	for(int i = 0; i < list.getSize(); i++)
//		if(list[i].getContactType() == contactType)
//			tmpList.add(list[i]);
//	return tmpList;
//}
//
//List Phonebook::search(string attribute, string crt, string contactType)
//{
//	List tmpList;
//	stringstream str;
//	int age;
//	str<<crt;
//	str>>age;
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
int Phonebook::savePhonebook(int save)
{
	if(!save)
		memcpy(&ContactList, &tmpList, sizeof(tmpList));
	deque<Contact>::iterator it;
	int i = 0;
	for(i = 0; i < ContactList.size(); i++)
	{
		mData<<ContactList[i].getContactType()<<"|";
		mData<<ContactList[i].getFirstName()<<"|";
		mData<<ContactList[i].getLastName()<<"|";
		mData<<ContactList[i].getPhoneNumber()<<"|";
		mData<<ContactList[i].getGender();
		if(ContactList[i].getContactType().compare("colleague") == 0 )
			mData<<"|"<<ContactList[i].getAge()<<"|"<<ContactList[i].getEmailAddress()<<"|"<<ContactList[i].getOccupation();
		if(ContactList[i].getContactType().compare("friend") == 0)
			{
				mData<<"|"<<ContactList[i].getAge()<<"|"<<ContactList[i].getEmailAddress()<<"|"<<ContactList[i].getOccupation();
				mData<<"|"<<ContactList[i].getBirthDate().toString()<<"|"<<ContactList[i].getHomeAddress();
		}
		mData<<endl;
	}
	mData.close();
	return 0;
}

Phonebook::~Phonebook()
{
	savePhonebook(1);
}
