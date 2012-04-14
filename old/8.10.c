#include<stdio.h>
float fun(double h)
{
	int temp;

	h=h+0.005;
	temp=(int)(h*100);

	return temp*0.01;

}
main()
{
	double num;
	float temp;
	printf("Input:\n");
	scanf("%lf",&num);

	temp =	fun(num);
	printf("%.2f\n",temp);
}
