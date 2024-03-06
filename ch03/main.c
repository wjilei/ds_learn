#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkList.h"
#include "data.h"
#include "sqlist.h"

#include "StaticLinkList.h"

static void PrintSqList(SqList L) {
  int i;
  ElemType e;
  for (i = 1; i <= SqListLength(L); i++) {
    SqGetElem(L, i, &e);
    printf("%d ", e);
  }

  printf("\n");
}

static void PrintLinkList(LinkList L) {
  int len = LL_ListLength(L);
  int i;
  ElemType e;
  for (i = 1; i <= len; i++) {
    LL_GetElem(L, i, &e);
    printf("%d ", e);
  }
  printf("\n");
}

static void test_sq_list() {

  SqList L1 = {0};
  ElemType e;

  SqListInsert(&L1, 1, 10);
  SqListInsert(&L1, 2, 11);

  PrintSqList(L1);

  SqListDelete(&L1, 1, &e);

  PrintSqList(L1);
}

static void test_sll_list() {
  StaticLinkList L;
  int i;
  ElemType e;
  memset(L, 0, sizeof(Component) * MAXSIZE_SLL);
  InitList_SLL(L);

  ListInsert_SLL(L, 1, 10);
  ListInsert_SLL(L, 2, 11);
  for (i = 1; i <= ListLength_SLL(L); i++) {
    GetElem_SLL(L, i, &e);
    printf("%d ", e);
  }
  printf("\n");
  ListDelete_SLL(L, 1);
  for (i = 1; i <= ListLength_SLL(L); i++) {
    GetElem_SLL(L, i, &e);
    printf("%d ", e);
  }
  printf("\n");
}

void test_link_list() {

  LinkList L2;
  ElemType e;
  Status ret;

  L2 = LL_CreateListHead();

  LL_ListInsert(&L2, 1, 2);
  LL_ListInsert(&L2, 2, 3);
  LL_ListInsert(&L2, 3, 5);
  ret = LL_ListInsert(&L2, 5, 10);
  if (ret != ERROR) {
    printf("error\n");
    exit(1);
  } else {
    printf("insert 5:10 error\n");
  }

  PrintLinkList(L2);

  LL_ListDelete(&L2, 2, &e);
  printf("delete: %d\n", e);

  ret = LL_ListDelete(&L2, 4, &e);
  if (ret != ERROR) {
    printf("error\n");
    exit(1);
  } else {
    printf("delete 4 error\n");
  }

  PrintLinkList(L2);

  LL_ClearList(&L2);

  LL_DestroyList(&L2);
}

int main() {

  test_sq_list();
  test_link_list();
  test_sll_list();

  return 0;
}
