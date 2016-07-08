#include <stdio.h>

//#define pi 3.14
const double pi = 3.14;

int main()

{
	//pi = 3.14;
	double pi = 1.14;

	int a = 10, b = 20;
	const int *ap;
	pi = 3.14;
	pi = 2.14;
	ap = &a;
	ap = &b;
	
	b = 21;
	//*ap = 21;

	//pi = 2.14; 
	//_pi = 2.14;
	
	printf("%f %d \r\n",pi,*ap);
}
