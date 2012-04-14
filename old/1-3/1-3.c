#include<stdio.h>
main()
{
	char a;
	printf("input a alpha:\n");
	scanf("%c",&a);

	if(a>'A'&&a<'Z')
		a+=32;
	printf("the alpha is %c\n",a);
}
