#include <stdio.h>

typedef struct {
	int m_nHp;
	char m_szName[128];
} _S_Player;

/*
 c++용
 class _S_Player {
}
*/

//typedef struct _S_PLAYER _S_Player;

int main()
{
	_S_Player player = {
		100,
		"player1",
	};

	puts(player.m_szName);

	return 0;
}
