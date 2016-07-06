#include <stdio.h>

int print_array(char **ary)
{
	for(int i=0;i<4;i++) {
		puts(ary[i]);
	}
}

int main()
{
	char *ptr_ary[]={"eagle", "tiger", "lion", "squirrel"};
	int count;
	
	count = sizeof(ptr_ary)/sizeof(ptr_ary[0]);

	/*
	 * for(i=0;i<count;i++) {
		printf("%s \r\n",ptr_ary[i]);
	 }
	*/

	print_array(ptr_ary);
	

	return 0;
}
