#include <stdio.h>

int main()
{
	
	int a;
	//int *ap = &a;
	int *ap;
	ap = &a;
	
	printf("%u , %u \r\n",ap,&a);
	a = 100;

	printf("%d %d \r\n",*ap,*((int *)4294953988));

	*((int *)4294953988) = 200; 

	printf("%d \r\n",a);

	
	return 0;

}
