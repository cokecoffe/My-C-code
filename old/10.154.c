#include<stdio.h>
int output_line(int (*p)[4],int line,int arr)
{
	int i;
	for(i=0;i<arr;i++)
	{
		printf("%d ",*(*p+i));
	}
	printf("\n");
	
	for(i=0;i<line;i++)
	{
		printf("%d\n",**p);
		p++;
	}
}

main()
{
	int data[3][4]={1,2,3,4,
					5,6,7,8,
					9,10,11,12};

	 output_line(data,3,4);
}
