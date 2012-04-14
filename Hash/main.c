#include <stdio.h>
#include"main.h"

int main(int argc, char** argv)
{
	int num;
	int times;		//出现的次数
	char index;
	pHash1 hash;
	pNode new;
	
	Init_Hashtable(&hash);
		
	
	while(index!='e')
	{
		printf("---------------------------\n");
		printf("'i'--insert\n'f'--find\n'e'--exit\n");
		scanf("%c",&index);
		getchar();
		switch(index)
		{
			case 'i':{
						printf("输入数据:\n");
						scanf("%d",&num);
						getchar();
						Init_Node(&new,num);
						Insert_Node(hash,num%NU_1,num>>3&NU_2,new);
					 }
						break;
			case 'f':{
						printf("输入要查找的数据:\n");
						scanf("%d",&num);
						getchar();
						times = Find_Node(hash,num%NU_1,num>>3&NU_2,num);
						printf("出现的次数:%d\n",times);
					}break;
			case 'e':break;
			default:index = 'e';
		}
	}
	
	return 0;
}
