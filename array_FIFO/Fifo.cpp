#include "Fifo.h"

//----------FQueue---------//
FQueue::FQueue( int maxelem )
{
	if( maxelem < 2 )
		throw FifoException( FIFO_SIZE );
	pInfo = new( nothrow ) QINFO*[maxelem];//new QINFO*[nMaxElem];
	if( !pInfo )
		throw FifoException( FIFO_OVERFLOW );
	nMaxElem = maxelem;
	nHead = nTail = nNoElem = 0;
}

FQueue::~FQueue()
{
	FQClear();
	delete[] pInfo;
}

bool FQueue::FQEmpty()const
{
	return !(this->nNoElem);
}

bool FQueue::FQFull()const
{
	return nNoElem == nMaxElem;
}

int FQueue::FQEnqueue( QINFO* Info )
{
	if( FQFull() )
		throw FifoException( FIFO_OVERFLOW );

	pInfo[nTail] = Info;
	nTail = (nTail + 1) % nMaxElem;
	nNoElem++;

	return 1;
}

QINFO* FQueue::FQDequeue()
{
	if( FQEmpty() )
		throw FifoException(FIFO_UNDERFLOW);

	QINFO* Info = pInfo[nHead];

	FQDel();
	return Info;
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

	pInfo[nHead] = nullptr;
	nHead = (nHead + 1) % nMaxElem;
	nNoElem--;
}

void FQueue::FQPrint( )
{
	if( FQEmpty() )
		cout << "Queue is empty" << endl;

	int counter = 0;
	int i = nHead;

	while( counter < nNoElem )
	{
		cout << (*pInfo[i]);
		i = (i + 1) % nMaxElem;
		counter++;
	}

	//int i = nHead;
	//if( FQFull() )
	//{
	//	cout << (*pInfo[i]);
	//	i = (i + 1) % nMaxElem;
	//}
	//while( i != nTail )
	//{
	//	cout << (*pInfo[i]);
	//	i = (i + 1) % nMaxElem;
	//}
}


