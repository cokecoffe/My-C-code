#include"str.h"

int str_cmp(const char *str1,const char *str2)
{
	if(str1==NULL||str2==NULL)
	{
		return ER;
	}
	for(;*str1==*str2;str1++,str2++)
	{
		if(!*str1)
		{
			return 0;
		}
	}
	return *str1-*str2;
}


char* str_cpy(char *str1,char *str2)
{
	if(NULL==str1||NULL==str2)
		{
			return NULL;
		}
	while(*str2!='\0')
	{
		*str1 = *str2;
		str2++;
		str1++;
	}

	*str1 = '\0';
	return str1;
}

int str_len(char *str)
{
	int str_len = 0;
	if(NULL==str)
	{
		return ER;
	}
	while(*str++!=0)
	{
		str_len++;
	}
	return str_len;
}

char *str_cat(char *str1,const char *str2)
{
	while(*str1!=0)
	{
		str1++;
	}
	while(*str2!=0)
	{
		*str1++ = *str2++;
	}
	*str1 = '\0';
	return str1;
}

char *transfort(char *p)
{
	char temp;
	char *tail,*front;
	int i=0,len=0;
	
	if(NULL==p)
	{
		return NULL;
	}


	front = p;
	tail = p;
	
	while(*tail!=0)
	{
		tail++;
		len++;
	}
	tail--;

	while(i<len/2)
	{
		temp = *p;
		*p = *tail;
		*tail = temp;
		tail--;
		p++;
		i++;
	}
	return front;
}

int choose_max(const char *p1,const char *p2,char *p3)
{
	if(NULL==p1||NULL==p2||NULL==p3)
	{
		return ER;
	}
	while(*p1!='\0'&&*p2!='\0')
	{
		if(*p1>=*p2)
		{
			*p3 = *p1;
		}
		else if(*p1<*p2)
			{
				*p3 = *p2;
			}

			p1++;
			p2++;
			p3++;
			
	}
	return OK;
}

int in_string(char *str1,char *str2)
{
	if(NULL==str1||NULL==str2)
	{
		return ER;
	}
	int i=0;
	while(*(str1+i)!='\0')
	{
		if(i%3==0&&i!=0)
		{
			*str2 = ' ';
			str2++;
		}
		*str2 = *(str1+i);
		i++;	
		str2++;
	}
	*str2 = '\0';
	return OK;
}
int num_count(char *data,int *count)		//计算字符串中的数字串的个数
{
	int i=0,digit=0,flag=0;
	
	while(*(data+i)!='\0')
	{
		if(flag==0&&*(data+i)>='0'&&*(data+i)<='9')
		{	
			flag=1;
			digit++;
		}
		else if(*(data+i)>='0'&&*(data+i)<='9')
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
		i++;
	}
	*count = digit;
}

int Sort(char ***str,int num,char **mirr)
{
	int i=0;
	int j=0;
	char **temp;

		for(i=0;i<num-1;i++)
		{
			for(j=0;j<num-1-i;j++)
			{
				if (**(mirr+i)>**(mirr+i+1))
				{
					temp = mirr+i;		
					mirr+i = mirr+i+1;
					mirr+i+1 = temp;
					
					temp = *str+i;	
					*str+i = *str+i+1;
					*str+i+1 = temp;
				}
			}
		}
}













