#include<stdio.h>
#include<string.h>
#define NUM 10

void Sort(char *arr)
{
	int i,j,length;
	char temp;

	length=strlen(arr);
	for(i=0;i<length-1;i++)
	{
		for(j=0;j<length-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

main()
{
	char data1[NUM]="";
	char data2[NUM]="";
	char data3[NUM*2]="";
	int i=0,j=0,k=0,length=0,len1=0,len2=0;

	printf("请输入第1个字符串：");	
	gets(data1);
	printf("\n");

	printf("请输入第2个字符串：");	
	gets(data2);
	printf("\n");

	Sort(data1);
	puts(data1);
	Sort(data2);
	puts(data2);

	len1=strlen(data1);
	len2=strlen(data2);

	length=len1+len2;
	
	while(k<=length&&i<len1&&j<len2)
	{
		if(data1[i]<data2[j])	
		{
			data3[k++]=data1[i++];
		}
		else	if(data1[i]=data2[j])
	 			{
					data3[k++]=data1[i++];
					j++;
				}
				else
				{
					data3[k++]=data2[j++];
				}

	}

	if(i==len1)
	{
		while(j<=len2)
			data3[k++]=data2[j++];
	}
	if(j==len2)
	{
		while(i<=len1)
			data3[k++]=data1[i++];
	}
	
	
	data3[k]='\0';

	printf("排序合并后的字符串为：");
	puts(data3);
	printf("\n");
}




















