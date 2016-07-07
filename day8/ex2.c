#include <stdio.h>

struct _S_WEPON {
	int m_nAttack;
	int m_nEndure;
};

struct _S_PLAYER {
	int m_nHP;
	int m_nMP;
	struct _S_WEPON swepon;

};

int main()
{
	struct _S_PLAYER player1;

	player1.m_nHP = 100;
	player1.m_nMP = 50;

	player1.sweapon.m_nAttack = 5;
	player1.sweapon.m_nEndure = 10;

	
	return 0;
}
