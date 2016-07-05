#include <stdio.h>
int main()
{
	char str[80] = "dream";

	printf("%s \r\n",str);
	
	int nCount = 0;
	while(str[++nCount] != 0) {
	//str[nCount++] 이럴 경우에는 6으로 나온다
	}:	
	printf("%d",nCount);

	return 0;
}
