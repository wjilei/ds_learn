#ifndef _SQLIST_H_
#define _SQLIST_H_


#define OK 0
#define ERROR 1

#define TRUE 1
#define FALSE 0

#define MAXSIZE 20


typedef int Status;

typedef int ElemType;


typedef struct s_SqList SqList;

struct s_SqList {
  ElemType data[MAXSIZE];
  int length;
};








#endif
