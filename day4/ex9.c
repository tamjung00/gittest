#include <stdio.h>

int main()
{
	int test1[] ={1,2,3,4,5};
	int *ptrTemp1;
	char *ptrTemp2;

	ptrTemp1 = test1;
	ptrTemp2 = (char *)test1;

	printf("%x %x \r\n",*ptrTemp1,ptrTemp1[1]);
	printf("%x %x \r\n",*ptrTemp2,*(ptrTemp2+4));
}
