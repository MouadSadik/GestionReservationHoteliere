#include<Date.h>

struct reservation {
    int id_Reservation;
    int id_Chambre;
    int id_Nourriture;
    int id_Client;
    int Nombre_Personnes;
    Date Date_Arrive;
    Date Date_Depart;
    float Prix_Total;
};
typedef struct reservation Reservation;