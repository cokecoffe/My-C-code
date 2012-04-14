#include<stdio.h>
main()
{
	float r;
	char flag;
  while(1)
	{
	printf("input the circle's R and the Flag(a---S,c---L,b---all)\n");

	printf("R:");
	do
	scanf("%f",&r);
	while(r>0);

	getchar();
	printf("Flag:");
	scanf("%c",&flag);

	switch(flag)
	{
	case 'a':printf("S=%f\n",3.14*r*r);break;
	case 'c':printf("L=%f\n",6.28*r);break;
	case 'b':printf("S=%f,L=%f\n",3.14*r*r,6.28*r);break;
	default:break;	
	}

	}

}
