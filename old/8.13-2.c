#include <stdio.h>

int main(int argc, char** argv)
{
	int i;	
	int min=3,min_2rd;
	int data[5]={-1,1,1,3,2};
	
	//min_2rd = (data[0]>data[1]?data[1]:data[0]);
	for()
	{
		if(data[i] > data[i+1])
		{
			min = data[1];
			min_2rd = data[0];
		}
		else
		{
			min = data[0];
			min_2rd = data[1];
		}
	}

	for(i=0;i<5;i++)
	{
		if(data[i]<min)
		{
			min_2rd = min;//3
			min = data[i];//1
		}
		else if(data[i]!=min&&data[i]<min_2rd)
			{
				min_2rd = data[i];
			}
			
	}
	
	printf("%d   %d",min,min_2rd);
	return 0;
}
