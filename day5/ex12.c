#include <stdio.h>

int main()
{

	char cmd;
	int bLoop;
	char buffer[64];
	int nTailIndex = 0;

	for(int i=0;i<64;i++) {
		buffer[i] =0;
	}
	bLoop = 1;
	while(bLoop) {

		scanf("%c",&cmd);
		getchar();

		switch(cmd) {
			case 'a' ://add
			printf("what : ");
			scanf("%c",cmd);
			getchar();
			buffer[nTailIndex] = cmd;
			nTailIndex++;
			break;
			case 'd' ://
			nTailIndex--;
			buffer[nTailIndex] = 0x00;
			break;
			case 'f' :
			//앞에서 부터 지우기
			for(int i=0;i<nTailIndex-1;i++) {
				buffer[i] = buffer[i+1];
			}
			nTailIndex--;
			buffer[nTailIndex] = 0x00;
			break;
			case 's' :
			printf("%s \r\n",buffer);
			break;
			case 'q' : 
			printf("quit \r\n");
			bLoop = 0;
			break;
		}

	}

}
