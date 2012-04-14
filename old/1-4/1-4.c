 #include<stdio.h>
main()
{
	int score;
	char t,temp;
while(1){
	printf("input score:\n");
	scanf("%d",&score);             //输入字母,死循环???

	if(score>=0&&score<=100)
		{
		  t=score/10;
  		  switch(t)
		  {
		  case 10:
		  case 9:temp='A';break;
		  case 8:temp='B';break;
		  case 7:temp='C';break;
		  case 6:temp='D';break;
		  default :temp='E';
		  }
		}
        else

		 printf("your score is error\n");

	printf("your score =%c\n",temp);
	}

}

