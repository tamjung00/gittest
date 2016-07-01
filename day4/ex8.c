#include <stdio.h>

int main()
{
	int num1 = 2016;
	int num2 = num1;
	int *ptrTemp = &num1;

	printf("%d, %d \r\n",num1,*ptrTemp);
	
	*ptrTemp = 2015;
	printf("%d, %d, %d \r\n",num1,*ptrTemp,num2);
		
}
