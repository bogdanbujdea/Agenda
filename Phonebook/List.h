#ifndef LIST_H
#define LIST_H

#include "Acquaintance.h"
#include "Colleague.h"
#include "Friend.h"


class List
{
private:
	Contact *mFirst;
	int mListSize;
public:
	List();
	template <typename T>
	void add(T contact);
	int getSize() { return mListSize; }
	int Delete(int nIndex);
	Contact& operator[] (const int nIndex);
	void setSize(int size);
	void Show();
};

template <typename T>
void List::add(T contact)
{
	Contact *tmpContact;
	tmpContact = new T(contact);
	Contact *tmp = mFirst;
	tmpContact->mNext = tmpContact->mPrevious = NULL;
	if(!mListSize)
		mFirst = tmpContact;
	else
	{
		while(_stricmp(tmp->getLastName().c_str(), tmpContact->getLastName().c_str()) <= 0)
		{
			if(tmp->mNext != NULL)
				tmp = tmp->mNext;
			else break;
		}
			if( _stricmp( tmp->getLastName().c_str(), tmpContact->getLastName().c_str() ) >= 0 )
			{
				if(tmp->mPrevious == NULL)
				{
					tmpContact->mNext = tmp;
					tmp->mPrevious = tmpContact;
					mFirst = tmpContact;
				}
				else
				{
					tmpContact->mPrevious = tmp->mPrevious;
					tmp->mPrevious->mNext = tmpContact;
					tmpContact->mNext = tmp;
					tmp->mPrevious = tmpContact;
				}
			}
			else if(tmp->mNext == NULL)
			{
				tmp->mNext = tmpContact;
				tmpContact->mPrevious = tmp;
			}
	}
	mListSize++;
}


#endif
