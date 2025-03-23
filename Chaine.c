#include <stdio.h>
#include <malloc.h>
#include "Chaine.h"



char* SaisirChaine()
{
	int c, nbc = 0;
	char * str = NULL;
	
	while((c = getchar()) != '\n')
	{
		str=(char*)realloc(str, (nbc+1)*sizeof(char));
		str[nbc++] = c;
	}
	if(nbc > 0)
	{
		str = (char*)realloc(str, (nbc+1)*sizeof(char));
		str[nbc] = '\0';
	}
	
	return str;
}


