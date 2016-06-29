#include <stdio.h>

int main()
{
	char *strTemp = "hello world";
	int index;
	printf("%s \r\n",strTemp);
	printf("%c \r\n",101);
	printf("문자를 선택하세요...");

	scanf("%d",&index);

	strTemp[index] = strTemp[index] + 1;
	
	printf("%c , %d \r\n",strTemp[index],strTemp[index]);
	printf("%s \r\n",strTemp);

	return 0;
}
