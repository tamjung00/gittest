#include <stdio.h>

int main()
{

	FILE *pFile;

	pFile = fopen("ex1,c","r");

	char strLine[128];
	char *pTemp; 

	while(1) {
		//if(fgets(strLine,128,pFile) == NULL) break;
		pTemp = fgets(strLine,128,pFile);
		if(pTemp == NULL) break;
		printf("%s",pTemp);
	}


	return 0;
}
