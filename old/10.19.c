#include<stdio.h>
#include"./malloc/create.h"
#include"./input/input.h"

/*为每一个字符串分配空间*/	
int str_trans(char *data,char **str)
{
		int num=0;
		int i=0,j=0,k=0;
		int ret;

		while(*(data+i)!='\0')
		{
			if(*(data+i)>='0'&&*(data+i)<='9')
			{	
				num++;
			}
			else if(num!=0)
				 {
					ret = dynamic_create((void **)(str+j),num*sizeof(char));
					j++;
					if(ER==ret)
					{
						return ER;
					}
					i--;
					for(k=0;k<num;k++)					//逆序赋值
					{
						*(*(str+j-1)+k) = *(data+i);
						i--;
					}
					i=i+num;							//恢复i
					num = 0;
				 }
				else
					{
						num=0;
					}
			i++;
		}
		return OK;
}

main()
{
	char *data;
	int len;
	int ret;
	int i=0;
	int flag=0;
	int digit=0;
	char **str;	

	do
	{
		printf("input length of string\n");
		scanf("%d",&len);
	}while(len<=0);
	getchar();

/*分配字符串空间*/
	ret = dynamic_create(&data,(len+1)*sizeof(char));
	if(ret!=OK)
	{
		printf("分配空间失败\n");
		return ER;
	}

/*输入字符串*/
	ret = input_str(data,len);
	if(ER==ret)
	{
		printf("赋值失败\n");
		return ER;
	}
	printf("string=%s\n",data);

/*计算数字串的个数*/	
	ret = num_count(data,&digit);
	if(ER==ret)
	{
		return ER;
	}
	printf("digit=%d\n",digit);
	
/*开辟一个指针数组*/
	ret = dynamic_create((void**)&str,digit*sizeof(char*));
	if(ER==ret)
	{
		return ER;
	}
printf("digit=%d\n",digit);
	printf("开辟指针数组成功\n");


	 str_trans(data,str);//将字符串中的数字串转置存储
	
	for(i=0;i<digit;i++)
	{
		printf("str%d=%s\n",i,*(str+i));
	}

}

