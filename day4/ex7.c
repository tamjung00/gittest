#include <stdio.h>

int testAr[5] = {100,101,102,103,104};
char testAr2[5] = {100,101,102,103,104};

int main()
{
	printf("%d \r\n",testAr[1]);
	
	int *pTemp = testAr;
	printf("%d \r\n",pTemp[1]);
	printf("%d \r\n",pTemp[2]);
	printf("%d, %d, %d \r\n",pTemp,pTemp+1,pTemp+2);
	printf("%d, %d, %d \r\n",pTemp,*(pTemp+1),*(pTemp+2));

	char *pTemp2 = testAr2;
	printf("%d, %d, %d \r\n",pTemp2,pTemp2+1,pTemp2+2);

	return 0;
}
