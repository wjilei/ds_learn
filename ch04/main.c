#include "SqStack.h"
#include <stdio.h>

static void test_sq_stack() {
  SqStack s;
  SElemType e;
  s.top = -1;

  SqStack_Push(&s, 10);
  SqStack_Push(&s, 11);

  SqStack_Pop(&s, &e);

  printf("%d\n", e);
}
int main() {
  test_sq_stack();
  return 0;
}
