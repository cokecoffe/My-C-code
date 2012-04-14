#include<stdio.h>
#define NUM 100 
main()
{
	int num,count;
	int stu[NUM]={0};
	int i=0;
	int j=1;
	int index;
	int num_temp;

	printf("输入学生个数：");
	scanf("%d",&num);
	num_temp=num;

	printf("输入要数的数：");
	scanf("%d",&count);
	
		for(i=0;num>1;i=(i+1)%num_temp,j++)
		{	
			if(stu[i]!=-1)
			{
				stu[i]=j;
			}
			else
				{
					j--;
				}
			
			if(j==count) //当数到最后一个数时,数组赋值-1,剩余人数-1,j复位0
			{
				stu[i]=-1;
				num--;
				j=0;
			}
			printf("stu[%d]=%d ",i,stu[i]);
	
		}
		
		printf("\n");
		for(index=0;index<num_temp;index++)
		{
			if(stu[index]!=-1)
				{
						printf("%d\n",index+1);
				}
		}
		
		
}

