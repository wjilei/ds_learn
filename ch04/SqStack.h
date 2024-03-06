#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__

#include "../utils.h"

typedef int SElemType;
typedef struct {
  SElemType data[MAXSIZE];
  int top;
}SqStack;


Status SqStack_Push(SqStack *s, SElemType e);
Status SqStack_Pop(SqStack *s, SElemType *e);


#endif
