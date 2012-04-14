#ifndef HUFFMAN
#define HUFFMAN
#include"main.h"

int Select(pHuff T,int *min,int *sec,int num);//选择两个最小的，父指针为NULL的结点
int CreateHuffTable(pData alp_num,pHuff *huffman,int num);
int HuffmanCode(pHuff T,char **alp_code,int num);//求每个字母的Huffman编码

#endif
