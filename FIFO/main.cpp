#include <iostream>
#include "Fifo.h"
#include "Global.h"


int main()
{
	try
	{
		cout << "FIFO queue" << endl;
		FQueue q;

		cout << "adding 4 elements" << endl;
		for( int i = 1; i < 9; i+=2 )
		{
			QINFO* pInfo = new QINFO( i, i+1, i+2 );
			q.FQEnqueue( pInfo );
		}
		cout << endl << "printing the queue" << endl;
		q.FQPrint();
		cout << endl;


		cout << "removing 2 elemets" << endl;
		q.FQDequeue();
		q.FQDequeue();

		cout << endl << "printing the queue" << endl;
		q.FQPrint();
		cout << endl;


		cout << "adding 3 elements" << endl;
		for( int i = 6; i < 9; i++ )
		{
			QINFO* pInfo = new QINFO( i, i + 5, i + 10 );
			q.FQEnqueue( pInfo );
		}
		cout << endl << "printing the queue" << endl;
		q.FQPrint();
		cout << endl;


		cout << "removing 3 elemets" << endl;
		for( int i = 0; i<3; i++ )
			q.FQDequeue();
		
		cout << endl << "printing the queue" << endl;
		q.FQPrint();
		cout << endl;


		cout << "adding 5 elements" << endl;
		for( int i = 15; i < 20; i++ )
		{
			QINFO* pInfo = new QINFO( i+3, i + 8, i + 11 );
			q.FQEnqueue( pInfo );
		}
		cout << endl << "printing the queue" << endl;
		q.FQPrint();
		cout << endl;


		cout << "clearing queue" << endl;
		q.FQClear();
		
		cout << endl << "printing the queue" << endl;
		q.FQPrint();
		cout << endl;


		cout << "adding dwa elements" << endl;
		for( int i = 7; i < 9; i++ )
		{
			QINFO* pInfo = new QINFO( i, i + 18, i + 30 );
			q.FQEnqueue( pInfo );
		}
		cout << endl << "printing the queue" << endl;
		q.FQPrint();
	}
	catch( FifoException& error )
	{
		cerr << endl << error.getReason() << endl;
	}
	catch( ... )
	{
		cerr << endl << "ERROR" << endl;
	}

	return 0;
}
