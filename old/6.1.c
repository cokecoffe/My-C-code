#include<stdio.h>
main()
{
	int num=1000;
	int index=5;
	do
		{
		if(num%3==2&&num%5==3&&num%7==2)
			{
			printf("%d ",num);
			index++;
			}
		num--;

		if(index%5==0)
			printf("\n");
		}
        while(num>0); 
	printf("\n");
}
