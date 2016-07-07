#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _S_PLAYER {
	int m_nHp;
	char m_szName[128];	
};

int main()
{
	struct _S_PLAYER *pPlayer;

	pPlayer = (struct _S_PLAYER *)malloc( sizeof( struct _S_PLAYER));
	
	pPlayer -> m_nHp = 100;
	strcpy(pPlayer->m_szName, "aria stak");

	free(pPlayer);

	return 0;
}
