#include<stdio.h>
#include"main.h"
#include"../stack/stack.h"
int Partition(int *arr,int low,int high)
{	
	int x;
	x= arr[low];             /* 选择基准记录*/ 
	while (low<high)
	{
		while (low< high && arr[high]>=x ) //high从右到左找小于x.key的记录
		{
			high--;
		}
		arr[low]= arr[high];	

		while (low<high && arr[low]<x )    //low从左到右找大于x.key的记录
		{
			low++; 
		} 
		arr[high]= arr[low]; 
	}
	arr[low]=x;                    //将基准记录保存到low=high的位置
	return low;                     //返回基准记录的位置
}
main()
{
	int i;
	int temp;
	int arr[8] = {49,38,65,97,76,13,27,49};
	int pivotloc;
	
	SqStack sta;//初始化栈
	InitStack(&sta);
	Data data={0,7};
	Data get;
	Push(&sta,(Elem)data);//0,7进栈
	
	
	while(EMPTY!=EmptyStack(&sta))
	{
		GetTop(&sta,(pElem)(&get));
		Pop(&sta);
		pivotloc = Partition(arr,get.low,get.high);
		
		temp = get.high;
		get.high = pivotloc-1;
		if(get.low<get.high)
		{
			Push(&sta,(Elem)get);
		}
		
		get.low = pivotloc+1;
		get.high = temp;
		if(get.low<get.high)
		{
			Push(&sta,(Elem)get);
		}
	}
	for(i=0;i<8;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	
}
