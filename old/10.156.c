#include<stdio.h>
#include"./str/str.h"
#include"./malloc/create.h"

main()
{
	
	char *data1;
	char *data2;
	int len;
	int ret;
	
	printf("input length:\n");
	scanf("%d",&len);

	data1 = create_arr(len);
	
	data2 = create_arr(len+len/3);

	str_cpy(data1,"abcd");

	printf("String1 = %s\n",data1);

	ret = in_string(data1,data2);
	if(ERR == ret)
	{
		printf("拷贝失败！\n");
		return ERR;
	}
	printf("String2 = %s\n",data2);
	
	free(data1);
	free(data2);
}
