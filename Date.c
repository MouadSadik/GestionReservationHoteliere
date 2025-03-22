#include <stdio.h>
#include "Date.h"

int IsStrDate(char *, const char) ;

unsigned int TM[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

int IsDate(unsigned int j, unsigned int m, unsigned int a)
{
	if((m < 1) || (m > 12))
	{
		return 0 ;
	} 
	if((a % 4 == 0))
	{
		TM[2] = 29 ;
	}
	if((j < 1) || (j > TM[m]))
	{
		return 0 ;
	} 
	
	return 1 ;
}

int IsStrDate(char * str, const char sep)
{
	unsigned int jour, mois, annee;
    char separateur1, separateur2;

    
    if (sscanf(str, "%u%c%u%c%u", &jour, &separateur1, &mois, &separateur2, &annee) != 5)
    {
        return 0;
    }

    if (separateur1 != sep || separateur2 != sep)
    {
        return 0;
    }

    return IsDate(jour, mois, annee);
}

int ComparerDatesCroissantes(Date d1, Date d2)
{
    if (d1.a != d2.a)
        return d1.a - d2.a ;
        
    if (d1.m != d2.m)
        return d1.m - d2.m ;
        
    return d1.j - d2.j ;
}

int ComparerDatesDecroissantes(Date d1, Date d2)
{
    if (d1.a != d2.a)
        return d2.a - d1.a ;
        
    if (d1.m != d2.m)
        return d2.m - d1.m ;
        
    return d2.j - d1.j ;
}
