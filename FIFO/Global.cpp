#include "Global.h"

QInfo::QInfo( int mkey, int a, int b )
{
	key = mkey;
	pTab = new int[2];
	pTab[0] = a;
	pTab[1] = b;
	
}

QInfo::~QInfo()
{
	
}

ostream& operator << ( ostream& out, const QINFO& info )
{
	out << "key=" << info.key << " pTab[0]=" << info.pTab[0] << " pTab[1]=" << info.pTab[1] << endl; //"pTab[0]: " << info.pTab[0] << endl;
	return out;
}
