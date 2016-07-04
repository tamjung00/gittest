#include <stdio.h>

int main()
{
	int in;
	int *out;

	//in = 100;
	*&in=100;
	
	printf("%d \r\n",in);
	printf("%d \r\n",*&in);
	
	//*out = 100; 잘못
	out = &in;
	*out = 200;

	printf("%d \r\n",*out);
	printf("%d \r\n",in);

	return 0;
}	
