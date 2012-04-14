#include<stdio.h>
main()
{
	int data=0;
	int sum=0;	
	int i=0;
	int temp=0;
	
	for(i=100;i<=1000;i++)	
	{
		temp=i;
	
		while(temp>0)
		{
			data=temp%10; 	    //取数的最低位
			sum+=data*data*data;//对取出的数求立方，并累加
			temp=temp/10;   	//将数截断最后一位
		}
		
		if(sum==i)
			printf("%d\n",i);	
			
		sum = 0; 
	}
}
