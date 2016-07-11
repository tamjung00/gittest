#include <stdio.h>

void draw_tri1()
{
	int ix,iy;
	for(iy=0;iy<10;iy++) {
		for(ix=0;ix<iy;ix++) {
			putchar('*');
		}
		puts("");
	}
}	

void draw_tri2()
{
	int ix,iy;
	for(iy=0;iy<10;iy++) {
		for(ix=(10-iy);ix>0;ix--) {
			putchar('*');
		}
		puts("");
	}
}


void draw_line(int n,char c)
{
	for(int i=0;i<n;i++) {
		putchar(c);
	}
}

void draw_tri3()
{
	int iy;
	for(iy=0;iy<10;iy++) {
		draw_line(9-iy, ' '); 
		draw_line(iy,'*');
		puts("");
	}
}

void draw_tri4()
{
	int iy;
	for(iy=0;iy<10;iy++) {
		draw_line(9-iy,' ');draw_line((iy*2)+1,'*');
		puts("");
	}
	
	for(iy=0;iy<5;iy++) {
		draw_line(7,' '); draw_line(6,'*');
		puts("");

	}	
}

void draw_tri5()
{
	int ix,iy;
	/*for(iy=0;iy<10;iy++) {
		for(ix=0;ix<iy;ix++){
			putchar('*');
		}
		puts("");
	}*/
	for(iy=0;iy<10;iy++) {
		for(ix=(10-iy);ix>0;ix--) {
			putchar('*');
		}
		puts("");
	}

}
	
int main()
{
	//draw_tri1();
	//draw_tri2();
	//draw_tri3();
	//draw_tri4();
	draw_tri5();	
	return 0;
}
	
