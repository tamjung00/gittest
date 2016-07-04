#include <stdio.h>

int main ()
{

	int num[] = {3,7,15,6,7,2};
	
	printf("배열의 갯수는 : %d \r\n",sizeof(num)/sizeof(int));
	
	int sum = 0;
	int max = -9999999;
	int min = 99999999;

	for(int i=0;i<sizeof(num)/sizeof(int);i++) {
		//sum = sum +num[i];
		sum += num[i];

	    if(max < num[i]) {
			max = num[i];
		}
		if(min>num[i]) {
			min = num[i];
		}	
	}
	
	
	printf("합 : %d \r\n",sum);
	printf("최대값 : %d \r\n",max);
	printf("최소값 : %d \r\r",min);
	
	return 0;

}
