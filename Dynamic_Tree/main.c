#include<stdio.h>
#include"main.h"

main()
{
	int index;
	int del;
	pData sl;
	pData new;
	
	init_elem(&sl);
	
	while(index !=EXIT)
	{
		printf("1---INSERT 2---DELETE 3---PRINT 4---EXIT\n");
		scanf("%d",&index);
		
		switch(index)
		{
			case INSERT:{	
							if(sl->num==0)
							{	
								printf("input root node\n");
								scanf("%d",&(sl->num)); 
							}
							else{
									init_elem(&new);	
									printf("input a num:");
									scanf("%d",&(new->num));														
									insert_tree(sl,new);
								}
						}break;
			case DELETE:
						{
							printf("input delete num\n");
							scanf("%d",&del);
							delete_tree(&sl,del);
						}break;
			case PRINT:{
							 Print_tree(sl);
							 printf("\n");
						}break;
			case EXIT:;
			default:break;
		}
	}
}
