#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"
#include "r_game.h"

char screen_buffer[20*20];

struct timespec work_timer;
double acc_tick,last_tick;

double rock_acc_tick;
int rock_pos_x,rock_pos_y;
int rock_pos_table[20] = { 1,13,18,5,9,12,6,2,1,19,11,3,4,8,17,15,16};
int rock_cur_table_index = 0;
int bLoop = 1;

double rock_acc_tick1;
int rock_pos_x1,rock_pos_y1;
int rock_pos_table1[20] = { 10,5,7,3,1,11,19,9,16,17,18,18,9,8,4,2,9};
int rock_cur_table_index1 = 0;

double rock_acc_tick2;
int rock_pos_x2,rock_pos_y2;
int rock_pos_table2[20] = { 5,10,9,18,13,4,17,8,3,2,1,16,15,6,11,12,3};
int rock_cur_table_index2 = 0;

double rock_acc_tick3;
int rock_pos_x3,rock_pos_y3;
int rock_pos_table3[20] = { 16,2,19,15,1,8,10,12,4,9,14,3,1,6,9,18,11};
int rock_cur_table_index3 = 0;


int car_posx,car_posy;

static int nFSM = 0;
static int nStep = 0;

void rg_PlayGame(double delta_tick)
{
	switch(nStep)
	{
		case 0:
			nStep++;
			system("clear");
			break;

		case 1:	
			//사용자 입력처리 
			if(kbhit() != 0) {
				char ch = getch();
				if(ch == 'q') {
					bLoop = 0;
				}
				else if(ch == 'a') {
					car_posx -= 1;
				}
				else if(ch == 'd') {
					car_posx += 1;
				}
				//printf("%d \r\n",ch);
			}

			//바위 움직이기 
			rock_acc_tick += delta_tick;

			if(rock_acc_tick > 0.5) {
				rock_acc_tick = 0;
				rock_pos_y += 1;
				//화면끝도달...
				if(rock_pos_y >= 20) {
					rock_pos_y = 0;
					rock_cur_table_index++;
					rock_cur_table_index %= 20;
					rock_pos_x = rock_pos_table[ rock_cur_table_index];
				
				}
	
			}
			rock_acc_tick1 += delta_tick;
			
			if(rock_acc_tick1 > 1) {
				rock_acc_tick1= 0;a
				rock_pos_y1 += 1;
				//화면끝도달...
				if(rock_pos_y1 >= 20) {
					rock_pos_y1 = 0;
					rock_cur_table_index1++;
					rock_cur_table_index1 %= 20;
					rock_pos_x1 = rock_pos_table1[ rock_cur_table_index1];
				
				}
	
			}
			rock_acc_tick2 += delta_tick;
			
			if(rock_acc_tick2 > 1.5) {
				rock_acc_tick2= 0;
				rock_pos_y2 += 1;
				//화면끝도달...
				if(rock_pos_y2 >= 20) {
					rock_pos_y2 = 0;
					rock_cur_table_index2++;
					rock_cur_table_index2 %= 20;
					rock_pos_x2 = rock_pos_table2[ rock_cur_table_index2];
				
				}
	
			}
			rock_acc_tick3 += delta_tick;
			
			if(rock_acc_tick3 > 2) {
				rock_acc_tick3= 0;
				rock_pos_y3 += 1;
				//화면끝도달...
				if(rock_pos_y3 >= 20) {
					rock_pos_y3 = 0;
					rock_cur_table_index3++;
					rock_cur_table_index3 %= 20;
					rock_pos_x3 = rock_pos_table3[ rock_cur_table_index3];
				
				}
	
			}


			//게임로직 (판정)
			if(rock_pos_y == car_posy &&
					rock_pos_x == car_posx)
			{
				bLoop = 0;
				//drawGame(screen_buffer);
				printf("game over\n");
			}
			
			if(rock_pos_y1 == car_posy &&
					rock_pos_x1 == car_posx)
			{
				bLoop = 0;
				//drawGame(screen_buffer);
				printf("game over\n");
			}
			if(rock_pos_y2 == car_posy &&
					rock_pos_x2 == car_posx)
			{
				bLoop = 0;
				//drawGame(screen_buffer);
				printf("game over\n");
			}
			if(rock_pos_y3 == car_posy &&
					rock_pos_x3 == car_posx)
			{
				bLoop = 0;
				//drawGame(screen_buffer);
				printf("game over\n");
			}

			//버퍼초기화 
			for(int i=0;i<400;i++) {
				screen_buffer[i] = 0;
			}

			//자동차 그리기 
			screen_buffer[ car_posy *20+ car_posx] = 2;
			//바위 그리기 
			screen_buffer[ rock_pos_y*20 + rock_pos_x ] = 1;
			screen_buffer[ rock_pos_y1*20 + rock_pos_x1] =1;
			screen_buffer[ rock_pos_y2*20 + rock_pos_x2] =1;
			screen_buffer[ rock_pos_y3*20 + rock_pos_x3] =1;


			acc_tick += delta_tick;
			if(acc_tick > 0.1 || bLoop == 0 ) {
				acc_tick = 0;
				drawGame(20,20,screen_buffer);
			}

			break;

		}

}

void rg_apply_mainTitle()
{
	switch(nStep) {
	
		case 0:
		puts("press to start");
		nStep = 1;
		break;
		case 1:
		//사용자 입력처리 
		if(kbhit() != 0) {
			
			char ch = getch();
			nFSM = 1;
			nStep = 0;
		}
		break;
	}

}

int main()
{
	//버퍼초기화 
	for(int i=0;i<400;i++) {
		screen_buffer[i] = 0;
	}

	set_conio_terminal_mode();
	
	acc_tick = last_tick = 0;
	system("clear");

	car_posy = 19;
	car_posx = 10;

	rock_pos_y = 0;
	rock_pos_x = rock_pos_table[ rock_cur_table_index ];
	rock_pos_y1 = 0;
	rock_pos_x1 = rock_pos_table1[ rock_cur_table_index1 ];
	rock_pos_y2 = 0;
	rock_pos_x2 = rock_pos_table2[ rock_cur_table_index2 ];
	rock_pos_y3 = 0;
	rock_pos_x3 = rock_pos_table3[ rock_cur_table_index3 ];


	while(bLoop) {

		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;


		if(nFSM == 0) { //타이틀 메뉴 상태 
			rg_apply_mainTitle(delta_tick);

		}
		else if(nFSM ==1 ) { //게임상태... 
			rg_PlayGame(delta_tick);
		}
		else {
		}

	}


	return 0;
}
