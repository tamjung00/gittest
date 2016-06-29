#include <stdio.h>

int main()
{
	int a = 0x7fffffff;
	int b = 0x80000000;
	int c = 255;
	char d = c;
	unsigned char e = c;
	
	printf("%d ~ %d \r\n",a,b);
	printf("%d , %d \r\n",(unsigned char)d,e);

	return 0;
}
