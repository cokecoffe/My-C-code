#ifndef OPER
#define OPER
#include<stdio.h>
#include"../malloc/create.h"
#include"main.h"

#define EMPTY -1

int	init_elem(pData *elem);
int intput_elem(pData elem);    
int create_tree(pData elem);
int find_index(pData,int);
int delete_elem(pData,int);
int output_tree(pData);
#endif
