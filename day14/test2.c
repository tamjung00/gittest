#include <stdio.h>
#include "test2.h"

static void foo()
{
	printf("it is test2's foo \r\n");
}

void test2_init(_S_TEST_2 *pObj)
{
	pObj->fpfoo = foo;
}
