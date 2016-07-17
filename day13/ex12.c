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
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer[2];
_S_MAP_OBJECT gPlayer;
_S_Plane gPlayerObject;
_S_MAP_OBJECT gBulletModel;
S_BULLET_OBJECT gBulletObject;

//게임오브젝트 선언
_S_Plane gPlayerPlane;
S_BULLET_OBJECT g_bullets[32];

_S_MAP_OBJECT gBulletModel;

int main()
{
	set_conio_terminal_mode();
	acc_tick = last_tick = 0;
	
    system("clear");

	for(int i =0;i<2;i++) 
	{
		map_init(&gScreenBuffer[i]);
		map_new(&gScreenBuffer[i],35,15);
	}

   	map_init(&gPlayer);
	map_load(&gPlayer,"plane1.dat");

	map_init(&gBulletModel);
	map_load(&gBulletModel,"plasma.dat");
	bullet_init(&gBulletObject,0,0,0,&gBulletModel);

	Plane_init(&gPlayerObject,&gPlayer,14,10);

   int targetx,targety;

	targety = 14;
	targetx = 14;

	int fire_x = 14;
	int fire_y = 0;

    while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;
		      
        double vx,vy,c;
		
		//실시간 입력
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
         
         else if(ch == 'j') {
				double vx,vy,c;
				vx = targetx - fire_x;
				vy = targety - fire_y;
				c = sqrt(vx*vx+vy*vy);
				vx /= c;
				vy /= c;

				bullet_fire(&gBulletObject,
				fire_x,fire_y,
				10.0,vx,vy,
				10);
			}
            
		    else if(ch == 'a') 
		{
			targetx -= 1;

		}
		else if(ch == 'd')
		{
			targetx += 1;
		}
        
		

        gPlayerObject.fpApply(&gPlayerObject,delta_tick,ch);
 }
        
    
       
        bullet_apply(&gBulletObject,delta_tick);
        
         //타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
           
            map_drawTile(&gScreenBuffer[0],0,0,&gScreenBuffer[1]);
            bullet_draw(&gBulletObject, &gScreenBuffer[1]);

            map_PutTile(&gScreenBuffer[1],fire_x,fire_y,1);
			map_PutTile(&gScreenBuffer[1],targetx,targety,5);
           
           gPlayerObject.fpDraw(&gPlayerObject,&gScreenBuffer[1]);
           
            gotoxy(0,0);
			
        
            map_dump(&gScreenBuffer[1],Default_Tilepalete);
		

			puts("move : w,a,s,d \r");
			puts("quit : q \r");
			
			acc_tick = 0;
		}

	}

	return 0;

}