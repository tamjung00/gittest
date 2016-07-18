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

struct timespec work_timer;
double acc_tick,last_tick;
double acc_guid_delay_tick;//유도탄 딜레이 시간
int bLoop = 1;

_S_MAP_OBJECT gScreenBuf[2];
_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gBulletModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gTestBullet;

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

	Plane_init(&gPlayerObject,&gPlayerModel,17,10);
	bullet_init(&gTestBullet,0,0,0,&gBulletModel);

	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	acc_guid_delay_tick = 0;

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
			else if (ch =='j') {
				
				double bullet_pos_x = 0;
				double bullet_pos_y = 0;
				
				double target_pos_x = gPlayerObject.m_fXpos;//비행기위치
				double target_pos_y = gPlayerObject.m_fYpos;

				double vx = target_pos_x - bullet_pos_x;//방향벡터구하기
				double vy = target_pos_y - bullet_pos_y;
				double dist = sqrt(vx*vx+vy*vy);
				vx /= dist;
				vy /= dist;


				gTestBullet.pfFire(&gTestBullet,
				bullet_pos_x,bullet_pos_y,
				10.0,vx,vy,10);
			}

			gPlayerObject.pfApply(&gPlayerObject,delta_tick,ch);

		}
			acc_guid_delay_tick += delta_tick;
			if(acc_guid_delay_tick > 2.5)
			{	
				acc_guid_delay_tick = 0;

				double bullet_pos_x = gTestBullet.m_fXpos;
				double bullet_pos_y = gTestBullet.m_fYpos;
				
				double target_pos_x = gPlayerObject.m_fXpos;//비행기위치
				double target_pos_y = gPlayerObject.m_fYpos;

				double vx = target_pos_x - bullet_pos_x;//방향벡터구하기
				double vy = target_pos_y - bullet_pos_y;
				double dist = sqrt(vx*vx+vy*vy);
				vx /= dist;
				vy /= dist;

				gTestBullet.m_fvx = vx;
				gTestBullet.m_fvy = vy;

			}

	
		gTestBullet.pfApply(&gTestBullet,delta_tick);

		//타이밍 계산 
		
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
		
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			
			gPlayerObject.pfDraw(&gPlayerObject,&gScreenBuf[1]);
			gTestBullet.pfDraw(&gTestBullet,&gScreenBuf[1]);

			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
