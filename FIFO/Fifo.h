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
  default: return "ERROR: Other Error";
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
  FQItem* pHead;
  FQItem* pTail;

public:
  FQueue();
  virtual ~FQueue();

  bool    FQEmpty();
  int     FQEnqueue( QINFO* p );
  QINFO*  FQDequeue();
  void    FQClear();
  void    FQDel();
  void    FQPrint();
};

