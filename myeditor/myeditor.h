#ifndef __MY_EDITOR_H__
#define __MY_EDITOR_H__

/*
 push str
 pop
 del
 rm index
 ins index str
 set index str

 */
typedef struct {
	char *m_szStr;
	void *m_pNext;
} _S_STR_LINE;

#endif
