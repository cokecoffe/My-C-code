#include<stdio.h>
int fun1(int arr[][3],int index,int index2)
{
	int i,j;
	int max = arr[0][0];
	for(i=0;i<index;i++)
	{
		for(j=0;j<index2;j++)
		{
			if(arr[i][j]>max)
			{
				max=arr[i][j];
			}
		}
	}
	return max;
}
int fun(int arr1[][3],int i,int j,int arr2[][3],int k,int n)
{
	return fun1(arr1,i,j)-fun1(arr2,k,n);
}

main()
{
	int num1[3][3]={1,2,3,
					4,5,6,
					7,8,9};
	int num2[3][3]={1,3,5,
					7,9,10,
					12,14,16
					};
	int temp;

	temp = fun(num1,3,3,num2,3,3);

	printf("两个数组的差值为：%d\n",temp);

}
