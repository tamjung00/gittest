#include <stdio.h>

int main()
{
	
	FILE *pfile = fopen("ex1.c","r");
	
	if(pfile == NULL) {
		puts("open failed");
	}
	else {
		puts("open success");


		while(1) {
			char ch = fgetc(pfile);
			if(ch == EOF) break;
			putchar(ch);
		}
	}

	fclose(pfile);
	
	return 0;
}
