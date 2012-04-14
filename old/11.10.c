#include<stdio.h>
#define WLEN 15
int a[6][6]={0,1,0,0,0,0,
			 0,0,2,0,0,5,
			 0,0,0,3,0,0,
			 0,0,0,0,4,0,
			 0,0,0,0,0,5,
			 0,0,0,0,0,0};
int get_word(char *str,char *word,int *i)//获取一个关键字
{
	int j=0;
	while(*str[*i]!=' ')
	{
		word[j]=str[*i];
		(*i)++;
		j++
	}
	word[i] = '\0';
}
int get_var(char *str,char *var,int *i)
{
	int j=0;
	while(str[*i]!='['||str[*i]!=';')
	{
		var[j] = str[*i];
		(*i)++;
		j++;
	}
	var[j]='\0';
}
int get_num(char *str,char *num,int *i)
{
	int j=0;
	while(str[i]!=']')
	{
		num[j] = str[i];
		(*i)++;
		j++;
	}
	num[j] = '\0';
}

int char2num(char *num)
{
	int i=0,sum=0;
	int flag = 1;
	while(num[i]!='\0')
	{
		i++;
	}
	i--;
	while(i!=-1)
	{
		sum += num[i]*flag;
		flag = flag*10;
		i--;
	}
	return sum;

}
main()
{
	enum Type{char,int,float};
	Type type;
	char word[10],var[10],num[10];
	char *data = "int a;int b[3];float s;char str[10];#";
	int i=0
	int n;
	int size=0;

	while(data[i]!='#')
	{
		get_word(data,word,&i);			//获取类型
		get_var(data+i,var,&i);			//获取变量名
			
		if(data[i]=='[')
		{
			get_num(data+i+1,num,&i);
			n = char2num(num);			//获取数组长度
			if(data[i]==']'||data[i+1]==';')
			{
				 size = ;         //int a[n];样式
			}
		}
		else if(data[i]==';')
			{
				size = ;//int a;样式
			}
			i++;	
	}			
}


