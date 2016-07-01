#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("clear");

    printf("\x1b[3;20f");
	printf("|");
	printf("\x1b[4;20f");
	printf("|");

	printf("\x1b[3;3f");
	printf("hello");
	printf("\x1b[5;2f");
	printf("world");

	printf("\x1b[20;0f");
	printf("====================");

	return 0;
}
