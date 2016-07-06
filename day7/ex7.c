#include <stdio.h>

int main()
{
	int in;
	double db;
	char ch;

	void *vp;

	vp = &in;
	*(int *)vp = 1;
	vp = &db;
	*(double*)vp = 1.0;
	vp = &ch;
	*(char*)vp = 'c';

	printf("%d,%f,%c \r\n",in,db,ch);


}
