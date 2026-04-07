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




//----------FQueue---------//
FQueue::FQueue()
{
	pHead = pTail = nullptr;
}
FQueue::~FQueue()
{
	FQClear();
}

bool FQueue::FQEmpty()
{
	return !(this->pHead);
}

int FQueue::FQEnqueue( QINFO* pInfo )
{
	FQItem* pNew = new( nothrow ) FQItem( pInfo );
	if( !pNew )
		throw FifoException( FIFO_OVERFLOW );

	if( FQEmpty() )
		this->pHead = pNew;
	else
		this->pTail->pNext = pNew;

	this->pTail = pNew;
	return 1;
}

QINFO* FQueue::FQDequeue()
{
	if( FQEmpty() )
		throw FifoException( FIFO_UNDERFLOW );

	QINFO* pInfo = this->pHead->pInfo;
	FQDel();
	return pInfo;
}


void FQueue::FQClear()
{
	while( !FQEmpty() )
		FQDel();
	return;
}

void FQueue::FQDel()
{
	if( FQEmpty() )
		throw FifoException(FIFO_UNDERFLOW);

	FQItem* p = this->pHead;
	this->pHead = p->pNext;

	if( FQEmpty() )
	{
		this->pTail = nullptr;
	}
	delete ( p );
}

void FQueue::FQPrint( )
{
	if( FQEmpty() )
		cout << "Queue is empty" << endl;

	FQItem* x = this->pHead;
	while( x )
	{
		cout << ( *(x->pInfo) );
		x = x->pNext;
		
	}
}



