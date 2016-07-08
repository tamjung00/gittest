#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//extern int bLoop;
//void me_exit();
int bLoop = 1;

void apply(char *); 

int main()
{
	puts("myeditor version 1.0");

	while(bLoop)
	{
		char strCmd[128];
		gets(strCmd);
		
		char *pTemp = strtok(strCmd," ");
		
		if(!strcmp(pTemp,"exit")) {bLoop = 0;}
		else {
			apply(pTemp);
		}
			
	}
	return 0;
}


