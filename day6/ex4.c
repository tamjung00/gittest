#include <stdio.h>
int main()
{
	char strTemp[64];
	char strTemp2[64];

	scanf("%s %s",strTemp,strTemp2);
	
	printf("%s, %s \r\n",strTemp,strTemp2);

	int nSize1,nSize2;
	int i;
	for (i=0;strTemp[i] != 0x00;i++);
	nSize1 = i;
	for (i=0;strTemp2[i] != 0x00;i++);
	nSize2 = i;
	
	printf("%d,%d \r\n",nSize1,nSize2);

	if(nSize1 != nSize2) {
		printf("not match \r\n");
	}
	else {
		int bMatch = 1;
		for(int i=0;i<nSize1;i++) {
			if(strTemp[i] != strTemp2[i]) {
				break;
			}
		}
		if(bMatch) {
			printf("match \r\n");
		}
		else {
			printf("not match \r\n");
     	}
	}



/*	
	int nCount=0;
	for(int i=0;strTemp[i] !=0;i++) {
		if(strTemp[i] == '1') {
			nCount++;
		}
	}
	
	printf("%d \r\n",nCount);
*/	 
	
	return 0;
}
