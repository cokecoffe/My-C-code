#include<stdio.h>
#include<stdlib.h>
#include"main.h"

int main(int argc, char** argv)
{
	FILE *id;
	FILE *w_id;
	int num;//字母种类
	char ch;
	char *s_file = argv[1];		//要压缩的文件名称
	char *d_file = argv[2];		//要保存为的文件名称
	pData alp_num;				//存放统计出来的每个字符以及个数
	pHuff huffman;
	char **alp_code;		//保存huffman编码
	
	if(s_file==NULL||d_file==NULL)
	{
		printf("commnd no completed\n");
		printf("input like:main ./filename ./new.rar\n");
		return ER;
	}
	
	id = fopen(s_file, "r+");
	w_id = fopen(d_file,"w+");

	num = CountChar(id,&alp_num);    //统计文件中的字母的个数，保存到alp_num


	CreateHuffTable(alp_num,&huffman,num);//建立Huffman树

	alp_code = (char**)malloc(num*sizeof(char*));//开辟指针数组
	
	if(alp_code==NULL)
	{
		printf("create alp_code err\n");
		return ER;
	}

	HuffmanCode(huffman,alp_code,num); //求每个字母的Huffman编码
		
	PushHuffman(w_id,huffman,2*num-1);   //将huffman表写到文件里 

	id = fopen(s_file, "r+");
	PushHuffCode(id,w_id,alp_num,alp_code);//将huffmancode写入文件里

	fclose(id);
	fclose(w_id);
	return 0;
}
