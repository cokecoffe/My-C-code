#include<stdio.h>
#include"main.h"

main()
{
	pData elem;
	int num=0;
	int index = 0;
	
	init_elem(&elem);		//初始化每一个结点
	intput_elem(elem);      //input data
	
	create_tree(elem);      //建立二叉排序树	

	output_tree(elem);		//print data
	
	printf("input what you want to del");
	scanf("%d",&num);
	index = find_index(elem,num);

	delete_elem(elem,index);   //删除某一个叶子
	output_tree(elem);		   //print data
}
