#include <stdio.h>

#include "sqlist.h"

static void PrintSqList(SqList L) {
  int i;
  ElemType e;
  for (i = 1; i <= ListLength(L); i++) {
    GetElem(L, i, &e);
    printf("%d ", e);
  }

  printf("\n");
}

int main() {
  SqList L = {0};
  ElemType e = 10, e1, e2;
  int i;
  ListInsert(&L, 1, 10);
  ListInsert(&L, 2, 11);

  PrintSqList(L);

  ListDelete(&L, 1, &e2);

  PrintSqList(L);
  return 0;
}
