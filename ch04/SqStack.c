#include "SqStack.h"

Status SqStack_Push(SqStack *s, SElemType e) {
  if (s->top == MAXSIZE) {
    return ERROR;
  }
  s->top++;
  s->data[s->top] = e;
  return OK;
}

Status SqStack_Pop(SqStack *s, SElemType *e) {
  if (s->top == -1) {
    return ERROR;
  }
  *e = s->data[s->top];
  s->top--;
  return OK;
}
