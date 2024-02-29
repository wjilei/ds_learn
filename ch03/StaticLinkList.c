
#include "StaticLinkList.h"

Status InitList_SLL(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE_SLL; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE_SLL - 1].cur = 0;
    return OK;
}

int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (space[0].cur)
    {
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free_SLL(StaticLinkList space, int i)
{
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

int ListLength_SLL(StaticLinkList L)
{
    int i = MAXSIZE_SLL-1;
    int len = 0;
    while(L[i].cur) {
        len ++;
        i = L[i].cur;
    }
    return len;
}

Status ListInsert_SLL(StaticLinkList space, int i, ElemType e)
{
    int j, k, l;
    l = MAXSIZE_SLL - 1;
    if (i < 1 || i > ListLength_SLL(space) + 1)
    {
        return ERROR;
    }

    j = Malloc_SLL(space);
    if (j)
    {
        space[j].data = e;
        for (k = 1; k <= i - 1; k++)
        {
            l = space[l].cur;
        }
        space[j].cur = space[l].cur;
        space[l].cur = j;
        return OK;
    }
    return ERROR;
}

Status ListDelete_SLL(StaticLinkList L, int i)
{
    int j;
    int k = MAXSIZE_SLL-1;
    if (i < 1 || i > ListLength_SLL(L))
    {
        return ERROR;
    }

    for(j = 1;j <= i-1; j ++) {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SLL(L, j);

    return OK;
}

Status GetElem_SLL(StaticLinkList L, int i, ElemType *e) {
    int j,k;
    k = MAXSIZE_SLL-1;
    if(i < 1 || i > ListLength_SLL(L)){
        return ERROR;
    }

    for (j = 1;j<=i;j ++){
        k = L[k].cur;
    }

    *e = L[k].data;
    return OK;
}