#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include <pthread.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

pthread_t tid;

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

void *InputThread(void *arg)
{
	while(1)
	{
			char ch=getch();
			if(ch=='q') {
				bLoop = 0;
				puts("bye~\r");
		}

	}
	return NULL;
}

int main()
{
	int err = pthread_create(&tid,NULL,&InputThread,NULL);
	if(err != 0) {
		printf("err : \r\n",strerror(err));
	}
	else {
		printf("thread create success \r\n");
	}

	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	
	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간 입력
		if(kbhit() !=0) {
			char ch=getch();
			if(ch=='q') bLoop=0;
				bLoop = 0;
				puts("bye~\r");
		}
		//타이밍 계산
		acc_tick += delta_tick;
		if(acc_tick >1.0) {
			puts("tick...");
			acc_tick = 0;
		}
	}
	
	return 0;

}
