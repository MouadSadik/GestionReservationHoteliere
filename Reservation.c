#include <stdio.h>
#include <stdlib.h>
#include "Date.h"
#include "Reservation.h"
#include "Clients.h"

static unsigned int NB_Reservation = 0;
static unsigned int CReservation = 0;
static Reservation *TReservation = NULL;

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

// Afficher les reservations
void afficherReservations() {
    for (int i = 0; i < NB_Reservation; i++) {
        printf("ID Reservation: %d | ID Chambre: %d | ID Nourriture: %d | ID Client: %d\n",
               TReservation[i].id_Reservation,
               TReservation[i].id_Chambre,
               TReservation[i].id_Nourriture,
               TReservation[i].id_Client);
    }
}

// Rechercher une reservation par ID
int rechercherReservation(int id) {
    for (int i = 0; i < NB_Reservation; i++) {
        if (TReservation[i].id_Reservation == id) {
            return i;
        }
    }
    return -1;
}

// Modifier une reservation
void modifierReservation(int id) {
    int index = rechercherReservation(id);
    if (index != -1) {
        printf("Nouveau nombre de personnes : ");
        scanf("%d", &TReservation[index].Nombre_Personnes);
        printf("Nouvelle date d'arrivee (jj mm aaaa) : ");
        scanf("%d %d %d", &TReservation[index].Date_Arrive.j, &TReservation[index].Date_Arrive.m, &TReservation[index].Date_Arrive.a);
        printf("Nouvelle date de depart (jj mm aaaa) : ");
        scanf("%d %d %d", &TReservation[index].Date_Depart.j, &TReservation[index].Date_Depart.m, &TReservation[index].Date_Depart.a);
        printf("Reservation modifiee avec succes.\n");
    } else {
        printf("Reservation introuvable.\n");
    }
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

// Sauvegarder les reservations dans un fichier texte
void sauvegarderReservationsDansFichier() {
    FILE *fichier = fopen("reservations.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    for (int i = 0; i < NB_Reservation; i++) {
        fprintf(fichier, "%d %d %d %d %d %d/%d/%d %d/%d/%d %.2f\n",
                TReservation[i].id_Reservation,
                TReservation[i].id_Chambre,
                TReservation[i].id_Nourriture,
                TReservation[i].id_Client,
                TReservation[i].Nombre_Personnes,
                TReservation[i].Date_Arrive.j, TReservation[i].Date_Arrive.m, TReservation[i].Date_Arrive.a,
                TReservation[i].Date_Depart.j, TReservation[i].Date_Depart.m, TReservation[i].Date_Depart.a,
                TReservation[i].Prix_Total);
    }
    fclose(fichier);
    printf("Reservations sauvegardees avec succes dans 'reservations.txt'.\n");
}

// Menu Reservation
void Menu_Reservation() {
    int choix, id;
    Reservation nouvelleReservation;

    do {
        printf("\n--- MENU RESERVATION ---\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Afficher les reservations\n");
        printf("3. Modifier une reservation\n");
        printf("4. Supprimer une reservation\n");
        printf("5. Sauvegarder les reservations\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("ID Reservation : "); scanf("%d", &nouvelleReservation.id_Reservation);
                printf("ID Chambre : "); scanf("%d", &nouvelleReservation.id_Chambre);
                printf("ID Nourriture : "); scanf("%d", &nouvelleReservation.id_Nourriture);
                printf("ID Client : "); scanf("%d", &nouvelleReservation.id_Client);
                printf("Nombre de personnes : "); scanf("%d", &nouvelleReservation.Nombre_Personnes);
                printf("Date d'arrivee (jj mm aaaa) : ");
                scanf("%d %d %d", &nouvelleReservation.Date_Arrive.j, &nouvelleReservation.Date_Arrive.m, &nouvelleReservation.Date_Arrive.a);
                printf("Date de depart (jj mm aaaa) : ");
                scanf("%d %d %d", &nouvelleReservation.Date_Depart.j, &nouvelleReservation.Date_Depart.m, &nouvelleReservation.Date_Depart.a);
                printf("Prix total : "); scanf("%f", &nouvelleReservation.Prix_Total);
                ajouterReservation(nouvelleReservation);
                break;
            case 2:
                afficherReservations();
                break;
            case 3:
                printf("ID Reservation a modifier : "); scanf("%d", &id);
                modifierReservation(id);
                break;
            case 4:
                printf("ID Reservation a supprimer : "); scanf("%d", &id);
                supprimerReservation(id);
                break;
            case 5:
                sauvegarderReservationsDansFichier();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 6);

    free(TReservation);
}
