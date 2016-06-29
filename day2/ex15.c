#include <stdio.h>

int main()
{
	int res = 1 > 2;

	printf("%d \r\n",res);
	
	res = 1 < 2;
	printf("%d \r\n",res);
	
	res = (1 == 2);
	printf("1==2 %d \r\n",res);

	res = (1 != 2);
	printf("1!=2 %d \r\n",res);

	res = (2 <= 2);
	printf("2<=2 %d \r\n",res);

	printf("%d,%d,%d,%d \r\n",(1&&1),(1&&0),(0&&0));
	printf("%d,%d,%d,%d \r\n",(1||1),(1||0),(0||0));
	printf("%d \r\n", !(1<2));

	return 0;
}
