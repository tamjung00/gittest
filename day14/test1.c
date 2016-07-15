#include <stdio.h>
#include "test1.h"
static void foo()
{
	printf("it is test1's foo \r\n");

}

void test1_init(_S_TEST_1 *pObj)
{
	pObj->fpfoo = foo;
}
