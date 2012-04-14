#include<stdio.h>
main()
{
	int num,arr[8],i=0,j=0;
	int temp;
	printf("input:\n");
	scanf("%d",&num);

	temp=num;
	do
	{
		arr[i++]=temp%2;
		temp=temp/2;
	}while(temp!=0);

	while(j<=i-1)
        printf("%d",arr[j++]);

	printf("\n");
}
