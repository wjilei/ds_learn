#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include "../utils.h"

/*线性表的单链表存储结构*/
typedef struct Node {
  ElemType data;
  struct Node *next;
} Node;

typedef struct Node *LinkList;


LinkList LL_CreateListHead();
void LL_ClearList(LinkList *L);
void LL_DestroyList(LinkList *L);

// 初始条件: 线性表L已存在,1<=i<=ListLength(L)
// 操作结果: 用e返回L中第i个数据元素的值
Status LL_GetElem(LinkList L, int i, ElemType *e);
// 初始条件：线性表L已存在, 1<=i<=ListLength(L)
// 操作结果: 在L中第i个位置插入新的数据元素e,L的长度加1
Status LL_ListInsert(LinkList *L, int i, ElemType e);
// 初始条件: 线性表L不为空, 1<=i<=ListLength(L)
// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
Status LL_ListDelete(LinkList *L, int i, ElemType *e);


int LL_ListLength(LinkList L);

#endif
