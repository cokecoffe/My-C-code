#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
	int f_id;
	char buf;
	int word_flag=0;
	int line=0,word=0,character=0;
	
	f_id=open("/home/wangke/abc.txt",O_RDWR);
	
	if(f_id==-1)
	{
			printf("打开文件错误\n");
	}
	else
		{
			do
			{
				read(f_id,&buf,1);//getchar()
				//遇到.行数加1
				if(buf=='.')					
				{
						line++;
				}
				if(buf!='\n'&&buf!='#')
					{
						if(buf!=' '&&buf!='.')
							{
								word_flag=0;	//如果读入的字符不是空格和.单词标记位0
								character++;
							}
						else	
								if(word_flag==0)//读入的是字母，且单词标记为0,那么修改标记为1
								{
									word_flag=1;
									word++;
								}
					}
			}
			while(buf!='#');
		}
	
	close(f_id);

	printf("line=%d\n",line);
	printf("character=%d\n",character);
	printf("word=%d\n",word);
}
