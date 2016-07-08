#include <stdio.h>

int main()
{
	char m = 0xaf; //10101111
	char m1 = m & 0x0f;//00001111
	char m2 = m | 0x10;//00010000 ->1011 1111
	char m3 = m ^0x5f;//0101 1111
	char m4 = ~m;

	printf("%x %x %x %x \r\n",m1,m2,m3.m4);

	return 0;
}
