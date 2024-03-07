#include "double_stack.h"
#include "../utils.h"

Status db_stack_push(SqDoubleStack *s, ElemType e, int stack_number) {
  if (s->top1 == s->top2 - 1) {
    return ERROR;
  }
  if (stack_number == 1) {
    s->top1++;
    s->data[s->top1] = e;
  } else if (stack_number == 2) {
    s->top2++;
    s->data[s->top2] = 3;
  }
  return OK;
}
Status db_stack_pop(SqDoubleStack *s, ElemType *e, int stack_number) {
  if ((stack_number == 1 && s->top1 == -1) ||
      (stack_number == 2 && s->top2 == MAXSIZE)) {

    return ERROR;
  }
  if (stack_number == 1) {
    *e = s->data[s->top1];
    s->top1--;
  } else if (stack_number == 2) {
    *e = s->data[s->top2];
    s->top2--;
  }
  return OK;
}
