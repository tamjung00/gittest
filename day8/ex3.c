#include <stdio.h>

struct _S_PLAYER {
	int m_nHp;
	int m_nMp;
};

int main()
{
	struct _S_PLAYER player1 = {
		100,50
	};
	
	struct _S_PLAYER player2;
	struct _S_PLAYER *pPlayer;

	player2 = player1;//복사
	pPlayer = &player1;//포인터 참조

	pPlayer-> m_nHp = 240;
	player2.m_nMp = 30;

	printf("%d \r\n",player1.m_nHp);


	return 0;
}
