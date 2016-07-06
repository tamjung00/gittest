#include <stdio.h>

void exchange(char **ap,char **bp)
{
	char *tp;
	tp = *ap;
	*ap = *bp;
	*bp = tp;
}

int main()
{
	int val =10;
	int *ip;
	ip = &val;
	
	char *ap = "success";
	char *bp = "falied";
	char *tp;

	printf("ap :%s , bp : %s \r\n",ap,bp);

	exchange(&ap,&bp);//두 포인터변수 ap,bp의 값을 바꾸는 함수
	/*
	tp = ap;
	ap = bp;
	bp = tp;
	*/
	printf("ap :%s , bp : %s \r\n",ap,bp);

}
