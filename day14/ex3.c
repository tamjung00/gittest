#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _S_ITEM_ {
	
	char m_szName[32];

	int m_nType;
	int m_nValue;

} _S_ITEM_;

_S_ITEM_ item_list[] = {
	{"short sword",0,10},
	{"wood shild",0,5},
	{"dagger",0,6},
	{"sling",0,3},
	{"staff",0,7},
};

unsigned long getHashCode(const char *szStr)
{
	int nLength = strlen(szStr);
	
	int nHash = 5381;

	for(int i=0;i<nLength;i++) {
		//printf("%d \r\n",szStr[i]);
		//nHash += szStr[i];
		int c = szStr[i];
		nHash = ((nHash<5) + nHash) + c;

	}

	return nHash;
}

_S_ITEM_ *findItem(const char *szName)
{
	int item_list_length = sizeof(item_list)/sizeof(_S_ITEM_);
	unsigned long hcode1 = getHashCode(szName); 
	for(int i=0;i<item_list_length;i++)
	{
		_S_ITEM_ *pitem = &(item_list[i]);
		//if(strcmp(szName,pitem->m_szName) == 0)
		if(getHashCode(pitem->m_szName) == hcode1) { 
		
			return pitem;
		}
	}

}

int main()
{
	_S_ITEM_ *pItem = findItem("short sword");
	printf("%s %d \r\n",pItem->m_szName,pItem->m_nValue);
	return 0;
}
