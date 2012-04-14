#include"node.h"
#include"listfun.h"
#include"../malloc/create.h"

void print_info(pStu stu)
{
	printf("学号：%d ",stu->num);
	printf("年龄：%d\n",stu->age);
}

int input_info(pStu stu)
{
	do
	{
		scanf("%d %d",&(stu->num),&(stu->age));
	}while(stu->num<=0||stu->age<0);
}

int init_List(pList list)
{
	dynamic_create((void**)&(list->head),sizeof(sStu));

	list->insert = insert;
	list->del = del;
	list->print = print;
	list->search = search;
}


main()
{
	int sel=0;
	int num=0;
	int ret;
	sList list;
	pStu temp;
	pStu head = NULL;
	pStu new;
	pStu (*search_fun[2])(pStu,int);

	init_List(&list);//init the list
	
	search_fun[0] =  num_search;
	search_fun[1] = age_search;
	

	while(sel!='#')
	{
		printf("select the function,#-to exit\n");
		printf("1-----Insert a student\n");
		printf("2-----Delete a student\n");
		printf("3-----Search a student(for num)\n");
		printf("4-----Search a student(for age)\n");
		printf("5-----Print the list\n");
		scanf("%d",&sel);
		switch(sel)
		{
			case INSERT:
			{
			//新结点初始化
dynamic_create((void**)&new,sizeof(sStu));
			new->stu_input = input_info;
			new->stu_print = print_info;
			printf("intput num and age\n");
			new->stu_input(new);
			
ret =list.insert(list.head,new,NameFind,InsertPosition);
						if(ret!=OK)
						{
							printf("插入失败\n");
							break;
						}
					}
					break;
			case DELETE:{
							printf("输入删除的方式1--num 2--age\n");
							scanf("%d",&sel);
							switch(sel)
							{
								case 1:{
										printf("输入要删除学生的学号\n");
										scanf("%d",&num);
										temp = list.search(list.head,0,num,search_fun);
										if(temp == NULL)
										{
											printf("没有您要删除的学生信息\n");
											break;
										}
										list.del(list.head,temp,DelPosition);					
										}break;
								case 2:{
											printf("输入要删除的学生的年龄\n");
											scanf("%d",&num);

											head = NULL;
											for(head=list.head;head->next!=NULL;)
											{
												temp = list.search(head,1,num,search_fun);
												if(NULL==temp)
												{
													printf("没有要删除的数据\n");
													break;
												}
												list.del(list.head,temp,DelPosition);					
												head = temp;
											}
											
										}break;
							default:break;
							}

			     		}
					break;
			case SEARCH_1:{
						
							printf("输入要查找的学生的学号\n");
							scanf("%d",&num);
							temp = list.search(list.head,0,num,search_fun);
							if(temp==NULL)
							{
								printf("没有查找到!\n");
								break;
							}
							printf("num=%d,age=%d\n",temp->num,temp->age);
						}
						break;
			case SEARCH_2:{
							printf("输入要查找的学生的年龄\n");
							scanf("%d",&num);
							head = NULL;
							for(head=list.head;head->next!=NULL;)
							{
								temp = list.search(head,1,num,search_fun);
								if(NULL==temp)
								{
									printf("没有查找到!\n");
									break;
								}
								printf("num=%d,age=%d\n",temp->num,temp->age);
								head = temp;
							}
						  }
						break;
			case PRINT:{
							list.print(&list);
						}
					break;
			default:printf("\n");	
		}
	}
}
