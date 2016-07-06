#include <stdio.h>

int main()
{
	int ary[3][4]= {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		};

	printf("%d , %d \r\n",ary[1][2],(*(ary+1)+2));

	return 0;
}
		
