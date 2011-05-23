#ifndef FRIEND_H
#define FRIEND_H

#include "Contact.h"

class Friend : public Contact
{
public:
	Friend(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType);
	Friend(string *s);
	Friend(const Friend &fr);
	Contact::getFirstName;
	Contact::getLastName;
	Contact::getPhoneNumber;
	Contact::getOccupation;
	Contact::getEmailAddress;
	Contact::getGender;
	Contact::getAge;
	Contact::getBirthDate;
	Contact::getHomeAddress;
	Contact::getContactType;

	Contact::setContactType;
	Contact::setFirstName;
	Contact::setLastName;
	Contact::setPhoneNumber;
	Contact::setOccupation;
	Contact::setEmailAddress;
	Contact::setAge;
	Contact::setGender;
	Contact::setBirthDate;
	Contact::setHomeAddress;
	friend class List;
};
#endif