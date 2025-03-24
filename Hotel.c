#include "Hotel.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Chaine.h"



void ChargerHotelsDepuisFichier(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file))
    {
        // Allocate memory for the new hotel
        NBHotel++;
        THotel = realloc(THotel, NBHotel * sizeof(Hotel));
        if (THotel == NULL)
        {
            printf("Erreur d'allocation mémoire.\n");
            fclose(file);
            return;
        }

        // Parse the line
        char *token = strtok(line, "$");
        THotel[NBHotel - 1].idHotel = atoi(token); // Get ID

        token = strtok(NULL, "$");
        THotel[NBHotel - 1].nomHotel = strdup(token); // Get Name

        token = strtok(NULL, "$");
        THotel[NBHotel - 1].adresseHotel = strdup(token); // Get Address

        token = strtok(NULL, "$");
        THotel[NBHotel - 1].villeHotel = strdup(token); // Get City

        token = strtok(NULL, "$");
        THotel[NBHotel - 1].paysHotel = strdup(token); // Get Country

        token = strtok(NULL, "$");
        if (!IsPhoneNumber)
        {
            NBHotel--;
            THotel = realloc(THotel, NBHotel * sizeof(Hotel));
            return;
        }
        THotel[NBHotel - 1].telHotel = strdup(token); // Get Phone

        token = strtok(NULL, "$");
        if (!IsEmail)
        {
            NBHotel--;
            THotel = realloc(THotel, NBHotel * sizeof(Hotel));
            return;
        }
        THotel[NBHotel - 1].emailHotel = strdup(token); // Get Email

        token = strtok(NULL, "$");
        if (!IsWebsite)
        {
            NBHotel--;
            THotel = realloc(THotel, NBHotel * sizeof(Hotel));
            return;
        }
        THotel[NBHotel - 1].siteWebHotel = strdup(token); // Get Website

        token = strtok(NULL, "$");
        THotel[NBHotel - 1].nbrEtoil = atoi(token); // Get Stars
    }

    fclose(file);
    printf("Données des hôtels chargées depuis le fichier %s.\n", filename);
}

void AjouterHotel()
{
    NBHotel++;
    Hotel *temp = realloc(THotel, NBHotel * sizeof(Hotel));
    if (temp == NULL)
    {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }
    THotel = temp;

    THotel[NBHotel - 1].idHotel = IdsHotel++;

    printf("Nom de l'hôtel: ");
    THotel[NBHotel - 1].nomHotel = SaisirChaine();

    printf("Adresse de l'hôtel: ");
    THotel[NBHotel - 1].adresseHotel = SaisirChaine();

    printf("Ville de l'hôtel: ");
    THotel[NBHotel - 1].villeHotel = SaisirChaine();

    printf("Pays de l'hôtel: ");
    THotel[NBHotel - 1].paysHotel = SaisirChaine();

    printf("Téléphone de l'hôtel: ");
    THotel[NBHotel - 1].telHotel = SaisirChaine();

    printf("Email de l'hôtel: ");
    THotel[NBHotel - 1].emailHotel = SaisirChaine();

    printf("Site Web de l'hôtel: ");
    THotel[NBHotel - 1].siteWebHotel = SaisirChaine();

    printf("Nombre d'étoiles: ");
    scanf("%u", &THotel[NBHotel - 1].nbrEtoil);

    printf("Hôtel ajouté avec succès! ID: %u\n", THotel[NBHotel - 1].idHotel);
}

void AfficherHotel(unsigned int id)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    for (unsigned int i = 0; i < NBHotel; i++)
    {
        if (THotel[i].idHotel == id)
        {
            printf("-----------------------------\n");
            printf("Hôtel ID: %u\n", THotel[i].idHotel);
            printf("Nom: %s\n", THotel[i].nomHotel);
            printf("Adresse: %s\n", THotel[i].adresseHotel);
            printf("Ville: %s\n", THotel[i].villeHotel);
            printf("Pays: %s\n", THotel[i].paysHotel);
            printf("Téléphone: %s\n", THotel[i].telHotel);
            printf("Email: %s\n", THotel[i].emailHotel);
            printf("Site Web: %s\n", THotel[i].siteWebHotel);
            printf("Nombre d'étoiles: %u\n", THotel[i].nbrEtoil);
            printf("-----------------------------\n");
        }
    }
}

void AfficherHotels()
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    for (unsigned int i = 0; i < NBHotel; i++)
    {
        printf("-----------------------------\n");
        printf("Hôtel ID: %u\n", THotel[i].idHotel);
        printf("Nom: %s\n", THotel[i].nomHotel);
        printf("Adresse: %s\n", THotel[i].adresseHotel);
        printf("Ville: %s\n", THotel[i].villeHotel);
        printf("Pays: %s\n", THotel[i].paysHotel);
        printf("Téléphone: %s\n", THotel[i].telHotel);
        printf("Email: %s\n", THotel[i].emailHotel);
        printf("Site Web: %s\n", THotel[i].siteWebHotel);
        printf("Nombre d'étoiles: %u\n", THotel[i].nbrEtoil);
        printf("-----------------------------\n");
    }
}

