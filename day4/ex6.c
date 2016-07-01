#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int world_map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,0,1,0,0,0,2,
	1,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int buffer_map[64];

int player_xpos = 1;
int player_ypos = 5;

void move_player(char cmd)
{	
	int old_xpos = player_xpos;
	int old_ypos = player_ypos;

	switch(cmd)
	{
		case 'i':
			printf("위로 한칸 이동했습니다\r\n");
			player_ypos -=1;
			break;
		case 'j':
			printf("좌로 이동했습니다\r\n");
			player_xpos -=1; 	
			break;
		case 'k':
			player_xpos += 1;
			break;
		case 'm':
			player_ypos += 1;
			break;
		
	}
		
	
	if(buffer_map[ player_xpos + player_ypos*8 ] ==0) {
	}
	else {
		//printf("막다른 길입니다. \r\n");
		player_xpos = old_xpos;
		player_ypos = old_ypos;
	}		


}

int main()
{
	char cmd;
	int bLoop = 1;

	while(bLoop) {
		printf("명령을 선택하세요,\r\n \
i(up),j(left),k(right),\r\n \
m(down),s(show map),x(exit)\r\n");
		
	for(int i=0;i<64;i++) {
			buffer_map[i] = world_map[i];
		}	

		scanf("%c",&cmd);
		getchar();
		move_player(cmd);
		buffer_map[ player_xpos + player_ypos*8 ] = 3;

		switch(cmd) {
			case 's':
				map_drawAll(buffer_map);
				break;
			case 'x':
				bLoop =0;
				printf("bye bye~\r\n");
				break;

		}

	}		
	
	return 0;
}
