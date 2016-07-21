#ifndef _FISH_H_
#define _FISH_H_

typedef struct _S_FISH_OBJECT {

	int m_nFSM;
	int m_nStep;

	double m_fXpos;
	double m_fYpos;

	double m_fCenterX;
	double m_fCenterY;

	double m_fSpeed;


 	_S_MAP_OBJECT *m_pBody;
	//_S_BULLET_OBJECT *m_pBullet;

	void(*pfApply)(struct _S_FISH_OBJECT *,double); 
	void(*pfDraw)(struct _S_FISH_OBJECT *,_S_MAP_OBJECT *); 


} _S_FISH_OBJECT;

void Fish_init(_S_FISH_OBJECT *pObj,_S_MAP_OBJECT *pBody);

#endif