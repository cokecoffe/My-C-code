#include<stdio.h>
main()
{
	int num[]={1,2,3,4,5,6,7,8,9,10};
	int i,j,k,index,temp;
	for(index = 0;index<10;index++)
	{
		printf("%d  ",num[index]);
	}
	printf("\n");
	do
	{
		printf("请输入从第几个数开始逆序：");
		scanf("%d",&i);
	}while(i>0&&i<10);	
	i--;
	printf("\n");

	do
	{
		printf("请输入逆序多少个数：");
        scanf("%d",&j);
    }while(i+j<=10)
	j--;
        printf("\n");

	k=i+j;
	while(i<k)
	{
		temp=num[i];
		num[i]=num[k];
		num[k]=temp;
		i++;
		k--;
	}

	for(index = 0;index<10;index++)
        {
                printf("%d  ",num[index]);
        }
	printf("\n");

}
