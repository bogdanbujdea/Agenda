
#ifndef CONTACT_H
#define CONTACT_H

#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Contact
{
private:
	Contact *mPrevious, *mNext;
	int mID;
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
	int mAge;
	Contact(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType);
	Contact(string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType);
	Contact(string EmailAddress, string Occupation, int Age,string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType);

	string getFirstName();
	string getLastName();
	string getPhoneNumber();
	string getHomeAddress();
	string getOccupation();
	string getEmailAddress();
	string getGender();
	int	   getAge();
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
	void setBirthDate(Date BirthDate);
};
#endif