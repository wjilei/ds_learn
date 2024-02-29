#ifndef _SLL_H_
#define _SLL_H_


#define MAXSIZE_SLL 1000

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;


typedef struct {
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE_SLL];


Status InitList_SLL(StaticLinkList space);

int Malloc_SLL(StaticLinkList space);
void Free_SLL(StaticLinkList space, int i);
int ListLength_SLL(StaticLinkList L);

Status ListInsert_SLL(StaticLinkList space, int i, ElemType e);

Status ListDelete_SLL(StaticLinkList L, int i);

Status GetElem_SLL(StaticLinkList L, int i, ElemType *e);

#endif