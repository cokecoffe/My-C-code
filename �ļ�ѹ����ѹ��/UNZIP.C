#include<stdio.h>
#include"main.h"

main(int argc, char** argv)
{
	FILE *r_id;
	FILE *w_id;
	pHuff T;
	char *s_file = argv[1];		//要压缩的文件名称
	char *d_file = argv[2];		//要保存为的文件名称
	
	if(s_file==NULL||d_file==NULL)
	{
		printf("commnd no completed\n");
		printf("input like:main ./filename ./new.rar\n");
		return ER;
	}
	r_id = fopen(s_file, "r+");
	w_id = fopen(d_file,"w+");
	if(NULL==r_id||NULL==w_id)
	{
		printf("not this file\n");
		return;
	}
	Get_Huffman(&T,r_id);		//取出Huffman表格
	
	
}
