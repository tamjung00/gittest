#include <stdio.h>

int main()
{
	//1111 1111
	//0111 1111 = 127, 0x7f
	//1000 0000 = 128, 0x80
	//1111 1111 = 255, 0xff
	char a = 0x7f;
	unsigned char b = 0xff;
	printf("%d , %d \r\n",a,0x7f);
	a = 0x80;
	printf("%d , %d \r\n",a,0x80);

	a = 0xff;
	printf("%d , %d \r\n",a,0xff);

	printf("%d  \r\n",b);

	return 0;
}
