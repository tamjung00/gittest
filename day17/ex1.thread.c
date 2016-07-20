#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid; //쓰레드 구조체

void *doSomeThing(void *arg) //쓰레드 함수는 정해져있다
{
	int nCount = 0;
	
	while(1)
	{
		printf("%d sec\r",nCount);
		//puts("test");
		sleep(1);
		nCount++;
	}
	return NULL;
}

int main()
{	
	
	int err;
	err = pthread_create(&tid,NULL,&doSomeThing,NULL); //쓰레드 생성
	if(err != 0) {
		printf("\r\n cannot cread thread : [%s] \r\n",strerror(err));
	}
	else {
		printf("\r\n Thread created successfully \r\n");
	}
	
	char ch = getchar();

	//doSomeThing(NULL);

	printf("%u press %c key \r\n",ch);

	return 0;

}
