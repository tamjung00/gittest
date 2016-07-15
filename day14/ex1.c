#include <stdio.h>

#include "test1.h"
#include "test2.h"

_S_TEST_1 test1;
_S_TEST_2 test2;

int main()
{

	test1_init(&test1);
	test2_init(&test2);

	test1.fpfoo();
	test2.fpfoo();
	
	return 0;
}

