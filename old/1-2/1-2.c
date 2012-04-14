#include<stdio.h>
main()
{
	int i=0;
	int num=0,alp=0,oth=0;
	char str;

	printf("please input a string:\n");

	while('\n'!=(str=getchar()))
		{
		  if(str<='9'&&str>='1')
		     num++;
		  else if(str<='Z'&&str>='A'||str<='z'&&str>='a')
				alp++;
				else
					oth++;
		   i++;
		}

	printf("num=%d,alpha=%d,other=%d\n",num,alp,oth);	
}
