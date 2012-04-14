#include "str.h"

char *change(char *p)
{
	if(NULL==p)
	{
		return NULL;
	}

	char temp;
	char *tail,*front;

	front = p;
	tail = p;
	while(*tail!=0)
	{
		tail++;
	}
	tail--;

	while(tail!=p)
	{
		temp = *p;
		*p = *tail;
		*tail = temp;
		tail--;
		p++;
	}
	return front;
}
