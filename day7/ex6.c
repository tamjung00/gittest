#include <stdio.h>

int doit(int (*fp)(int,int),int a,int b)
{
	return 0;
}

int sum(int a, int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
}

int main()
{
	int (*ary_fp[2])(int,int) = {
		sum,sub
		};
	//printf("%d\r\n",doit(sum,3,2) );
	//printf("%d\r\n",doit(sub,3,2) );
	
	for(int i=0;i<2;i++) {
		printf("%d \r\n",doit(ary_fp[i],3,20));
	}

	return 0;
}
