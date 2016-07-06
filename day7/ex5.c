#include <stdio.h>

int sum(int a,int b)
{

	return a+b;
}

int main()
{

	//int r = sum(1,2);

	int(*fp)(int,int) = sum;

	int r =fp(1,2);

	printf("%d \r\n",r);

	return 0;
}
