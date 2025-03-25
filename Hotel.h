

typedef struct hotel{
    unsigned int idHotel;
    char* nomHotel;
    char* adresseHotel;
    char* villeHotel;
    char* paysHotel;
    char*telHotel;
    char*emailHotel;
    char*siteWebHotel;
    unsigned int nbrEtoil;
}Hotel;


static unsigned int NBHotel = 0;
static unsigned int IdsHotel = 0;
static Hotel *THotel = NULL;


void Menu_Hotel();

