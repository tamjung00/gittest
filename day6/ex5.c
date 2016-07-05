#include <stdio.h>
#include <string.h>
int main()
{
	char *pStr = "hello world";
	char strTemp[128];

	strcpy(strTemp,pStr);//문자열복사함수 오른쪽-왼쪽으로 복사

	strTemp[0] = 'R';
	printf("원본 %s \r\n",pStr);

	printf("%s 을 복사 했습니다.  \r\n",strTemp);

	printf("문자열의 길이는 %d \r\n",strlen(strTemp));//문자열길이구하는함수
	
	int cmp = strcmp("hello world","rello");//문자열비교함수
	
	printf("%d \r\n",cmp);

	char *pstr2 = ",hi world";

	strcat(strTemp,pstr2);//두개의 문자열을 붙이는 함수
	printf("%s \r\n",strTemp);

}
