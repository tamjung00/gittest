#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ip;
	int nCount;
	int sum = 0;

	puts("입력할 데이터 수를 입력하세요.");
	scanf("%d", &nCount);

	ip =(int *)malloc(sizeof(int) *nCount);

	for(int i=0;i<nCount;i++) {
		puts("데이터 입력하세요.");
		
		//scanf("%d",ip+i);
		scanf("%d",&(ip[i]));
	}

	for(int i=0;i<nCount;i++) {
		sum += ip[i];
	}

	printf("%d \r\n",sum);
	free(ip);

	return 0;
}
