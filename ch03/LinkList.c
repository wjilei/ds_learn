
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"


LinkList LL_CreateListHead() {
  LinkList L = (LinkList)malloc(sizeof(Node));
  L->next = NULL;
  return L;
}

void LL_ClearList(LinkList *L) {
  LinkList p,next;
  p = (*L)->next;
  while(p) {
    next = p->next;
    free(p);
    p = next;
  }

  (*L)->next = NULL;
}


void LL_DestroyList(LinkList *L) {
  LL_ClearList(L);
  free(*L);
}

// 初始条件: 线性表L已存在,1<=i<=ListLength(L)
// 操作结果: 用e返回L中第i个数据元素的值
Status LL_GetElem(LinkList L, int i, ElemType *e) {
  int j;
  LinkList p = L->next;
  j = 1;
  while (p && j < i) {
    p = p->next;
    j++;
  }
  if (!p || j > i) {
    return ERROR;
  }
  *e = p->data;
  return OK;
}

// 初始条件：线性表L已存在, 1<=i<=ListLength(L)
// 操作结果: 在L中第i个位置插入新的数据元素e,L的长度加1
Status LL_ListInsert(LinkList *L, int i, ElemType e) {
  int j;
  LinkList p, s;

  j = 1;
  p = *L;

  while (p && j < i) {
    p = p->next;
    j++;
  }

  if (!p || j > i) {
    return ERROR;
  }

  s = (LinkList)malloc(sizeof(Node));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

// 初始条件: 线性表L不为空, 1<=i<=ListLength(L)
// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
Status LL_ListDelete(LinkList *L, int i, ElemType *e) {
  int j;
  LinkList p, q;
  p = *L;
  j = 1;
  while (p && j < i) {
    p = p->next;
    j++;
  }
  if (!p || j > i) {
    return ERROR;
  }
  q = p->next;
  p->next = q->next;
  *e = q->data;

  free(q);

  return OK;
}

int LL_ListLength(LinkList L) {
  int j=0;
  LinkList p;
  p = L->next;
  while (p) {
    j++;
    p = p->next;
  }

  return j;
}