void SupprimerHotel(unsigned int id)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel à supprimer.\n");
        return;
    }

    for (unsigned int i = 0; i < NBHotel; i++)
    {
        if (THotel[i].idHotel == id)
        {
            // Shift all subsequent hotels to the left
            for (unsigned int j = i; j < NBHotel - 1; j++)
            {
                THotel[j] = THotel[j + 1];
            }

            // Reduce the count and reallocate memory
            NBHotel--;
            THotel = realloc(THotel, NBHotel * sizeof(Hotel));
            if (THotel == NULL && NBHotel > 0)
            {
                printf("Erreur d'allocation mémoire.\n");
            }
            printf("Hôtel ID %u supprimé avec succès.\n", id);
            return;
        }
    }

    printf("Hôtel avec ID %u non trouvé.\n", id);
}

void ModifierHotel(unsigned int id)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel à modifier.\n");
        return;
    }

    for (unsigned int i = 0; i < NBHotel; i++)
    {
        if (THotel[i].idHotel == id)
        {
            printf("Modifier les informations de l'hôtel ID %u:\n", id);

            printf("Nom actuel: %s\n", THotel[i].nomHotel);
            printf("Nouveau nom: ");
            THotel[i].nomHotel = SaisirChaine();

            printf("Adresse actuelle: %s\n", THotel[i].adresseHotel);
            printf("Nouvelle adresse: ");
            THotel[i].adresseHotel = SaisirChaine();

            printf("Ville actuelle: %s\n", THotel[i].villeHotel);
            printf("Nouvelle ville: ");
            THotel[i].villeHotel = SaisirChaine();

            printf("Pays actuel: %s\n", THotel[i].paysHotel);
            printf("Nouveau pays: ");
            THotel[i].paysHotel = SaisirChaine();

            printf("Téléphone actuel: %s\n", THotel[i].telHotel);
            printf("Nouveau téléphone: ");
            THotel[i].telHotel = SaisirChaine();

            printf("Email actuel: %s\n", THotel[i].emailHotel);
            printf("Nouvel email: ");
            THotel[i].emailHotel = SaisirChaine();

            printf("Site Web actuel: %s\n", THotel[i].siteWebHotel);
            printf("Nouveau site web: ");
            THotel[i].siteWebHotel = SaisirChaine();

            printf("Nombre d'étoiles actuel: %u\n", THotel[i].nbrEtoil);
            printf("Nouveau nombre d'étoiles: ");
            scanf("%u", &THotel[i].nbrEtoil);
            getchar();

            printf("Hôtel ID %u modifié avec succès.\n", id);
            return;
        }
    }

    printf("Hôtel avec ID %u non trouvé.\n", id);
}

int compareById(const void *a, const void *b)
{
    return ((Hotel *)a)->idHotel - ((Hotel *)b)->idHotel;
}

int compareByName(const void *a, const void *b)
{
    return strcmp(((Hotel *)a)->nomHotel, ((Hotel *)b)->nomHotel);
}

int compareByCity(const void *a, const void *b)
{
    return strcmp(((Hotel *)a)->villeHotel, ((Hotel *)b)->villeHotel);
}

int compareByCountry(const void *a, const void *b)
{
    return strcmp(((Hotel *)a)->paysHotel, ((Hotel *)b)->paysHotel);
}

void SortHotelsId()
{
    qsort(THotel, NBHotel, sizeof(Hotel), compareById);
    printf("Hôtels triés par ID.\n");
}

void SortHotelsNom()
{
    qsort(THotel, NBHotel, sizeof(Hotel), compareByName);
    printf("Hôtels triés par nom.\n");
}

void SortHotelsVille()
{
    qsort(THotel, NBHotel, sizeof(Hotel), compareByCity);
    printf("Hôtels triés par ville.\n");
}

void SortHotelsPays()
{
    qsort(THotel, NBHotel, sizeof(Hotel), compareByCountry);
    printf("Hôtels triés par pays.\n");
}

void RechercherHotelParNom(const char *nom)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    for (unsigned int i = 0; i < NBHotel; i++)
    {
        if (strcmp(THotel[i].nomHotel, nom) == 0)
        {
            printf("-----------------------------\n");
            printf("Hôtel trouvé :\n");
            printf("ID: %u\n", THotel[i].idHotel);
            printf("Nom: %s\n", THotel[i].nomHotel);
            printf("Adresse: %s\n", THotel[i].adresseHotel);
            printf("Ville: %s\n", THotel[i].villeHotel);
            printf("Pays: %s\n", THotel[i].paysHotel);
            printf("Téléphone: %s\n", THotel[i].telHotel);
            printf("Email: %s\n", THotel[i].emailHotel);
            printf("Site Web: %s\n", THotel[i].siteWebHotel);
            printf("Nombre d'étoiles: %u\n", THotel[i].nbrEtoil);
            printf("-----------------------------\n");
            return;
        }
    }
    printf("Aucun hôtel trouvé avec le nom %s.\n", nom);
}

