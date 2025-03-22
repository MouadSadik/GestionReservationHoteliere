#include<stdlib.h>


typedef struct chambre
{
    unsigned int idChambre;
    unsigned int idHotel;
    unsigned int numeroChambre;
    char* typeChambre;
    unsigned int capacite;
    unsigned int etage;
    double prixChambre;
}Chambre;


static unsigned int NBChambre = 0 ; 
static unsigned int CChambre= 0 ; 
static Chambre * TChambre = NULL ;
