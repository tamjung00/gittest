#include <stdio.h>

int main()
{
	int test = 0x0000001;//0011,0010,0100,1000
	test = test << 1;
	printf("%x \r\n",test);
	
	test = test << 1;
	printf("%x \r\n",test);
	
	test = test << 1;
	printf("%x \r\n",test);



	return 0;
}
