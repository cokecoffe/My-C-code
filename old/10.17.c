#include<stdio.h>
#include"./malloc/create.h"

int Sort(char **str,int num,char **mirr)
{
	int i=0;
	int j=0;
	char *temp,*temp_2;
	
		for(i=0;i<num-1;i++)
		{
			printf("!!\n");
			for(j=0;j<num-1-i;j++)
			{
				if (**(mirr+j)>**(mirr+1+j))
				{
					temp = *(mirr+j);		
					*(mirr+j) =*(mirr+j+1);
					*(mirr+j+1) = temp;
					
					temp_2 = *(str+j);	
					*(str+j) = *(str+j+1);
					*(str+j+1) = temp_2;
				}
			}
		}
}

main()
{
	int num=0;
	int len=0;
	int i,j,k;
	int ret;
	char **str;
	char **mirr;

	printf("请输入字符串个数\n");
	scanf("%d",&num);
	if(num<=0)
	{
		printf("输入有错误！\n");
		return ER;
	}

/*为指针数组开辟空间*/
	 dynamic_create((void**)&str,num*sizeof(char *));
	 dynamic_create((void**)&mirr,num*sizeof(char *));//存放镜像地址

/*为每个字符串开辟空间，并且输入数据*/
	for(i=0;i<num;i++)
	{
		printf("输入字符串%d长度\n",i+1);
		scanf("%d",&len);
		getchar();//吸收回车符号！！

		dynamic_create((void**)(str+i),(len+1)*sizeof(char));
		dynamic_create((void**)(mirr+i),((len+1)/2)*sizeof(char));

		input_str(*(str+i),len);//输入数据
		k=len-1;

		for(j=0;j<(len+1)/2;j++,k--)//为镜像字符串初始化
		{
			*(*(mirr+i)+j)=*(*(str+i)+k);
			printf("mi=%c\n",*(*(mirr+i)+j));
		}
	}

/*排序字符串*/
	Sort(str,num,mirr);

	printf("排序后的字符串顺序为：\n");
	for(i=0;i<num;i++)
	{
		printf("str[%d]=%s\n",i,*(str+i));
	}
}