void AfficherHotelsParVille(const char *ville)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    int found = 0;
    for (unsigned int i = 0; i < NBHotel; i++)
    {
        if (strcmp(THotel[i].villeHotel, ville) == 0)
        {
            printf("-----------------------------\n");
            printf("Hôtel ID: %u\n", THotel[i].idHotel);
            printf("Nom: %s\n", THotel[i].nomHotel);
            printf("Adresse: %s\n", THotel[i].adresseHotel);
            printf("Ville: %s\n", THotel[i].villeHotel);
            printf("Pays: %s\n", THotel[i].paysHotel);
            printf("Téléphone: %s\n", THotel[i].telHotel);
            printf("Email: %s\n", THotel[i].emailHotel);
            printf("Site Web: %s\n", THotel[i].siteWebHotel);
            printf("Nombre d'étoiles: %u\n", THotel[i].nbrEtoil);
            printf("-----------------------------\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("Aucun hôtel trouvé dans la ville %s.\n", ville);
    }
}

void AfficherHotelsParEtoiles(unsigned int etoiles)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    int found = 0;
    for (unsigned int i = 0; i < NBHotel; i++)
    {
        if (THotel[i].nbrEtoil == etoiles)
        {
            printf("-----------------------------\n");
            printf("Hôtel ID: %u\n", THotel[i].idHotel);
            printf("Nom: %s\n", THotel[i].nomHotel);
            printf("Adresse: %s\n", THotel[i].adresseHotel);
            printf("Ville: %s\n", THotel[i].villeHotel);
            printf("Pays: %s\n", THotel[i].paysHotel);
            printf("Téléphone: %s\n", THotel[i].telHotel);
            printf("Email: %s\n", THotel[i].emailHotel);
            printf("Site Web: %s\n", THotel[i].siteWebHotel);
            printf("Nombre d'étoiles: %u\n", THotel[i].nbrEtoil);
            printf("-----------------------------\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("Aucun hôtel trouvé avec %u étoiles.\n", etoiles);
    }
}

void SauvegarderHotelsDansFichier(const char *nomFichier)
{
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL)
    {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    for (unsigned int i = 0; i < NBHotel; i++)
    {
        // Save the data in the format: id$nom$adresse$ville$pays$tel$email$siteWeb$nbrEtoiles
        fprintf(fichier, "%u$%s$%s$%s$%s$%s$%s$%s$%u\n",
                THotel[i].idHotel,
                THotel[i].nomHotel,
                THotel[i].adresseHotel,
                THotel[i].villeHotel,
                THotel[i].paysHotel,
                THotel[i].telHotel,
                THotel[i].emailHotel,
                THotel[i].siteWebHotel,
                THotel[i].nbrEtoil);
    }

    fclose(fichier);
    printf("Données des hôtels sauvegardées avec succès dans %s\n", nomFichier);
}

void Menu_Hotel()
{
    unsigned int choice, id, etoiles;
    char nom[100], ville[100];
    ChargerHotelsDepuisFichier("data_hotel");

    do
    {
        printf("\n--- Menu Hôtel ---\n");
        printf("1. Ajouter un hôtel\n");
        printf("2. Afficher un hôtel\n");
        printf("3. Afficher tous les hôtels\n");
        printf("4. Supprimer un hôtel\n");
        printf("5. Modifier un hôtel\n");
        printf("6. Trier les hôtels par ID\n");
        printf("7. Trier les hôtels par nom\n");
        printf("8. Trier les hôtels par ville\n");
        printf("9. Trier les hôtels par pays\n");
        printf("10. Rechercher un hôtel par nom\n");
        printf("11. Afficher les hôtels par ville\n");
        printf("12. Afficher les hôtels par étoiles\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%u", &choice);

        switch (choice)
        {
        case 1:
            AjouterHotel();
            break;
        case 2:
            printf("Entrez l'ID de l'hôtel à afficher: ");
            scanf("%u", &id);
            AfficherHotel(id);
            break;
        case 3:
            AfficherHotels();
            break;
        case 4:
            printf("Entrez l'ID de l'hôtel à supprimer: ");
            scanf("%u", &id);
            SupprimerHotel(id);
            break;
        case 5:
            printf("Entrez l'ID de l'hôtel à modifier: ");
            scanf("%u", &id);
            ModifierHotel(id);
            break;
        case 6:
            SortHotelsId();
            break;
        case 7:
            SortHotelsNom();
            break;
        case 8:
            SortHotelsVille();
            break;
        case 9:
            SortHotelsPays();
            break;
        case 10:
            printf("Entrez le nom de l'hôtel à rechercher: ");
            scanf("%s", nom);
            RechercherHotelParNom(nom);
            break;
        case 11:
            printf("Entrez la ville: ");
            scanf("%s", ville);
            AfficherHotelsParVille(ville);
            break;
        case 12:
            printf("Entrez le nombre d'étoiles: ");
            scanf("%u", &etoiles);
            AfficherHotelsParEtoiles(etoiles);
            break;
        case 0:
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choice != 0);
}
