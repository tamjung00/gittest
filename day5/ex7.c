#include <stdio.h>

int main()
{
	int num[10] = {4,5,3,8,6};

	printf("%d \r\n", sizeof(num));

	for(int i=0;i<sizeof(num)/sizeof(int);i++) {
		printf("%d ",num[i]);
	}
	
	return 0;


}
