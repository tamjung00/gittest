#include <stdio.h>

int main()
{
	int a;
	a = 7;
	{
		int a;
		a = 3;
		printf("%d \r\n",a);
	}
	printf("%d \r\n",a);

}
