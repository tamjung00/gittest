#include <stdio.h>

int main()
{
	int a,b,c,d,e;

	a = 1;
	b = 2;
	c = 3;
	d = 4;
	e = 5;
	
	int *ptr;

	ptr = &a;

	printf("%u %u \r\n",ptr,&a);
	printf("%u %u \r\n",ptr - 1,&b);
    printf("%u %u \r\n",ptr - 2,&c);
	printf("%u %u \r\n",ptr - 3,&d);
 	printf("%u %u \r\n",ptr - 4,&e);

	printf("a = %d \r\n",*ptr,a);
	printf("b = %d \r\n",*(ptr-1));
	printf("c = %d \r\n",*(ptr-2)); 

	for(int i=0;i<5;i++) {
		printf("%d , ", *(ptr-i));
	}
	
	return 0;
}
