#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Contact.h"

class Colleague : public Contact
{
public:
	Colleague(string EmailAddress, string Occupation, int Age,string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID);
	Colleague(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID);
	Colleague(string *s);
	Colleague(const Colleague &col);
	Contact::getFirstName;
	Contact::getLastName;
	Contact::getPhoneNumber;
	Contact::getOccupation;
	Contact::getEmailAddress;
	Contact::getGender;
	Contact::getAge;
	Contact::getContactType;
	Contact::getID;

	Contact::setID;
	Contact::setContactType;
	Contact::setFirstName;
	Contact::setLastName;
	Contact::setPhoneNumber;
	Contact::setOccupation;
	Contact::setEmailAddress;
	Contact::setAge;
	Contact::setGender;
	friend class List;
};
#endif