#include <stdio.h>

int main()
{
	char ch='A';
	char name[80]="황금박쥐";
	int in=10;
	double db=16.8;

	printf("정수형 상수의 출력 : %d\n", -10);
	printf("정수형 변수의 출력 : %d\n", in);
	printf("정수형 수식의 출력 : %d\n", in/3);

	printf("실수형 상수를 소수점 형태로 출력 : %1f\n", 2.5);
	printf("실수형 변수를 지수 형태로 출력 : %1e\n", db);
	printf("실수형 수식을 소수점 형태로 출력 : %1f\n", db/4);

	printf("문자상수의 출력 : %c\n", 'F');
	printf("문자변수의 출력 : %c\n", ch);
	printf("문자 배열의 출력 : %s\n:, name);
	printf("문자열상수의 출력 : %s\n", "날아라 태극호");

	return 0;
}
