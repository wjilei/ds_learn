#include "SqStack.h"
#include "double_stack.h"
#include <stdio.h>
#include <stdlib.h>

static void test_sq_stack() {
  SqStack s;
  SElemType e;
  s.top = -1;

  SqStack_Push(&s, 10);
  SqStack_Push(&s, 11);

  SqStack_Pop(&s, &e);

  printf("%d\n", e);
}

static void test_sq_db_stack() {
  SqDoubleStack s;
  ElemType e;
  Status ret;
  s.top1 = -1;
  s.top2 = MAXSIZE;

  db_stack_push(&s, 10, 1);
  db_stack_push(&s, 10, 2);
  db_stack_push(&s, 11, 1);
  db_stack_push(&s, 10, 2);

  db_stack_pop(&s, &e, 1);
  if (e != 11) {
    printf("error,expect 11, got %d\n", e);
    exit(1);
  }
  db_stack_pop(&s, &e, 1);
  if (e != 10) {
    printf("error,expect 10, got %d\n", e);
    exit(1);
  }
  printf("all tests passed...\n");
  ret = db_stack_pop(&s, &e, 1);
  if (ret != ERROR) {
    printf("error,expect %d, got %d\n", ERROR, ret);
    exit(1);
  }
}

int main() {
  test_sq_stack();
  test_sq_db_stack();
  return 0;
}
