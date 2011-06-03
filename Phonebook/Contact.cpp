
#include "Contact.h"

using namespace std;

Contact::Contact()
{
	mGender			= "";
	mFirstName		= "";
	mLastName		= "";
	mPhoneNumber	= "";
	mEmailAddress	= "";
	mOccupation		= "";
	mHomeAddress	= "";
	mBirthDate.setYear(0);
	mAge			= 0;
	mID = -1;
}

Contact::Contact(string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID)
{
	mContactType	= ContactType;
	mGender			= Gender;
	mFirstName		= FirstName;
	mLastName		= LastName;
	mPhoneNumber	= PhoneNumber;
	mID				= ID;

	mEmailAddress	= "";
	mOccupation		= "";
	mHomeAddress	= "";
	mBirthDate.setYear(0);
	mAge			= -1;

}

Contact::Contact(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID)
{
	mContactType	= ContactType;
	mGender			= Gender;
	mFirstName		= FirstName;
	mLastName		= LastName;
	mPhoneNumber	= PhoneNumber;
	mEmailAddress	= EmailAddress;
	mOccupation		= Occupation;
	mHomeAddress	= HomeAddress;
	mBirthDate		= BirthDate;
	mAge			= Age;
	mID = ID;
}

Contact::Contact(string EmailAddress, string Occupation, int Age,string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID)
{
	mContactType	= ContactType;
	mEmailAddress	= EmailAddress;
	mOccupation		= Occupation;
	mAge			= Age;
	mGender			= Gender;
	mFirstName		= FirstName;
	mLastName		= LastName;
	mPhoneNumber	= PhoneNumber;
	mID = ID;

	mHomeAddress	= "";
	mBirthDate.setYear(0);
	
}




string Contact::getFirstName() { return mFirstName; }
string Contact::getLastName() { return mLastName; }
string Contact::getPhoneNumber() { return mPhoneNumber; }
string Contact::getOccupation() { return mOccupation; }
Date Contact::getBirthDate() { return mBirthDate; }
string Contact::getEmailAddress() { return mEmailAddress; }
string Contact::getHomeAddress() { return mHomeAddress; }
string Contact::getGender() { return mGender; }
int Contact::getAge() { return mAge; }
int Contact::getID() { cout<<"\nreturned id="<<mID<<endl; return mID; }

void Contact::setID(int ID) { mID = ID; }
void Contact::setFirstName(string FirstName) { mFirstName = FirstName; }
void Contact::setLastName(string LastName) { mLastName = LastName; }
void Contact::setPhoneNumber(string PhoneNumber) { mPhoneNumber = PhoneNumber; }
void Contact::setOccupation(string Occupation) { mOccupation = Occupation; }
void Contact::setContactType(string ContactType) { mContactType = ContactType; }
void Contact::setEmailAddress(string EmailAddress) { mEmailAddress = EmailAddress; }
void Contact::setAge(int Age) { mAge = Age; }
void Contact::setGender(string Gender) { mGender = Gender; }
void Contact::setHomeAddress(string HomeAddress) { mHomeAddress = HomeAddress; }
void Contact::setBirthDate(Date BirthDate) { mBirthDate = BirthDate; }
