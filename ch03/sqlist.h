
#ifndef _SQ_LIST_H_
#define _SQ_LIST_H_

#define OK 1
#define ERROR 0

#define TRUE 1
#define FALSE 0

#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct SqList SqList;

struct SqList{
  ElemType data[MAXSIZE];
  int length;
};
/* Status 是函数的类型，其值是函数结果状态代码，如OK等
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：用e返回L中第i个元素的值
*/
Status GetElem(SqList L, int i, ElemType *e);

Status ListInsert(SqList *L, int i, ElemType e);

#endif