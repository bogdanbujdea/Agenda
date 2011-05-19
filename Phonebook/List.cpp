#include "List.h"


List::List()
{
	mListSize = 0;
	mFirst = NULL;
}

int List::Delete(int nIndex)
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
	Contact *tmp = mFirst;
	int i = 0;
	while(tmp->mNext != NULL && i != nIndex)
	{
		tmp = tmp->mNext;
		i++;
	}
	if(i == nIndex)
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
	return i;
}

void List::Show()
{
	//int i = 0;
	//Contact *tmp = mFirst;
	//if(tmp == NULL)
	//	cout<<"\nempty list\n";
	//else
	//while(tmp)
	//{
	//	cout<<"Name:"<<tmp->getName();
	//	cout<<"\nPhone Number:"<<tmp->getPhoneNumber();
	//	cout<<"\nID:"<<i;
	//	cout<<"\nGender:"<<tmp->getGender()<<endl<<endl;
	//	tmp = tmp->mNext;
	//	i++;
	//}
}

void List::setSize(int size) { mListSize = size; }

Contact& List::operator[] (const int nIndex)
{
    Contact *tmp = mFirst;
	if(tmp == NULL || nIndex < 0 || nIndex > mListSize)
	{
		MessageBox(0,"Index error or list is empty",0,0);
		exit(0);
	}
	int i = 0;
	while(tmp != NULL)
	{
		if(nIndex == i)
		{	
			return *tmp;
		}
		else
		{
			tmp = tmp->mNext;
			i++;
		}
	}
	if(nIndex == mListSize)
	{
		MessageBox(0,"Element not found",0,0);
		exit(0);
		return *tmp;
	}
}