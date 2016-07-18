#ifndef __BULLET_H__
#define __BULLET_H__

typedef struct _S_BULLET_OBJECT {
	int m_nFSM;
	int m_nStep;
	double m_fXpos;
	double m_fYpos;

	double m_fCenterX; //중심점
	double m_fCenterY;
	
	double m_fvx;
	double m_fvy;
	double m_fSpeed;

	double m_faccLifeTime; //현재 생존시간 
	double m_fLifeLimit; //수명

	_S_MAP_OBJECT *m_pBody;

	void (*pfDraw)(struct _S_BULLET_OBJECT *pObj,_S_MAP_OBJECT *pMapBuf);
	
	void (*pfApply)(struct _S_BULLET_OBJECT *pObj,double deltaTick);
	
	void (*pfFire)(struct _S_BULLET_OBJECT *pObj,int x,int y,double vx,double vy,double speed,double lifeLimit);


} _S_BULLET_OBJECT;
 

void bullet_init(_S_BULLET_OBJECT *pObj,double x,double y,double speed,_S_MAP_OBJECT *pBody);

//void  bullet_apply(_S_BULLET_OBJECT *pObj,double deltaTick);

//void bullet_draw(_S_BULLET_OBJECT *pObj,_S_MAP_OBJECT *pMapBuf);

//void bullet_fire(_S_BULLET_OBJECT *pObj,int x,int y,double vx,double vy,double speed,double lifeLimit);

#endif
