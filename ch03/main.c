#include <stdio.h>

#include "sqlist.h"

int main() {
  SqList L = {0};
  ElemType e = 10, e1;
  ListInsert(&L, 1, 10 );
  GetElem(L, 1, &e1);
  printf("%d\n", e1);
  return 0;
}
