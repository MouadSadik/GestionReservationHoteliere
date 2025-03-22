#include<stdio.h>
#include<Clients.h>

<<<<<<< HEAD
struct client {
    int id_Client;
    char *Nom;
    char *Prenom;
    char *Email;
    char *Adresse;
    char *Nationalite;
    int Code_Postale;
    char *Ville_Client;
};
typedef struct client Client;


=======
static unsigned int NBC = 0 ; // Variable globale : Compteur de clients devant �tre auto-incr�ment� 
static unsigned int CC = 0 ; // Cle primaire de la structure Client
static Client * TC = NULL ; // Variable globale : Pointeur pour creer un tableau dynamique de clients
>>>>>>> 59d104493f378a843b2f08405b8a58cffa207989
