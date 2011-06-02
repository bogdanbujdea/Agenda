#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Acquaintance.h"
#include "Colleague.h"
#include "Friend.h"
#include "Database.h"
#include <windows.h>
#include <algorithm>
#include <fstream>
#include <deque>

using namespace std;

enum TypeOfSort
{
	SORT_BY_FIRST_NAME,
	SORT_BY_LAST_NAME,
};

class Phonebook
{
private:
	string mDbName, mOwner, mPbName;
	ofstream mData;
	static Phonebook *mInstance;
	static bool mInstanceFlag;
	deque<Contact> tmpList;
	Phonebook();
	Phonebook(const Phonebook&);
public:
	string getPbName() { return mPbName; }
	void setPbName(string PbName) { mPbName = PbName; }
	Database *ContactDB;
	deque<Contact> ContactList;
	static Phonebook& getInstance()
	{
		if(!mInstanceFlag)
		{
			mInstance = new Phonebook();
			mInstanceFlag = true;
			return *mInstance;
		}
		else 
		{
			return *mInstance;
		}
	}
	void setDbName(string Name) { mDbName = Name; }
	void operator=(Phonebook&);
	int addAcquaintance(string *s);
	int addColleague(string *s);
	int addFriend(string *s);
	int editContact();
	string getOwner();
	deque<Contact> getContacts(deque<Contact> list, string contactType);
	void deleteContact(int nIndex);
	int displayContacts(deque<Contact> list);
	//List search(string attribute, string crt, string contactType);
	friend bool sortByName(Contact c1, Contact c2);
	void Sort(int SortType);
	int loadPhonebook();
	int savePhonebook(int);
	void setOwner(string owner);
	int closePhonebook();
	~Phonebook();
	friend class Iterator;
	Iterator *createIterator() ;
};

	
class Iterator
{
private:
	int index;
	Phonebook *phoneBook;
public:
	Iterator(Phonebook *p) { phoneBook = p; index = 0; }
	void first()
	{
		index = 0;
	}
	void next()
	{
		if(!isDone())
			index++;
	}
	bool isDone()
	{
		return index == phoneBook->ContactList.size();
	}

	Contact *currentItem()
	{
		return &phoneBook->ContactList[index];
	}
	
};
#endif