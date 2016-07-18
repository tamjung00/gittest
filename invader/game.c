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

#include "plane.h"
#include "bullet.h"
#include "alien.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gBulletModel;
_S_MAP_OBJECT gAlienModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gBulletObject[32];
_S_ALIEN_OBJECT gAlienObjects[8];

int main()
{

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],35,16);
	}

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane1.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"plasma.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	double TablePosition[] = {0,6.0};

	for(int i=0;i<2;i++)
	{//에일리언위치
		
		_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = TablePosition[i];
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;

	}
	
	/*
	{ 
		
		_S_ALIEN_OBJECT *pObj = &gAlienModel[0];
		aline_init(&gAlienObject[0],&gAlienModel);
		pObj->m_fXpos = 5;
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;

	}
	*/

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


		for(int i=0;i<2;i++)
	
		{		

			_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
			pObj->pfApply(pObj,delta_tick);

		}		

		
		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			
			for(int i=0;i<2;i++)	
			{
				_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);

			}

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
