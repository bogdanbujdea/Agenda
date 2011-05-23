#ifndef ACQUAINTANCELIST_H
#define ACQUAINTANCELIST_H

#include "Acquaintance.h"

class AcquaintanceList
{
private:
	Acquaintance *mFirst;
	int mListSize;
public:
	AcquaintanceList();
	AcquaintanceList(Acquaintance acq);
	void addAcquaintance(Acquaintance acq);
	int deleteAcquaintance(int nIndex);
	Acquaintance& operator[] (const int nIndex);
	void Show();
};
#endif
