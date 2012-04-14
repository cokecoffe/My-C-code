#ifndef OPER
#define OPER

#define OK 1
#define ER -1 
#define LEFT 1
#define RIGHT 2

#include"main.h"
int	init_elem(pData *);
int insert_tree(pData ,pData);
int delete_tree(pData *,int);
int Find_Point(pData ,int,pData *);
int Print_tree(pData);

#endif
