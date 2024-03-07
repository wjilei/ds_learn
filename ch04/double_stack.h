#ifndef _DB_STACK_H_
#define _DB_STACK_H_

#include "../utils.h"

typedef struct {
  ElemType data[MAXSIZE];
  int top1;
  int top2;
}SqDoubleStack;


Status db_stack_push(SqDoubleStack *s, ElemType e, int stack_number);
Status db_stack_pop(SqDoubleStack *s, ElemType *e, int stack_number);

#endif
