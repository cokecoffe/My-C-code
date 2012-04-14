#include<stdio.h>
main()
{
	int fibi[40]={1,1};
	int i;

	for(i=2;i<40;i++)
	{
		fibi[i]=fibi[i-1]+fibi[i-2];
	}

	for(i=0;i<40;i++)
		{
		printf("%d ",fibi[i]);
		if(i%5==0)
			printf("\n");
		}
}
