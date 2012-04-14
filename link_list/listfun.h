#ifndef LIST
#define LIST

#include<stdio.h>
#include<stdlib.h>
#include"node.h"

int NameFind(pStu,pStu);
pStu InsertPosition(pStu,pStu);

pStu DelPosition(pStu,pStu);
pStu num_search(pStu,int);
pStu age_search(pStu,int);
/*insert_fun*/

int insert(pStu pHead,
				pStu,
				int(*pNameFind)(pStu,pStu),
				pStu(*pInsertPosition)(pStu,pStu));
/*delete_fun*/
int del(pStu,pStu,pStu(*pDelPosition)(pStu,pStu));

/*print_fun*/
void print(struct list*);

/*seach_fun*/
pStu search(pStu,int,int,pStu(*fun_search[])(pStu,int));

#endif
