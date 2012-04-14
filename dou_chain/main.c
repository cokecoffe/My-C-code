#include"main.h"
#include"../malloc/create.h"
#include"get_addr.h"

/*显示链表中的内容*/
int display_free(pMem head)
{
	pMem temp = head;
	while(temp->next!=head)
	{
		printf("id= %d,size = %d\n",temp->next->id,temp->next->memory_size);
		temp = temp->next;
	}
}

/*获取内存函数*/
int get_memory(pMem m_head,pMem g_head,pGet a_head,int size)
{
	pMem m_temp = m_head;		//空闲链表
	pMem g_temp = g_head;		//申请链表
	pGet a_temp = a_head;		//记录链表
	pMem max = NULL;		//记录最大差值的位置
	pMem del=NULL;
	pMem will_del;		// 存放将要删除的结点
	pMem move_list=NULL;
	pMem change;		//临时链表向申请链表 缓冲变量
	pMem temp_list=NULL;
	int index=0;		//记录每次申请的结点个数
	
	init_memory(&temp_list);//初始化临时链表

	
	while(size>0)
	{	m_temp = m_head->next;
    	max = m_head->next;

    	
		while(m_temp!=m_head)
		{
			if(m_temp->memory_size==size)
			{		
				del_memory(m_temp);//匹配则删除原来内存结点
			
				insert_temp_memory(temp_list,m_temp);				
				size = 0;
				break;
			}
		
			if(m_temp->memory_size > max->memory_size)
			{
				max = m_temp;	//max指向需要申请的最大结点	
			}
			m_temp = m_temp->next;
	
		}
		if(size == 0)
		{
			break;
		}

			printf("max=%d\n",max->id);
		updata_memory(m_head,max,temp_list,&size);		
	}

	move_list = temp_list->next;
	while(move_list!=temp_list)
	{
		index++;
		move_list = move_list->next;
	}
	insert_get_addr(a_head,temp_list,index);//更新记录链表

	
	move_list = temp_list->next;	
	
	while(move_list != temp_list)				// 遍历临时链表
	{			
		move_list->pre->next = move_list->next;       //从临时链表中拿下来
		move_list->next->pre = move_list->pre;

		will_del = move_list;
		
		move_list = move_list->next;
		
		insert_memory(g_head,will_del);						
	}

	
	
	move_list = temp_list->next;
	while(move_list!=temp_list)			//释放临时链表
	{
		will_del = move_list;
		move_list = move_list->next;
		free(will_del);
	}

	printf("申请内存成功\n");
}
/*释放内存函数*/
free_memory(pMem pown,pMem papply,pGet p_record)
{
	pMem *free_temp;
	int i;

		free_temp = get_record(p_record);//获取指针数组
		
		for(i=0;free_temp[i]!=NULL;i++)
		{
			insert_own_memory(pown,free_temp[i]);//恢复到空闲链表
		    del_applay_list(papply,free_temp[i]);	//删除申请链表中对应的结点
		}	
}


main()
{
	int index = 0;
	int size = 0;
	pMem pOwnHead;//原始内存链表
	pMem pGetHead;//分配内存链表
	pGet pGetaddr = NULL;//记录链表

	pGet temp_addr ;
	
	init_memory(&pOwnHead);//初始化头结点

	create_memory(pOwnHead,10);//创建10个结构体

	init_memory(&pGetHead);//初始化分配内存链表

	init_get_addr(&pGetaddr);// 初始化记录链接表

	temp_addr = pGetaddr;
	while(index!=5)
	{
		printf("输入要进行的操作：\n");
		printf(" 1--------Create\n");
		printf(" 2--------Delete\n");
		printf(" 3--------Display the free space\n");
		printf(" '5'--------Exit\n");

		scanf("%d",&index);
		switch(index)
		{
			case CREATE:
					{
						printf("输入要开辟的空间:\n");
						scanf("%d",&size);							
						get_memory(pOwnHead,pGetHead,pGetaddr,size);
						
					}break;
			case DELETE:	{	
								if(temp_addr->next!=pGetaddr)
								{
									free_memory(pOwnHead,pGetHead,temp_addr->next);
									temp_addr = temp_addr->next;
								}
							}break;
			case DISPLAY1:
						{
							printf("空闲的空间为：\n");
							display_free(pOwnHead);
							printf("已经分配的空间为：\n");
							display_free(pGetHead);
													
						}break;
			case '5':break;
			default:break;
		}



	}







}


