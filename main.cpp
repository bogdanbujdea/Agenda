#include "IniFile.h"
#include "Phonebook.h"
#include <iomanip>
#include "Database.h"

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
				Database db("test.db");
				db.openDB();
				vector<vector<string>> q;
				try
				{
					 q = db.query("Select * from Phonebooks");
				}
				catch(string errmsg)
				{
					cout<<"\nError:"<<errmsg<<endl;
				}
				vector<vector<string>>::iterator it;
				for(it = q.begin(); it != q.end(); it++)
				{
					cout<<endl<<"at 0:"<<it->at(0)<<" \t at 1:"<<it->at(1)<<endl;
				}
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
				try{
					p.deleteContact(i);
				}
				catch(char *error)
				{
					cout<<endl<<error<<endl;
				}
				catch(int error)
				{
					cout<<"\nError number:"<<error<<endl;
				}
				break;
			}
		case 10:
			{	
				/*string s1,s2,s3;
				cout<<"\nAtribut:";
				getline(cin,s1);
				cout<<"\nCriteriu:";
				getline(cin,s2);
				cout<<"\nContactele de tip:";
				getline(cin,s3);*/
				//p.displayContacts(p.search(s1,s2,s3));
				cout<<"\n1.By first name";
				cout<<"\n2.By last name";
				try{
					int opt;
					cin>>opt;
					if(opt == 1)
						p.Sort(SORT_BY_FIRST_NAME);
					else 
						p.Sort(SORT_BY_LAST_NAME);
				}
				catch(char *error)
				{
					cout<<error<<endl;
				}
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
	Phonebook &pb = Phonebook::getInstance();
	IniFile iniFile("Settings.ini", "Settings");
	Database db("test.db");
	db.openDB();
	//cout<<"\nAlege agenda:";
	/*getline(cin, dir);*/
	vector<vector<string>> results;
	vector<vector<string>>::iterator it;
	string dir;
	try
	{
	db.query("CREATE TABLE IF NOT EXISTS Phonebooks(id INTEGER, name varchar(10));");
	results = db.query("SELECT COUNT(*) FROM Phonebooks");
	string tmp = results.at(0).at(0);
	int pbs = 0;
	pbs = atoi(tmp.c_str());
	if(pbs)
	{
		cout<<"Sunt "<<pbs<<" agende create\n";
		cout<<"1.Alege una";
		cout<<"\n2.Creeaza una noua";
		int opt;
		cin>>opt;
		if(opt == 1)
		{
			results = db.query("Select * from Phonebooks");
			for(it = results.begin(); it != results.end(); it++)
			{
				cout<<it->at(0)<<" -> "<<it->at(1)<<endl;
			}
			cout<<"\nIntrodu numele agendei alese:";
			cin>>dir;
		}
		else
		{
			cout<<"Introdu numele agendei noi:";
			cin>>dir;
			pbs++;
			char p[10];
			_itoa_s(pbs, p, 10);
			cout<<pbs<<" agende create "<<"p="<<p<<"\n";
			string q = "INSERT INTO Phonebooks VALUES(";
			q += p;
			q += "0, ";
			q += "\"";
			q += dir;
			q += "\");";
			db.query(q);
		}

	}
	else
	{
		cout<<"\n Inca nu a fost creata nicio agenda, creati una:";
		cin>>dir;
		string q = "INSERT INTO Phonebooks VALUES(0, ";
		q += "\"";
		q += dir;
		q += "\");";
		db.query(q);
	}
	dir += ".txt";
	pb.setFile(dir);
	pb.loadPhonebook();
	managePhonebook(pb);
	//int PbNo = iniFile.GetIntValue("Settings", "PbNo");
	//cout << "\nCurrently there are "<<PbNo<<" phone books created"<<endl;
	//if( !PbNo)
	//	InitPhonebook(pb, iniFile);
	//else
	//{
	//	string dir;
	//	for(int i = 0; i < PbNo; i++)
	//	{
	//		dir = "Pb";
	//		char ch[5];
	//		itoa(i, ch, 10);
	//		dir += ch;
	//		cout << iniFile.GetStringValue(dir, "Owner", "error") << endl;
	//		dir.clear();
	//	}
	
	//results = db.query("Select name from Phonebooks");
	}
	catch(string error)
	{
		cout<<error<<endl;
	}
	
	
	for(it = results.begin(); it != results.end(); it++)
		cout<<it->at(0)<<endl;
	cin>>dir;
	
	managePhonebook(pb);
	pb.savePhonebook(1);
	system("pause");
	return 0;
}