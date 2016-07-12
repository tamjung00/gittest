#include <stdio.h>
#include <stdlib.h>

#include "map.h"

int main()
{
	char TilePalete[] = {'.','#'.'@'};
	_S_MAP_OBJECT carObj;
	map_init(&carObj);
	
	map_load(&carObj,"car.dat");
	puts("-----load complete----------------")

	//system("clear");
	//
	map_dump(&carObj,TilePalete);
	
	return 0;
}
