#ifndef __ENGIINE_2D__

#define __ENGIINE_2D__

void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);

}


int drawMyBox(
		int nXpos,int nYpos,
		int nColor,int nSize)
{
	int ix,iy;

	setColor(30,nColor);
	ix=0;
	for(iy=0;iy <= nSize;iy++) {
		for(ix=0;ix <=nSize;ix++) {
			gotoxy(ix+nXpos,iy+nYpos);
			printf(" ");
		}
	}

	setColor(0,0);

}
//--------------타일멥 엔진
void map_printCell(int rawdata)
{
	switch(rawdata) {
		case 0: //공터 
			printf(" ");
			break;
		case 1: //벽
			setColor(31,40);
			printf("-");
			break;
		case 2: //열린문 
			printf("M");
			break;
		case 3: //player
			setColor(33,40);
			printf("A");
			break;
		case 4 ://잠긴문
			setColor(32,40);
			printf("m");
			break;
		case 5: //열쇠
			setColor(34,40);
			printf("k");
			break;
		case 6: 
			setColor(31,40);
			printf("|");
			break;
		default:
			printf(" ");
			break;
	}

}

void map_drawAll(int *pMap)
{
	int ix,iy;

	for(iy=0;iy<10;iy++) {
		for(ix=0;ix<10;ix++) {
			map_printCell(pMap[ix+iy*10]);
		}
		printf("\r\n");
	}
}



#endif
