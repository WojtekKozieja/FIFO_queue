#pragma once

#include "global.h"

#define FIFO_OVERFLOW 0x01
#define FIFO_UNDERFLOW 0x02
#define FIFO_SIZE 0x3

class FifoException
{
public:
	FifoException( int errCode ) { mErrCode = errCode; }
	const char* getReason()const;
private:
	int mErrCode;

};

inline  const char* FifoException::getReason() const
{
	switch( mErrCode )
	{
	case FIFO_OVERFLOW:   return "ERROR: memory allocation error\n";
	case FIFO_UNDERFLOW:  return "ERROR: FIFO is empty\n";
	case FIFO_SIZE:				return "ERROR: FIFO is too small\n";
	default:              return "ERROR: Other Error\n";
	}
}

class FQueue
{
private:
	QINFO** pInfo;
	int nHead;
	int nTail;
	int nNoElem;
	int nMaxElem;

public:
	FQueue( int maxelem );
	virtual ~FQueue();

	bool    FQEmpty() const;
	bool    FQFull() const;
	int     FQEnqueue( QINFO* p );
	QINFO*  FQDequeue();
	void    FQClear();
	void    FQDel();
	void    FQPrint();
};



/*
#pragma once

#include "global.h"

#define FIFO_OVERFLOW 0x01
#define FIFO_UNDERFLOW 0x02
#define FIFO_UNDEFINED 0xFFFF

class FifoException
{
public:
	FifoException( int errCode ) { mErrCode = errCode; }
	const char* getReason();
private:
	int mErrCode;

};

inline  const char* FifoException::getReason()
{
	switch( mErrCode )
	{
	case FIFO_OVERFLOW:   return "ERROR: memory allocation error\n";
	case FIFO_UNDERFLOW:  return "ERROR: FIFO is empty\n";
	default: return "ERROR: Other error";
	}
}

class FQItem
{
private:
	QINFO* pInfo;
	FQItem* pNext;
public:
	FQItem( QINFO* pInfo );
	virtual ~FQItem();
	friend class FQueue;
};


class FQueue
{
private:
	QINFO* pHead;
	QINFO* pTail;

public:
	FQueue();
	virtual ~FQueue();

	bool    FQEmpty();
	int     FQEnqueue( QINFO* p ); // wstawia now¹ rzecz na koniec
	QINFO* FQDequeue();
	void    FQClear();
	void    FQDel();
	void    FQPrint();
};





#include "Fifo.h"


//---------FQItem----------//

FQItem::FQItem( QINFO* pInfo )
{
	this->pInfo = pInfo;
	this->pNext = NULL;
}

FQItem::~FQItem()
{
	//delete pInfo;
}





*/