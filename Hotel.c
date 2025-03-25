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
        NBHotel++;
        Hotel *temp = realloc(THotel, NBHotel * sizeof(Hotel));
        if (temp == NULL)
        {
            printf("Erreur d'allocation mémoire.\n");
            fclose(file);
            return;
        }
        THotel = temp;

        char *token = strtok(line, "$");
        if (token) THotel[NBHotel - 1].idHotel = atoi(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].nomHotel = strdup(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].adresseHotel = strdup(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].villeHotel = strdup(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].paysHotel = strdup(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].telHotel = strdup(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].emailHotel = strdup(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].siteWebHotel = strdup(token);

        token = strtok(NULL, "$");
        if (token) THotel[NBHotel - 1].nbrEtoil = atoi(token);
    }

    fclose(file);
    printf("Données des hôtels chargées depuis le fichier %s.\n", filename);
}

void AjouterHotel()
{
    Hotel *temp = realloc(THotel, (NBHotel + 1) * sizeof(Hotel));
    if (temp == NULL)
    {
        printf("Erreur d'allocation mémoire.\n");
        return;
    }
    THotel = temp;
    NBHotel++;

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
    getchar(); // Pour consommer le '\n' restant

    printf("Hôtel ajouté avec succès! ID: %u\n", THotel[NBHotel - 1].idHotel);
}

void AfficherHotel(unsigned int id)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    unsigned int i;
    for (i = 0; i < NBHotel; i++)
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
            return;
        }
    }
    printf("Aucun hôtel trouvé avec l'ID %u.\n", id);
}

void AfficherHotels()
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    unsigned int i;
    for (i = 0; i < NBHotel; i++)
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

    unsigned int i;
    int found = 0;
    for (i = 0; i < NBHotel; i++)
    {
        if (THotel[i].idHotel == id)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Hôtel avec ID %u non trouvé.\n", id);
        return;
    }

    // Libérer la mémoire des chaînes
    free(THotel[i].nomHotel);
    free(THotel[i].adresseHotel);
    free(THotel[i].villeHotel);
    free(THotel[i].paysHotel);
    free(THotel[i].telHotel);
    free(THotel[i].emailHotel);
    free(THotel[i].siteWebHotel);

    // Déplacer les éléments suivants
    for (unsigned int j = i; j < NBHotel - 1; j++)
    {
        THotel[j] = THotel[j + 1];
    }

    NBHotel--;
    if (NBHotel > 0)
    {
        Hotel *temp = realloc(THotel, NBHotel * sizeof(Hotel));
        if (temp != NULL)
        {
            THotel = temp;
        }
    }
    else
    {
        free(THotel);
        THotel = NULL;
    }

    printf("Hôtel ID %u supprimé avec succès.\n", id);
}

void ModifierHotel(unsigned int id)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel à modifier.\n");
        return;
    }

    unsigned int i;
    int found = 0;
    for (i = 0; i < NBHotel; i++)
    {
        if (THotel[i].idHotel == id)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Hôtel avec ID %u non trouvé.\n", id);
        return;
    }

    printf("Modifier les informations de l'hôtel ID %u:\n", id);

    printf("Nom actuel: %s\nNouveau nom: ", THotel[i].nomHotel);
    free(THotel[i].nomHotel);
    THotel[i].nomHotel = SaisirChaine();

    printf("Adresse actuelle: %s\nNouvelle adresse: ", THotel[i].adresseHotel);
    free(THotel[i].adresseHotel);
    THotel[i].adresseHotel = SaisirChaine();

    printf("Ville actuelle: %s\nNouvelle ville: ", THotel[i].villeHotel);
    free(THotel[i].villeHotel);
    THotel[i].villeHotel = SaisirChaine();

    printf("Pays actuel: %s\nNouveau pays: ", THotel[i].paysHotel);
    free(THotel[i].paysHotel);
    THotel[i].paysHotel = SaisirChaine();

    printf("Téléphone actuel: %s\nNouveau téléphone: ", THotel[i].telHotel);
    free(THotel[i].telHotel);
    THotel[i].telHotel = SaisirChaine();

    printf("Email actuel: %s\nNouvel email: ", THotel[i].emailHotel);
    free(THotel[i].emailHotel);
    THotel[i].emailHotel = SaisirChaine();

    printf("Site Web actuel: %s\nNouveau site web: ", THotel[i].siteWebHotel);
    free(THotel[i].siteWebHotel);
    THotel[i].siteWebHotel = SaisirChaine();

    printf("Nombre d'étoiles actuel: %u\nNouveau nombre d'étoiles: ", THotel[i].nbrEtoil);
    scanf("%u", &THotel[i].nbrEtoil);
    getchar();

    printf("Hôtel ID %u modifié avec succès.\n", id);
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

    unsigned int i;
    int found = 0;
    for (i = 0; i < NBHotel; i++)
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
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Aucun hôtel trouvé avec le nom %s.\n", nom);
    }
}

void AfficherHotelsParVille(const char *ville)
{
    if (NBHotel == 0)
    {
        printf("Aucun hôtel enregistré.\n");
        return;
    }

    unsigned int i;
    int found = 0;
    for (i = 0; i < NBHotel; i++)
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

    unsigned int i;
    int found = 0;
    for (i = 0; i < NBHotel; i++)
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

    unsigned int i;
    for (i = 0; i < NBHotel; i++)
    {
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
        getchar(); // Pour consommer le '\n' restant

        switch (choice)
        {
        case 1:
            AjouterHotel();
            break;
        case 2:
            printf("Entrez l'ID de l'hôtel à afficher: ");
            scanf("%u", &id);
            getchar();
            AfficherHotel(id);
            break;
        case 3:
            AfficherHotels();
            break;
        case 4:
            printf("Entrez l'ID de l'hôtel à supprimer: ");
            scanf("%u", &id);
            getchar();
            SupprimerHotel(id);
            break;
        case 5:
            printf("Entrez l'ID de l'hôtel à modifier: ");
            scanf("%u", &id);
            getchar();
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
            fgets(nom, sizeof(nom), stdin);
            nom[strcspn(nom, "\n")] = '\0';
            RechercherHotelParNom(nom);
            break;
        case 11:
            printf("Entrez la ville: ");
            fgets(ville, sizeof(ville), stdin);
            ville[strcspn(ville, "\n")] = '\0';
            AfficherHotelsParVille(ville);
            break;
        case 12:
            printf("Entrez le nombre d'étoiles: ");
            scanf("%u", &etoiles);
            getchar();
            AfficherHotelsParEtoiles(etoiles);
            break;
        case 0:
            SauvegarderHotelsDansFichier("data_hotel");
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choice != 0);
}