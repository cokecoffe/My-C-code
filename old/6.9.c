#include<stdio.h>
main()
{
	int num;
	int i,j,k;
	for(num=100;num<=1000;num++)
	{
		i=num%10;     	//个位
		j=(num%100-i)/10;	//十位
		k=num/100;	//百位

		if(num==i*i*i+j*j*j+k*k*k)
		printf("%d ",num);
	}
}
