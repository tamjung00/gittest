#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

int main()
{

	_S_MAP_OBJECT ScreenBuf;
	map_init(&ScreenBuf);
	map_new(&ScreenBuf,35,17);

	system("clear");
	gotoxy(0,0);

	
	double startx,starty;
	double endx,endy;

	startx = 14; starty = 8;
	endx = 1; endy = 3;

	map_PutTile(&ScreenBuf,(int)startx,(int)starty,1);
	map_PutTile(&ScreenBuf,(int)endx,(int)endy,2);

////방향벡터 구하기	
	double mx,my;
	mx = startx; my = starty;

	double vx = endx - startx;
	double vy = endy - starty;
	double c = sqrt(vx*vx+vy*vy);

	vx /= c;
	vy /= c;
///////////////////////////////////
	
	//for(int i=0;i<8;i++) { 
	while(1) {
		mx += vx;
		my += vy;
		if( (int)mx == (int)endx && (int)my == (int)endy) {
			break;
		}

		map_PutTile(&ScreenBuf,(int)mx,(int)my,5);
		map_dump(&ScreenBuf,Default_Tilepalete);

	}

	return 0;


}

