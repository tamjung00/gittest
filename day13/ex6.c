#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#define PI 3.141592
//a : 180 = b : PI
//b = a/180 * PI

int main()
{

	_S_MAP_OBJECT ScreenBuf;
	map_init(&ScreenBuf);
	map_new(&ScreenBuf,35,17);

	system("clear");
	gotoxy(0,0);
	
	double target_x = 14;
	double target_y = 4;

	double center_x = 14;
	double center_y = 8;

	map_PutTile(&ScreenBuf,center_x,center_y,5);
	map_PutTile(&ScreenBuf,target_x,target_y,2);

	for(int i=0;i<360;i++) 
	{
		double rad = ((double)i)/180.0 * PI;
		double tx,ty;
	
		
		tx = (target_x - center_x)* cos(rad) -
			(target_y - center_y) * sin(rad); 
		
		ty = (target_x - center_x) * sin(rad) + 
			(target_y - center_y) * cos(rad);

		tx += center_x;
		ty += center_y;
		
		//printf("%f,%f \r\n",tx,ty);
		map_PutTile(&ScreenBuf,tx,ty,1);
	}
	
	/*for(int i=0;i<35;i++) {
		angle = (double) i *(180/35);

	}
	*/

	map_dump(&ScreenBuf,Default_Tilepalete);

	return 0;


}

