#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//add 10,20
	//sub 5,2
	//mul 4,3
	//div 8,2

	char strCmd[128];

	gets(strCmd);
	//scanf("%s",strCmd);
	
	//...
	
	char *ptrTemp;
	char *pCmd;
	int a,b;

	ptrTemp = strtok(strCmd," ");

	pCmd = strdup(ptrTemp);

	a = atoi( strtok(NULL,",") );
	b = atoi( strtok(NULL,",") );
	
	if(strcmp(pCmd,"add") == 0) {
		printf("덧셈을...%d \r\n",a+b);
	}

	else if(strcmp(pCmd,"sub") == 0) {
		printf("뺄셈을...%d \r\n",a-b);
	}
	
	if(strcmp(ptrTemp, "mul") == 0) {
		printf("곱셈을...%d \r\n",a*b);
	}
	else if(strcmp(ptrTemp, "div") == 0) {
	 
		printf("나눗셈을...%d \r\n",a/b);	
	}



	return 0;
}
