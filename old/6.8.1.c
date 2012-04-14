#include<stdio.h>

main()
{
	int i,j,k;

	for(i=0;i<=100;i++)
		for(j=0;j<=50;j++)
			for(k=0;k<=20;k++)
				if((i+j*2+k*5)==100)
					printf("%d个1分,%d个2分，%d个5分\n",i,j,k);
			
}
