#include<stdio.h>
#include<stdlib.h>
#include"Reservation.h"
#include"Clients.h"


static unsigned int NB_Reservation = 0 ; 
static unsigned int CReservation = 0 ; 
static Reservation * TReservation = NULL ;


// Ajouter une reservation
void ajouterReservation(Reservation nouvelleReservation) {
    if (NB_Reservation == 0) {
        TReservation = (Reservation *)malloc(sizeof(Reservation));
    } else {
        TReservation = (Reservation *)realloc(TReservation, (NB_Reservation + 1) * sizeof(Reservation));
    }
    TReservation[NB_Reservation] = nouvelleReservation;
    NB_Reservation++;
    CReservation++;
    printf("Reservation ajoutee avec succes.\n");
}

// Afficher toutes les reservations
void afficherReservations() {
    for (int i = 0; i < NB_Reservation; i++) {
        printf("ID Reservation: %d | ID Chambre: %d | ID Nourriture: %d | ID Client: %d | Nombre de personnes: %d | Arrivee: %d/%d/%d | Depart: %d/%d/%d | Prix Total: %.2f\n",
               TReservation[i].id_Reservation,
               TReservation[i].id_Chambre,
               TReservation[i].id_Nourriture,
               TReservation[i].id_Client,
               TReservation[i].Nombre_Personnes,
               TReservation[i].Date_Arrive.j, TReservation[i].Date_Arrive.m, TReservation[i].Date_Arrive.a,
               TReservation[i].Date_Depart.j, TReservation[i].Date_Depart.m, TReservation[i].Date_Depart.a,
               TReservation[i].Prix_Total);
    }
}

// Rechercher une reservation par ID
int rechercherReservation(int id) {
    for (int i = 0; i < NB_Reservation; i++) {
        if (TReservation[i].id_Reservation == id) {
            return i;
        }
    }
    return -1; // Retourne -1 si non trouve
}

// Supprimer une reservation
void supprimerReservation(int id) {
    int index = rechercherReservation(id);
    if (index != -1) {
        for (int i = index; i < NB_Reservation - 1; i++) {
            TReservation[i] = TReservation[i + 1];
        }
        NB_Reservation--;
        TReservation = (Reservation *)realloc(TReservation, NB_Reservation * sizeof(Reservation));
        printf("Reservation supprimee avec succes.\n");
    } else {
        printf("Reservation introuvable.\n");
    }
}








int Menu_Res() {
    int choix;
    do {
        printf("\n--- Menu de Gestion des Reservations ---\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Afficher toutes les reservations\n");
        printf("3. Rechercher une reservation\n");
        printf("4. Supprimer une reservation\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: {
                // Ajouter une reservation
                Reservation r1;
                printf("Entrez l'ID de la reservation: ");
                scanf("%d", &r1.id_Reservation);
                printf("Entrez l'ID de la chambre: ");
                scanf("%d", &r1.id_Chambre);
                printf("Entrez l'ID de la nourriture: ");
                scanf("%d", &r1.id_Nourriture);
                printf("Entrez l'ID du client: ");
                scanf("%d", &r1.id_Client);
                printf("Entrez le nombre de personnes: ");
                scanf("%d", &r1.Nombre_Personnes);
                printf("Entrez la date d'arrivee (jour mois annee): ");
                scanf("%d %d %d", &r1.Date_Arrive.j, &r1.Date_Arrive.m, &r1.Date_Arrive.a);
                printf("Entrez la date de depart (jour mois annee): ");
                scanf("%d %d %d", &r1.Date_Depart.j, &r1.Date_Depart.m, &r1.Date_Depart.a);
                printf("Entrez le prix total: ");
                scanf("%lf", &r1.Prix_Total);

                ajouterReservation(r1);
                break;
            }
            case 2:
                // Afficher toutes les reservations
                printf("\n--- Liste des reservations ---\n");
                afficherReservations();
                break;
            case 3: {
                // Recherche d'une reservation
                int idRecherche;
                printf("Entrez l'ID de la reservation a rechercher: ");
                scanf("%d", &idRecherche);

                int index = rechercherReservation(idRecherche);
                if (index != -1) {
                    printf("\nReservation ID %d trouvee a l'index %d.\n", idRecherche, index);
                } else {
                    printf("\nReservation ID %d non trouvee.\n", idRecherche);
                }
                break;
            }
            case 4: {
                // Suppression d'une reservation
                int idSuppression;
                printf("Entrez l'ID de la reservation a supprimer: ");
                scanf("%d", &idSuppression);

                supprimerReservation(idSuppression);
                break;
            }
            case 5:
                // Quitter
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

    // Liberation de la memoire
    free(TReservation);

    return 0;
}