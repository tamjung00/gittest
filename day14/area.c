#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "area.h"

static _S_AREA *find(_S_AREA *pObj,const char *area_name)
{
	for(int i=0;i<8;<i++) {
		_S_AREA *pArea = pObj->node[i];
		if(pArea != NULL){
			if(strcmp(area_name,pArea->m_szName) ==0) {
				return &
			}
				

		}
	}	

	return NULL;
}

static void draw (_S_AREA *pObj)
{
	printf("당신은 현재 %s 에 있습니다.  \r\n",pObj->m_szName);
}

void area_init(_S_AREA *pObj)
{
	for(int i=0;i<8;<i++) {
		*pObj->node[i] = NULL;	
	}	

	pObj->pfMove = move;
	pObj->pfDraw = draw;

}
