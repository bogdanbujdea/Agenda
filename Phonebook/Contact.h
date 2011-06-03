
#ifndef CONTACT_H
#define CONTACT_H
#pragma warning( disable : 4290 )
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Contact
{
private:
	Contact *mPrevious, *mNext;
	
	friend int ShowPbOptions();
	friend void SetContact(int);
public:
	Contact();
	friend class List;
	friend class Phonebook;
	friend class CAgendaDlg;
	friend class PbDetails;

	Date mBirthDate;
	string mHomeAddress, mEmailAddress, mOccupation, mFirstName, mLastName, mPhoneNumber, mContactType, mGender;
	int mAge, mID;
	Contact(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID);
	Contact(string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID);
	Contact(string EmailAddress, string Occupation, int Age,string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID);

	string getFirstName();
	string getLastName();
	string getPhoneNumber();
	string getHomeAddress();
	string getOccupation();
	string getEmailAddress();
	string getGender();
	int	   getAge();
	int getID();
	Date getBirthDate();
	string getContactType() { return mContactType; }

	void setFirstName(string);
	void setLastName(string);
	void setPhoneNumber(string PhoneNumber);
	void setHomeAddress(string HomeAddress);
	void setOccupation(string Occupation);
	void setContactType(string ContactType);
	void setEmailAddress(string EmailAddress);
	void setGender(string Gender);
	void setAge(int Age);
	void setID(int ID);
	void setBirthDate(Date BirthDate);
	class WrongContactCreation : public logic_error {
  public:
    WrongContactCreation(string type)
    : logic_error("Cannot create type " + type) {}
  };
	static Contact* factory(const string& type, string *val)
		throw(WrongContactCreation);
};
#endif