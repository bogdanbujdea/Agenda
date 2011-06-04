#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

#include "Contact.h"


class Acquaintance : public Contact
{
	friend class Contact;
	Acquaintance(string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID);
	Acquaintance(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID);
	Acquaintance(string *s);
	Acquaintance(const Acquaintance &acq);
public:
	//Acquaintance& operator= (const Acquaintance &acq);
	Contact::getFirstName;
	Contact::getLastName;
	Contact::getPhoneNumber;
	Contact::getGender;
	Contact::getContactType;
	Contact::getID;

	Contact::setID;
	Contact::setContactType;
	Contact::setFirstName;
	Contact::setLastName;
	Contact::setPhoneNumber;
	Contact::setGender;
	friend class List;

	~Acquaintance();

	
};
#endif