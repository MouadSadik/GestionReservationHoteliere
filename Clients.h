#include "Date.h"

struct client {
    int id_Client;
    char *Nom;
    char *Prenom;
    char *Email;
    char *Adresse;
    char *Nationalite;
    int Code_Postale;
    char *Ville_Client;
    Date Date_Naissance;
    struct client *suivant;
};
typedef struct client Client;

void Menu_Client();