#ifndef MEM
#define MEM
#include"main.h"
#define EACHMEMORY 10
int init_memory(pMem *head);
int create_memory(pMem head,int n);
int insert_own_memory(pMem,pMem);
int insert_memory(pMem,pMem);
int del_memory(pMem);
int insert_temp_memory(pMem,pMem);
int del_applay_list(pMem,pMem);

#endif
