#include "sqlist.h"




/* Status 是函数的类型，其值是函数结果状态代码，如OK等
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：用e返回L中第i个元素的值
*/
Status GetElem(SqList L, int i, ElemType *e) {
  if(L.length == 0 || i < 1 || i > L.length) {
    return ERROR;
  }
  *e = L.data[i-1];
  return OK;
}

/*
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：在L中第i个位置之前插入新的元素e,L的长度加1
*/
Status ListInsert(SqList *L, int i, ElemType e) {
  int k;
  if(L->length == MAXSIZE) {
    return ERROR;
  }
  if (i < 1 || i > L->length+1) {
    return ERROR;
  }
  if (i <= L->length) {
    for (k = L->length-1; k >= i-1; k--) {
      L->data[k+1] = L->data[k];
    }
  }
  
  L->data[i-1] = e;
  L->length ++;
  return OK;
}
