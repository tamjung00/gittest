#include <stdio.h>
int main()
{
	int num1;

	printf("input :");
	scanf("%d", &num1);
	if(num1 > 5) {
		printf("5보다 큽니다. \r\n");
	}
	else if(num1 >3) {
		printf("3보다는 큽니다. \r\n");
	}
	else {
		printf("5보다 작습니다. \r\n");
	}

	return 0;
}
