#ifndef OTHER
#define OTHER

int Find_code(pData alp_num,char ch);
int CountChar(FILE *id,pData *p);
int PushHuffman(FILE *id,pHuff T,int num_of_huff);
int PushHuffCode(FILE *id,pData alp_num,char **alp_code);
int Get_Huffman(pHuff T,FILE *r_id);

#endif
