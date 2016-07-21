#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "fish.h"

static void Apply(_S_FISH_OBJECT *pObj,double deltaTick)
{
	double speed = 2.5;

	switch(pObj->m_nFSM) {

		case 0: //die
			break;
		case 1: //ready
			pObj->m_nFSM = 2; //시작
			break;
		case 2: //move 
			pObj->m_fYpos += (deltaTick *speed);
			
            if(pObj->m_fYpos >25) {
			   pObj->m_fYpos =0;
			   pObj->m_nFSM = 2;
			}
		}
}
static void Draw(_S_FISH_OBJECT *pObj,_S_MAP_OBJECT *pBuff)
{
	
	switch(pObj->m_nFSM)
	{
		case 0:
			break;
		default:
			map_drawTile_trn(pObj->m_pBody,
				(int)(pObj->m_fXpos + pObj->m_fCenterX),
				(int)(pObj->m_fYpos + pObj->m_fCenterY),
				pBuff);
			
			break;
	}
}

void Fish_init(_S_FISH_OBJECT *pObj,_S_MAP_OBJECT *pBody)
{
	pObj->m_nFSM = 0;
	pObj->m_nStep = 0;
	pObj->m_pBody = pBody;
	pObj->m_fYpos = 0;
	pObj->m_fXpos = 0;
	pObj->m_fSpeed = 0;	
	pObj->m_fCenterX = 0 - (pBody->m_header.m_nWidth/2);
	pObj->m_fCenterY = 0 - (pBody->m_header.m_nHeight/2);
	
	pObj->pfApply = Apply;
	pObj->pfDraw = Draw;

}