#include<stdio.h>

void max(int a[][3], int line, int row)
{
	int i,j;
//	max1,max2,max3,min_inmax,temp;
	int max,min_temp=100;	
//	max1=a[0][0];
//	max2=a[0][1];
//	max3=a[0][2];

	for(i=0;i<line;i++)
	{
		max=a[i][0];	
		for(j=0;j<row;j++)
			{
				if(a[i][j]>max)
					max=a[i][j];

/*				switch(i)
				{
		    		 case 0:	if(a[i][j]>max1)	
					 			{
									max1=a[i][j];
								}
					 
		    		 case 1:	if(a[i][j]>max2)	
					 			{
									max2=a[i][j];
								}

		    		 case 2:	if(a[i][j]>max3)	
					 			{
									max3=a[i][j];
								}
				}
*/
	 		}
		printf("第%d行的最大数为：%d\n",i,max);	
		if(max<min_temp)
		{
			min_temp=max;
		}
	}

	printf("min=%d\n",min_temp);
//	temp=(max1>max2?max2:max1);
//	min_inmax=(temp>max3?max3:temp);
//	printf("最小数%d\n",min_inmax);
}

main()
{
	int a[3][3]={1,2,3,
				 4,5,6,
				 7,8,9};

    max(a,3,3);
		
	
}
