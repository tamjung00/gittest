#include <stdio.h>

int main()
{
	int array1[]={1,2,3,4,5};
	int array2[5];
	
	int j = 4;

	for(int i=0;i<5;i++)
	{
		array2[i] = array1[j--];
		printf("%d \r\n",array2[i]);
	}

	for(int i=0;i<5;i++){
		printf("%d \r\n",array1[i]);
	}
	
	
	return 0;
}
