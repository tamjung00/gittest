#include <stdio.h>

int main()
{

	char *ptrArray[5] = {
		"apple",
		"android",
		"windows",
		"linux",
		"unix"
	};

	for(int i=0;i<5;i++) {
		puts(ptrArray[i]);
	}
	
	for(int i=0;i<5;i++) {
		putchar(ptrArray[i][0]);
	}

	puts("");

	for(int i=0;i<5;i++) {
		putchar(ptrArray[0][1]);
	}
}
