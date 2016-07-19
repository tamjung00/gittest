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
_S_MAP_OBJECT gMissileModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gBulletObject[32];
_S_ALIEN_OBJECT gAlienObjects[8];
_S_BULLET_OBJECT gMissileObject[32];

//충돌
double getDistance(_S_BULLET_OBJECT *pBullet,_S_Plane *pPlane)
	{
		double bullet_pos_x = pBullet->m_fXpos;
		double bullet_pos_y = pBullet->m_fYpos;
				
		double target_pos_x = gPlayerObject.m_fXpos;
		double target_pos_y = gPlayerObject.m_fYpos;

		double vx = target_pos_x - bullet_pos_x;
		double vy = target_pos_y - bullet_pos_y;
		double dist = sqrt(vx*vx+vy*vy);
		return dist;
	}

int main()
{

	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],40,25);
	}

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane1.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"plasma.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gMissileModel);
	map_load(&gMissileModel,"missile.dat");

	Plane_init(&gPlayerObject,&gPlayerModel,20,22);

	gPlayerObject.m_nFSM = 1;
	
//에일리언 총알
	for(int i=0;i< sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT) ;i++)
	{
		bullet_init(&gBulletObject[i],0,0,0,&gBulletModel);
		
	}

//비행기 총알
	for(int i=0;i< sizeof(gMissileObject)/sizeof(_S_BULLET_OBJECT) ;i++)
	{
		bullet_init(&gMissileObject[i],0,0,0,&gMissileModel);
		
	}

//에일리언 위치
	double TablePosition[] = {0,6.0,30.0,13.0};

	for(int i=0;i<4;i++)
	{
	
		_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = TablePosition[i];
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;
		
		gAlienObjects[i].m_pBullet = &gBulletObject[i];
	}
	

	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	system("clear");

//플레이상태로 만들기
	gPlayerObject.m_nFSM = 1;

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
			else if(ch=='j') {
				for(int i=0;i<sizeof(gMissileObject)/sizeof(_S_BULLET_OBJECT);i++) {
					_S_BULLET_OBJECT *pObj = &gMissileObject[i];
					if(pObj->m_nFSM == 0) { //슬립상태라면....
						bullet_fire(pObj,
								gPlayerObject.m_nXpos,
								gPlayerObject.m_nYpos,10,5.0);
						break;
					}
				}
			}		
		//비행기apply
			gPlayerObject.pfApply(&gPlayerObject,delta_tick,ch);
		}
			
	//에일리언총알 apply	
		for(int i=0;i< sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT) ;i++)
		{	
			_S_BULLET_OBJECT *pObj = &gBulletObject[i];
			pObj->pfApply(pObj,delta_tick);
		}	

	//에일리언apply
		for(int i=0;i<4;i++)
	
		{		
			_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
			pObj->pfApply(pObj,delta_tick);
		}		
	
	//에일리언총알과 비행기 충돌
		for(int i=0;i< sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT) ;i++)
		{
			_S_BULLET_OBJECT *pObj = &gBulletObject[i];
			
			if(pObj->m_nFSM != 0) {
				
				double dist = getDistance(pObj,&gPlayerObject); 

				if(dist < 0.25) {  
					pObj->m_nFSM = 0;
					gPlayerObject.m_nFSM = 0;
					printf("---------------GAME OVER----------------\r\n");
					bLoop = 0;
				}

			}
		}

		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			
            gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			gPlayerObject.pfDraw(&gPlayerObject,&gScreenBuf[1]); //비행기draw

		//에일리언 draw	
            for(int i=0;i<4;i++)	
			{
				_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);

			}
		
		//에일리언 총알 draw
			for(int i=0;i< sizeof(gBulletObject)/sizeof(_S_BULLET_OBJECT) ;i++)
			{	
				_S_BULLET_OBJECT *pObj = &gBulletObject[i];
			 	pObj->pfDraw(pObj,&gScreenBuf[1]);
			}	
		
			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
