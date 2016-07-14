#include <stdio.h>
#include "../../CJSON/CJSON.h"

int main()
{
	char *pStrJSON = "{ \"xpos\":1, \"cmd\":\"move\"  }";

	cJSON *pJson;

	pJson = cJSON_Parse(pStrJSON);
	
	printf("%d \r\n", cJSON_GetObjectItem(pJson,"xpos")->valueint);
	printf("%s \r\n", cJSON_GetObjectItem(pJson,"cmd")->valuestring);

	cJSON_Delete(pJson);

	return 0;
}
