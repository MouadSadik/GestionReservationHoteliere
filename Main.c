#include <stdio.h>
#include<stdlib.h>
#include"Reservation.h"




void Menu_General()
{
	
	int choix = -1;
    int code;
    
    while (choix != 0)
    {
		printf("\n----------------Le menu general----------------\n");
        printf("\n 0/  Quitter le programme");
        printf("\n 1/  Ajuster la table des clients");
        printf("\n 2/  Ajuster la table des chambres");
        printf("\n 3/  Ajuster la table des hotels");
        printf("\n 4/  Ajuster la table des factures");
        printf("\n 5/  Ajuster la table des reservations");
        printf("\n 6/  Ajuster la table des avis");
        printf("\n 7/  Ajuster la table des nourritures");
        printf("\n 8/  Ajuster la table des cccccccc");
        printf("\n 9/  Ajuster la table des cccccccc");
        
        printf("\n\t Saisir votre choix [0, 6] : ");
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
	        case 0:
	            printf("\n Sortie du programme");
				exit(0);
	        case 1:
	            //Menu_Clients();
	            break;
	        case 2:
	            //Menu_Chambres();
	            break;
	        case 3:
	           // Menu_Hotels();
	            break;
	        case 4:
				Menu_Facture();
	            break;
	        case 5:
				Menu_Res();
	            break;
	        case 6:
	            //Menu_Avis() ;
	            break;
	        case 7:
	        	//Menu_Nourritures();
	        	break;
	        default:
	            printf("\n Saisir une option entre 0 et 6\n");
	            break;
        }
}
}



int main()
{
	printf("\nBienvenu dans le system de gestion hoteuliere\n");
	
	
	return 0;
	
}