#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkList.h"
#include "data.h"

// #include "sqlist.h"

// static void PrintSqList(SqList L) {
//   int i;
//   ElemType e;
//   for (i = 1; i <= ListLength(L); i++) {
//     GetElem(L, i, &e);
//     printf("%d ", e);
//   }

//   printf("\n");
// }

static void PrintLinkList(LinkList L)
{
  int len = ListLength(L);
  int i;
  ElemType e;
  printf("%d\n", len);
  for (i = 1; i <= len; i++)
  {
    GetElem(L, i, &e);
    printf("%d ", e);
  }
  printf("\n");
}

int main()
{
  // SqList L = {0};
  // ElemType e = 10, e1, e2;
  // int i;
  // ListInsert(&L, 1, 10);
  // ListInsert(&L, 2, 11);

  // PrintSqList(L);

  // ListDelete(&L, 1, &e2);

  // PrintSqList(L);

  LinkList L;
  ElemType e;
  Status ret;
  L = CreateList();

  ListInsert(&L, 1, 2);
  ListInsert(&L, 2, 3);
  ListInsert(&L, 3, 5);
  ret = ListInsert(&L, 5, 10);
  if (ret != ERROR)
  {
    printf("error\n");
    return 2;
  }
  else
  {
    printf("insert 5:10 error\n");
  }

  PrintLinkList(L);

  ListDelete(&L, 2, &e);
  printf("delete: %d\n", e);

  ret = ListDelete(&L, 4, &e);
  if (ret != ERROR)
  {
    printf("error\n");
    return 2;
  }
  else
  {
    printf("delete 4 error\n");
  }

  PrintLinkList(L);

  ClearList(&L);

  return 0;
}
