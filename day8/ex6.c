#include <stdio.h>

union _U_TEST {
	unsigned char byte[4];
	unsigned int number;
};

enum season {spring=5,summer,fall,winter};

int main()
{
	union _U_TEST test;
	
	test.number = 0x01020304;

	printf("%u \r\n",test.number);

	enum season ss,ss2;
	
	ss = spring+10;
	//ss = 5;
	ss2 = summer;

	printf("%d %d \r\n",ss,ss2);
	
	return 0;	
}
