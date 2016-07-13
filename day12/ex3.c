#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"
#include "bullet.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gBulletModel;
S_BULLET_OBJECT gBulletObject;

int main()
{
	system("clear");
	for(int i=0;i<2;i++) {
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,16);
	}

	map_init(&gBulletModel);
	map_load(&gBulletModel,"bullet1.dat");

	bullet_init(&gBulletObject,0,0,0,&gBulletModel);


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
			if(ch=='q') {
				bLoop = 0;
				puts("bye~\r");
			}
			else if(ch == 'j') {

				bullet_fire(&gBulletObject,17,12,10,0,5,0);
			}
		}
		//타이밍 계산
		acc_tick += delta_tick;
		bullet_apply(&gBulletObject,delta_tick);


		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			bullet_draw(&gBulletObject,&gScreenBuf[1]);

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			//puts("tick...\r\n");
			//printf("%f \r\n",gBulletObject.m_fYpos);
			acc_tick = 0;
		}
	}
	
	return 0;

}
