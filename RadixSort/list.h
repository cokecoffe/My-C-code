#ifndef LIST
#define LIST

#include"main.h"
#define EMPTY 0
#define NO_EMPTY 1

int init_list(pData sl);
int empty_list(pData p);
int delete_list(pData head);
pData find_end(pData head);
#endif
