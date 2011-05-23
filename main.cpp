#include "IniFile.h"
#include "Phonebook.h"
#include <iomanip>

int managePhonebook(Phonebook &p);

int InitPhonebook(Phonebook &p, IniFile &ini) 
{
	string tmp;
	cout<<"\nEnter your name:";
	getline(cin, tmp);
	ini.CreateSection("Pb0");
	ini.WriteValue("Pb0", "Owner", tmp);
	ini.WriteValue("Settings", "PbNo", "1");
	tmp += ".txt";
	p.setFile(tmp);
	p.loadPhonebook();
	managePhonebook(p);
	return 1;
}

int managePhonebook(Phonebook &p)
{
	string str;
	int opt;
	while(1)
	{
		system("cls");
		cout<<"1.View acquaintances\n";
		cout<<"2.View colleagues\n";
		cout<<"3.View friends\n";
		cout<<"4.View all contacts\n";
		cout<<"5.Add acquaintance\n";
		cout<<"6.Add colleague\n";
		cout<<"7.Add friend\n";
		cout<<"8.Save phone book\n";
		cout<<"9.Delete contact\n";
		cout<<"10.Sort\n";
		cout<<"0.Save and exit\n";
		cout<<"\nChoose one option:";
		cin>>opt;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		cin.ignore(1000, '\n');
		if(cin.gcount() > 1)
			continue;
		switch(opt)
		{
		case 0:
			{
				return 0;
			}
		case 1:
			{
				deque<Contact> list;
				list = p.getContacts(p.ContactList, "acquaintance");
				p.displayContacts(list);
				break;
			}
		case 2:
			{
				//p.displayContacts(p.getContacts(p.ContactList, "colleague"));
				break;
			}
		case 3:
			{
				//p.displayContacts(p.getContacts(p.ContactList, "friend"));
				break;
			}
		case 4:
			{
				//p.displayContacts(p.getContacts(p.ContactList, "contactlist"));
				break;
			}
		case 5:
			{
				string fname, lname, number, gender;
				cout<<"\nFirst Name:"; getline(cin, fname);
				cout<<"\nLast Name:"; getline(cin, lname);
				cout<<"\nPhone number:"; getline(cin, number);
				cout<<"\nGender:"; getline(cin, gender);
				Acquaintance acq(gender, fname, lname, number, "acquaintance");
				acq.setContactType("acquaintance");
				p.ContactList.push_back(acq);
				break;
			}
		case 8:
			{
				p.savePhonebook(1);
				break;
			}
		case 9:
			{
				int i;
				cout<<"\nindex=";
				cin>>i;
				p.deleteContact(i);
				break;
			}
		case 10:
			{	string s1,s2,s3;
				cout<<"\nAtribut:";
				getline(cin,s1);
				cout<<"\nCriteriu:";
				getline(cin,s2);
				cout<<"\nContactele de tip:";
				getline(cin,s3);
				//p.displayContacts(p.search(s1,s2,s3));
				break;
			}
		default:
			cout<<"\nWrong option\n";
		}
		system("pause");
	}
}


int main()
{
	IniFile iniFile("Settings.ini", "Settings");
	Phonebook &pb = Phonebook::getInstance();
	int PbNo = iniFile.GetIntValue("Settings", "PbNo");
	cout << "\nCurrently there are "<<PbNo<<" phone books created"<<endl;
	if( !PbNo)
		InitPhonebook(pb, iniFile);
	else
	{
		string dir;
		for(int i = 0; i < PbNo; i++)
		{
			dir = "Pb";
			char ch[5];
			itoa(i, ch, 10);
			dir += ch;
			cout << iniFile.GetStringValue(dir, "Owner", "error") << endl;
			dir.clear();
		}
		cout<<"\nAlege agenda:";
		getline(cin, dir);
		dir += ".txt";
		pb.setFile(dir);
		pb.loadPhonebook();
		managePhonebook(pb);
	}
	pb.savePhonebook(1);
	system("pause");
	return 0;
}