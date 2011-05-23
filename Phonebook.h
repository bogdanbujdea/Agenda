#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "List.h"
#include <windows.h>
#include <fstream>


using namespace std;

class Phonebook
{
private:
	string mFile, mOwner;
	ofstream mData;
	static Phonebook *mInstance;
	static bool mInstanceFlag;
	List tmpList;
	Phonebook();
	Phonebook(const Phonebook&);
public:
	List ContactList;
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
	void setFile(string File) { mFile = File; }
	void operator=(Phonebook&);
	int addAcquaintance(string *s);
	int addColleague(string *s);
	int addFriend(string *s);
	int editContact();
	string getOwner();
	List getContacts(List list, string contactType);
	int deleteContact(int nIndex);
	int displayContacts(List list);
	List search(string attribute, string crt, string contactType);
	int loadPhonebook();
	int savePhonebook(int);
	void setOwner(string owner);
	int closePhonebook();
	~Phonebook();
};
#endif