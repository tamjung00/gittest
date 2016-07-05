#include <stdio.h>
#include <string.h>

int ext_sum = 0;

void test()
{
	static int sum=0; //정적변수의 선언
	sum++;
	printf("%d \r\n",sum);

	ext_sum++;
}
extern int test_num;

int main()
{
	test();
	test();
	
	printf("%d \r\n",ext_sum);

	printf("%d \r\n",test_num);

	//printf("%d",sum);
	return 0;
}
