#include "Date.h"

struct facture {
    int id_Facture;
    int id_Client;
    int id_Reservation;
    float Montant_Total;
    Date Date_Facture;
};
typedef struct facture Facture;

void Menu_Facture();