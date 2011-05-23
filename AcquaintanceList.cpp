#include "AcquaintanceList.h"

AcquaintanceList::AcquaintanceList()
{
	mListSize = 0;
}

AcquaintanceList::AcquaintanceList(Acquaintance acq)
{
	mListSize = 0;
	mFirst = new Acquaintance(acq.getGender(), acq.getName(), acq.getPhoneNumber(), mListSize);
	mFirst->mNext = mFirst->mPrevious = NULL;
	mListSize++;
}


void AcquaintanceList::addAcquaintance(Acquaintance acq)
{
	Acquaintance *tmpAcq;
	tmpAcq = new Acquaintance(acq.getGender(), acq.getName(), acq.getPhoneNumber(), mListSize);
	tmpAcq->mNext = tmpAcq->mPrevious = NULL;
	Acquaintance *tmp = mFirst;
	if(!mListSize)
		mFirst = tmpAcq;
	else
	{
		
		while(tmp->getName().compare(tmpAcq->getName()) <= 0)
		{
			if(tmp->mNext != NULL)
				tmp = tmp->mNext;
			else break;
		}
			if(tmp->getName().compare(tmpAcq->getName()) >= 0)
			{
				if(tmp->mPrevious == NULL)
				{
					tmpAcq->mNext = tmp;
					tmp->mPrevious = tmpAcq;
					mFirst = tmpAcq;
				}
				else
				{
					tmpAcq->mPrevious = tmp->mPrevious;
					tmp->mPrevious->mNext = tmpAcq;
					tmpAcq->mNext = tmp;
					tmp->mPrevious = tmpAcq;
				}
			}
			else if(tmp->mNext == NULL)
			{
				tmp->mNext = tmpAcq;
				tmpAcq->mPrevious = tmp;
			}
	}
	tmp = mFirst;
	int index = 0;
	while(tmp->mNext != NULL)
	{
		tmp->mID = index++;
		tmp = tmp->mNext;
	}
	tmp->mID = index;
	mListSize++;
}

int AcquaintanceList::deleteAcquaintance(int nIndex)
{
	if(!mListSize)
	{
		cout<<"Empty List";
		return 0;
	}
	if(nIndex < 0 || nIndex >= mListSize)
	{
		cout<<"Invalid index";
		return 0;
	}
	if(mFirst == NULL)
		return -1;
	mListSize--;
	Acquaintance *tmp = mFirst;
	while(tmp->mNext != NULL && tmp->mID != nIndex)
		tmp = tmp->mNext;
	if(tmp->mID == nIndex)
	{
		if(tmp == mFirst)
		{
			mFirst->mNext->mPrevious = NULL;
			mFirst = mFirst->mNext;
			delete tmp;
			return 0;
		}
		else if(tmp->mNext == NULL)
		{
			tmp->mPrevious->mNext = NULL;
			delete tmp;
			return 0;
		}
		else
		{
			tmp->mPrevious->mNext = tmp->mNext;
			tmp->mNext->mPrevious = tmp->mPrevious;
			delete tmp;
			return 0;
		}
	}
	if(tmp->mNext = NULL)
	{
		tmp->mPrevious->mNext = NULL;
		delete tmp;
	}
	return nIndex;
}

void AcquaintanceList::Show()
{
	//for(int i = 0; i < mListSize; i++)
	//{
	//	cout<<"\nName:"<<mFirst[i].getName();
	//	cout<<"\nPhone Number:"<<mFirst[i].getPhoneNumber();
	//	cout<<"\nID:"<<mFirst[i].mID;
	//	cout<<"\nGender:"<<mFirst[i].getGender()<<endl;
	//}
	int i = 0;
	Acquaintance *tmp = mFirst;
	while(tmp)
	{
		cout<<"Name:"<<tmp->getName();
		//cout<<"\nPhone Number:"<<tmp->getPhoneNumber();
		cout<<"ID:"<<tmp->mID<<endl;
		//cout<<"\nGender:"<<tmp->getGender()<<endl;
		tmp = tmp->mNext;
		i++;
	}
}


Acquaintance& AcquaintanceList::operator[] (const int nIndex)
{
    Acquaintance *tmp = mFirst;
	while(tmp->mNext != NULL && tmp->mID != nIndex)
		tmp = tmp->mNext;
	if(tmp->mID == nIndex)
		return *tmp;
	return *tmp;
}