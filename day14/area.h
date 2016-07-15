#ifndef _AREA_H_
#define _AREA_H_

typedef struct _S_AREA {
	char *m_szName;
	struct _S_AREA *node[8];

	void (*fpDraw)(struct _S_AREA *);
	struct _S_AREA *(*fpFind)(struct _S_AREA *,const char *);

} _S_AREA;

void area_init(_S_AREA *pObj);


#endif
