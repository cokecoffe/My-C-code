#include<stdio.h>
main()
{
	char num1,num2;

	printf("please input 2 nums:\n");
	
	scanf("%c",&num1);
	getchar();
	do
	{
		scanf("%c",&num2);
		getchar();
	}
	while(num1==num2);

	printf("%d\n",(num2-48)*10+num1-48);
	printf("%d\n",(num1-48)*10+num2-48);

}
