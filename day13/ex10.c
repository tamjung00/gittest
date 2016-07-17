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

//#include "bullet.h"
#include "plane.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer[2]; 
//_S_MAP_OBJECT gScreenBuf[2];
_S_MAP_OBJECT gPlayer;
_S_Plane gPlayerObject;

//게임오브잭트 선언 
 _S_Plane gPlayerPlane;

S_BULLET_OBJECT g_bullets[32];

int main()
{
    set_conio_terminal_mode();
	acc_tick=last_tick=0;
	
    system("clear");

	for(int i =0;i<2;i++) //총알
	{
		map_init(&gScreenBuffer[i]);
		map_new(&gScreenBuffer[i],35,16);
	}

	
	map_init(&gPlayer);
	map_load(&gPlayer,"plane1.dat");

	Plane_init(&gPlayerObject,&gPlayer,17,10);

	double target_x,target_y;
	double center_x,center_y;
	center_x = 14;
	center_y = 7;
	
	target_x = 14;
	target_y = 3;
	
	double angle = 0;
	
	
	
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
			//Plane_Apply(&gPlayerObject,delta_tick,ch);
            
            gPlayerObject.fpApply(&gPlayerObject,delta_tick,ch);
        }
         
         //apply 위치

		angle += (delta_tick * 45);
		double tx,ty;
		double rad = angle/180.0 * 3.141592;
		tx = (target_x - center_x) *cos(rad) - (target_y - center_y) * sin(rad);
		ty = (target_x - center_x) *sin(rad) - (target_y - center_y) * cos(rad);
		tx += center_x;
		ty += center_y;
		

        //타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			//puts("tick...\r");
			gotoxy(0,0);
			//map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			map_drawTile(&gScreenBuffer[0],0,0,&gScreenBuffer[1]);
			map_PutTile(&gScreenBuffer[1],tx,ty,2); 
            map_PutTile(&gScreenBuffer[1],center_x,center_y,5); 
			map_PutTile(&gScreenBuffer[1],target_x,target_y,1) ;
			
			gPlayerObject.fpDraw(&gPlayerObject,&gScreenBuffer[1]);

            //gotoxy(0,0);
			//Plane_Draw(&gPlayerObject,&gScreenBuf[1]);

			//map_dump(&gScreenBuf[1],Default_Tilepalete);
            map_dump(&gScreenBuffer[1],Default_Tilepalete);
            
			acc_tick = 0;
		}

	}

	
	return 0;

}
