#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}
	
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1b,y,x);
		
}	

int main()
{
	int fore_color;
	fore_color = 31;
	system("clear");
	//"\x1b[31m"
	//printf("%c[%dm",0X1b,fore_color);
	gotoxy(18,10);
	setColor(33,45);
	printf("hello");
	gotoxy(18,12);
	setColor(31,46);
	printf("world");
	setColor(0,0); //reset ansi command

	gotoxy(17,9);
	printf("*******");
	gotoxy(17,13);
	printf("*******");

	gotoxy(17,10);
	printf("*");
    gotoxy(17,11);
	printf("*");
    gotoxy(17,12);
	printf("*");
    gotoxy(17,13);
	printf("*");
	
	gotoxy(23,10);
	printf("*");
    gotoxy(23,11);
	printf("*");
    gotoxy(23,12);
	printf("*");
    gotoxy(23,13);
	printf("*");

	gotoxy(30,2);
	printf("|");
	gotoxy(30,3);
	printf("|");
	gotoxy(30,4);
	printf("|");
	gotoxy(30,5);
	printf("|");
	gotoxy(30,6);
	printf("|");
	gotoxy(30,7);
	printf("|");
	gotoxy(30,8);
	printf("|");
	gotoxy(30,9);
	printf("|");
	gotoxy(30,10);
	printf("|");
	gotoxy(30,11);
	printf("|");
	gotoxy(30,12);
	printf("|");
	gotoxy(30,13);
	printf("|");
	gotoxy(30,14);
	printf("|");
	gotoxy(30,15);
	printf("|");
	gotoxy(30,16);
	printf("|");
	gotoxy(30,17);
	printf("|");
	gotoxy(30,18);
	printf("|");
	gotoxy(30,19);
	printf("|");
    
	gotoxy(10,1);
	printf("|");
	gotoxy(10,2);
	printf("|");
	gotoxy(10,3);
	printf("|");
	gotoxy(10,4);
	printf("|");
	gotoxy(10,5);
	printf("|");
	gotoxy(10,6);
	printf("|");
	gotoxy(10,7);
	printf("|");
	gotoxy(10,8);
	printf("|");
	gotoxy(10,9);
	printf("|");
	gotoxy(10,10);
	printf("|");
	gotoxy(10,11);
	printf("|");
	gotoxy(10,12);
	printf("|");
	gotoxy(10,13);
	printf("|");
	gotoxy(10,14);
	printf("|");
	gotoxy(10,15);
	printf("|");
	gotoxy(10,16);
	printf("|");
	gotoxy(10,17);
	printf("|");
	gotoxy(10,18);
	printf("|");
	gotoxy(10,19);
	printf("|");

	gotoxy(10,1);
	printf("=====================");

	gotoxy(10,20);
	printf("=====================");

	return 0;
}
