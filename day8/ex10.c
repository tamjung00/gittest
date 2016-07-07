#include <stdio.h>

int main()
{
	FILE *pFile;
	pFile = fopen("test.txt","w");

	fprintf(pFile,"%d,%s \r\n",100,"hello");

	fclose(pFile);

	pFile = fopen("test.txt","r");
	char szStr[128];
	int num;
	fscanf(pFile,"%d,%s \r\n",&num,szStr);

	return 0;
}
