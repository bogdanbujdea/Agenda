#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

#include "Contact.h"


class Acquaintance : public Contact
{
public:
	Acquaintance(string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType);
	Acquaintance(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType);
	Acquaintance(string *s);
	Acquaintance(const Acquaintance &acq);
	//Acquaintance& operator= (const Acquaintance &acq);
	Contact::getFirstName;
	Contact::getLastName;
	Contact::getPhoneNumber;
	Contact::getGender;
	Contact::getContactType;

	Contact::setContactType;
	Contact::setFirstName;
	Contact::setLastName;
	Contact::setPhoneNumber;
	Contact::setGender;
	friend class List;

	~Acquaintance();

	
};
#endif