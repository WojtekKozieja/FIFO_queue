#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
using namespace std;

#define QINFO QInfo

struct QInfo
{
	int key;
	int* pTab; // dynamic array

	QInfo( int key, int a, int b );
	virtual ~QInfo();
	friend ostream& operator << ( ostream& out, const QINFO& info );
};

#endif
