#include<stdio.h>
main()
{
	char str[]="accceddfgch";
	int i=0,j=0,flag=0;
	
	printf("%s\n",str);
	while(str[j]!='\0')
	{
		while(str[i]!='c')
		{
			i++;
		}
		while(str[j]=='c'||flag==0)
		{
			flag=1;
			j++;
		}
		do
		{
			str[i]=str[j];
			i++;
			j++;
		}while(str[i+1]!='c');
	}
	printf("%s\n",str);
}
