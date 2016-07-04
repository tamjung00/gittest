#include <stdio.h>

void exchange(int *pa,int *pb)
{
	int temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;	
}	

int main ()
{
	int a = 7;
	int b = 5;

	exchange(&a,&b);

	printf("%d %d \r\n",a,b);
	
	return 0;
}
