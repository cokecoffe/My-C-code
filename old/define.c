#include<stdio.h>
#define ARR(A,B) sizeof(A)/sizeof(B)

#define M(x) ((x>64&&x<90)?(x+32):-1)

main()
{
	char alp = 'a';
	int a[5];

	if(M(alp)!=-1)
	
	printf("%c\n",M(alp));

	printf("%d\n",ARR(a,int));
}
