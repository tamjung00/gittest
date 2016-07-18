#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "bullet.h"
#include "alien.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gAlienModel;
_S_MAP_OBJECT gPlasmaModel;

_S_ALIEN_OBJECT gTestAlienObject;
_S_BULLET_OBJECT gTestBulletObject;

int main()
{

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,16);
	}
	
	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gPlasmaModel);
	map_load(&gPlasmaModel,"plasma.dat");

	alien_init(&gTestAlienObject,&gAlienModel);
	bullet_init(&gTestBulletObject,0,0,0,&gPlasmaModel);

	gTestAlienObject.m_pBullet = &gTestBulletObject;
	
	gTestAlienObject.m_fXpos = 5;
	gTestAlienObject.m_fYpos = 5;
	gTestAlienObject.m_nFSM = 1;
	
	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	system("clear");

	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		//실시간 입력
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}

		}
		
		gTestAlienObject.pfApply(&gTestAlienObject,delta_tick);
		gTestBulletObject.pfApply(&gTestBulletObject,delta_tick);

		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			
			gTestAlienObject.pfDraw(&gTestAlienObject,&gScreenBuf[1]);
			gTestBulletObject.pfDraw(&gTestBulletObject,&gScreenBuf[1]);
			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
