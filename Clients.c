#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Clients.h"
#include"Chaine.h"



static unsigned int NB_Client = 0 ; 
static unsigned int CClient= 0 ; 
static Client * TClient = NULL ;

static Client * DL = NULL ; 
static Client * FL = NULL ;


void AfficherClient(Client * clt) 
{ 
    if(clt != NULL) 
    { 
        printf("\n=> Code\t\t : %u", clt->id_Client) ; 
        printf("\n=> Nom\t\t : %s", clt->Nom) ; 
        printf("\n=> Prenom\t : %s", clt->Prenom) ; 
        printf("\n=> Email\t : %s", clt->Email) ; 
        printf("\n=> Adresse\t : %s", clt->Adresse) ; 
        printf("\n=> Nationalite\t : %s", clt->Nationalite) ; 
        printf("\n=> Code_Postale\t : %d", clt->Code_Postale) ; 
        printf("\n=> Ville_Client\t : %s", clt->Ville_Client) ; 
        printf("\n=> Date Naissance : %02u/%02u/%4u", clt->Date_Naissance.j, clt->Date_Naissance.m, clt->Date_Naissance.a);
        printf("\n-------------------------------") ;            
    } 
    else 
    { 
        printf("\n Le client n'existe pas ou liste vide !!!") ; 
    }        
} 

void AfficherClients() 
{ 
    Client * clt = DL ; 
    printf("\n\n---------------liste des clients----------------\n\n");
    while(clt != NULL) 
    { 
        AfficherClient(clt) ; 
        clt = clt->suivant ;     
    }
	printf("\n\n---------------Fin de la liste----------------\n\n");    
} 

void SaisirClient(Client * clt) 
{ 
    if(clt != NULL) 
    { 
        clt->id_Client = ++CClient ; 
        printf("\n=> Saisir le nom du client : ") ; 
        clt->Nom = SaisirChaine() ; 

        printf("\n=> Saisir le prenom du client : ") ; 
        clt->Prenom = SaisirChaine() ; 

        printf("\n=> Saisir l Email du client : ") ; 
        clt->Email = SaisirChaine() ; 

        printf("\n=> Saisir l Adresse du client : ") ; 
        clt->Adresse = SaisirChaine() ; 

        printf("\n=> Saisir la Nationalite du client : ") ; 
        clt->Nationalite = SaisirChaine() ; 

        printf("\n=> Saisir le Code Postale du client : ") ; 
        scanf("%d",&(clt->Code_Postale));
        getchar();

        printf("\n=> Saisir la Ville du client : ") ; 
        clt->Ville_Client = SaisirChaine() ;

        printf("\n\t Saisir la date de naissance jj/mm/aaaa : ") ; 
        scanf("%u/%u/%u", &(clt->Date_Naissance.j), &(clt->Date_Naissance.m), &(clt->Date_Naissance.a)) ; 
    } 
} 

void AjouterClientDL() 
{ 
    Client * clt = malloc(sizeof(Client)) ; 
    if(clt == NULL) 
    { 
        printf("\n Barrette memoire saturee !!!") ; 
        return ; 
    } 
    SaisirClient(clt) ; 
    clt->suivant = DL ; 
    DL = clt ; 
    if(FL == NULL) 
    { 
        FL = clt ; 
    } 
} 

void AjouterClientFL() 
{ 
    Client * clt = malloc(sizeof(Client)) ; 
    if(clt == NULL) 
    { 
        printf("\n Barrette memoire saturee !!!") ; 
        return ; 
    } 
    SaisirClient(clt) ; 
    clt->suivant = NULL ; 
    if(FL != NULL) 
    { 
        FL->suivant = clt ;  
    } 
    else 
    { 
        DL = clt ;   
    } 
    FL = clt ; 
} 

Client * AdresseClient(unsigned int code, Client ** pre) 
{ 
    Client * clt = DL ; 
     
    while((clt != NULL) && (clt->id_Client != code)) 
    { 
        *pre = clt ; 
        clt = clt->suivant ;     
    } 
    return clt ;
} 

void SupprimerClient(unsigned int code) 
{ 
    Client * clt, * pre ; 
    clt = AdresseClient(code, &pre) ; 
    if(clt == NULL) 
    { 
        printf("\n Le client n'existe pas dans la liste !!!") ; 
        return ; 
    } 
    if((clt == DL) && (clt == FL)) 
    { 
        DL = NULL ; 
        FL = NULL ; 
    } 
    else if(clt == DL) 
    { 
        DL = DL->suivant ; 
    } 
    else if(clt == FL) 
    { 
        pre->suivant = NULL ; 
        FL = pre ; 
    } 
    else 
    { 
        pre->suivant = clt->suivant ;    
    } 
    printf("\nle client %d a ete supprimer!\n",clt->id_Client);
    free(clt->Nom) ; 
    free(clt->Prenom) ; 
    free(clt->Email) ; 
    free(clt->Adresse) ; 
    free(clt->Nationalite) ; 
    free(clt->Ville_Client) ; 
    free(clt) ; 
} 

void ModifierClient(int code)
{
	Client* u, *pre;
	u = AdresseClient(code, &pre) ; 

	printf("\n=> Saisir le nom du client : ") ; 
    u->Nom = SaisirChaine() ; 

    printf("\n=> Saisir le prenom du client : ") ;
    u->Prenom = SaisirChaine() ; 

    printf("\n=> Saisir l Email du client : ") ; 
    u->Email = SaisirChaine() ; 

    printf("\n=> Saisir l Adresse du client : ") ; 
    u->Adresse = SaisirChaine() ; 

    printf("\n=> Saisir la Nationalite du client : ") ; 
    u->Nationalite = SaisirChaine() ; 

    printf("\n=> Saisir le Code Postale du client : ") ; 
    scanf("%d",&(u->Code_Postale));
    getchar();

    printf("\n=> Saisir la Ville du client : ") ; 
    u->Ville_Client = SaisirChaine() ;

    printf("\n\t Saisir la date de naissance jj/mm/aaaa : ") ; 
    scanf("%u/%u/%u", &(u->Date_Naissance.j), &(u->Date_Naissance.m), &(u->Date_Naissance.a)) ;
}

void sauvegarder_LSC() {
    FILE *pf = fopen("client_data.txt", "w");

    if (pf == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    int i;
    Client *u;
    for (u = DL ; u->suivant != NULL ; u = u->suivant) {
        fprintf(pf, "%d#%s#%s#%s#%s#%s#%d#%s#%u/%u/%u\n", u->id_Client, u->Nom, u->Prenom, u->Email, u->Adresse, u->Nationalite, u->Code_Postale, u->Ville_Client, u->Date_Naissance.j, u->Date_Naissance.m, u->Date_Naissance.a);
    }
	fprintf(pf, "%d#%s#%s#%s#%s#%s#%d#%s#%u/%u/%u", u->id_Client, u->Nom, u->Prenom, u->Email, u->Adresse, u->Nationalite, u->Code_Postale, u->Ville_Client, u->Date_Naissance.j, u->Date_Naissance.m, u->Date_Naissance.a);
   

    fclose(pf);
    printf("\nLes donnees ont ete sauvegardees dans le fichier.\n");
}

int is_positive_integer( char *str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }

    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }

    return 1;
}

int verif_file(char *filename) {

    FILE *pf = fopen(filename, "r");
    if (pf == NULL) {
        perror("Error opening file\n");
        return 0;
    }

    char * chaine;
	int i;
    char c = '0';
    int nbc ;
    while (c != EOF)
    {
		//id_client
    	i = 0;
    	
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
            i = 1;
        }
        if(i==0)
        {
        	free(chaine);
        	fclose(pf);
			pf = NULL;
        	return 1;
		}
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        if (!is_positive_integer(chaine)) 
		{
            free(chaine);
            return 0;
        }
        free(chaine);
        
		//nom
        nbc = 0;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            nbc++;
        }
        if (nbc == 0)
        {
           return 0;
        }
        
		//prenom
        nbc = 0;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            nbc++;
        }
        if (nbc == 0)
        {
            return 0;
        }
        
		//email
        nbc = 0;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            nbc++;
        }
        if (nbc == 0)
        {
           return 0;
        }
        
		//adresse
        nbc = 0;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            nbc++;
        }
        if (nbc == 0)
        {
           return 0;
        }
        
		//nationalite
        nbc = 0;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            nbc++;
        }
        if (nbc == 0)
        {
           return 0;
        }
        
		//code_postale
		nbc=0;
		chaine = NULL;
		while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }

        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        if (!is_positive_integer(chaine)) 
		{
            free(chaine);
            return 0;
        }
	        
	    free(chaine);
        
        
		//ville_client
	
	 nbc = 0;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            nbc++;
        }
        if (nbc == 0)
        {
           return 0;
        }
        
		//date_naissace
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        
        if (!IsStrDate(chaine , '/')) {
            free(chaine);
            return 0;
        }
        if(c==EOF)
        {
        	free(chaine);
        	break;
		}
        
        free(chaine);   
		  
    }
    fclose(pf);
    pf = NULL;
	
    return 1;
}

void get_data_file(char * filename) {

    FILE *pf = fopen(filename, "r");

    if (pf == NULL) {
        printf("\nError opening file ");
        return ;
    }


    char * chaine;
    int c = 0;
    int nbc ;
	int i = 0;
    while (c!=EOF)
    {
		//id_client
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
            i = 1;
        }
        if(i==0)
        {
        	printf("\nfichier vide !!!!!");
        	return;
		}
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
		
        int id_client = atoi(chaine);
        free(chaine);
        if(id_client>CClient)
        {
            CClient=id_client;
        }
		//nom
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        char * nom = chaine;
		//prenom
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        char * prenom = chaine;
		//email
		nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        char * email = chaine;
		//adresse  
		nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        char * adresse = chaine;
		//nationalite
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        char * nationalite = chaine;
		//code_postale
		nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
		
        int code_postale = atoi(chaine);
        free(chaine);
		
		//ville_client
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        char * ville_client = chaine;
        
		//date_naissance
        nbc = 0;
        chaine = NULL;
        while (((c= fgetc(pf))!= '\n') && (c != EOF) && (c != '#') )
        {
            chaine = realloc(chaine, (nbc+1)*sizeof(char));
            chaine[nbc++] = c;
        }
        
        if (nbc > 0)
        {
            chaine = realloc(chaine,(nbc+1)*sizeof(char));
            chaine[nbc] = '\0';
        }
        
        Date date_naissance = Str_Date(chaine);
        
        free(chaine);
        
    	Client * clt = malloc(sizeof(Client)) ;
		if(clt == NULL) 
    	{ 
        	printf("\n Barrette mémoire saturée !!!") ; 
        	return ; 
    	}
    	clt->id_Client = id_client;
        clt->Nom = nom;
        clt->Prenom = prenom;
        clt->Email=email;
        clt->Adresse=adresse;
        clt->Nationalite=nationalite;
        clt->Code_Postale=code_postale;
        clt->Ville_Client=ville_client;
        clt->Date_Naissance = date_naissance;
		clt->suivant = NULL ;
		
		if(FL != NULL) 
    	{ 
    		FL->suivant = clt ;  
		} 
		else 
		{ 
			DL = clt ;   
		} 
		FL = clt ;	
		if(c == EOF)
		{
			printf("\n------------Fin d'importation des donnees !!!-------------\n\n\n");
			break;
		}
	}

    fclose(pf);
    pf = NULL;
    
}


void Menu_Client()
{
	
	int choix = -1;
    int code;
    
    while (choix != 0)
    {
		printf("\n----------------Le menu de la table des Clients----------------\n");
        printf("\n 0/  Quitter le programme");
        printf("\n 1/  afficher la liste des clients");
        printf("\n 2/  Ajouter un client au bedut de la liste");
        printf("\n 3/  Ajouter un client a la fin de la liste");
        printf("\n 4/  supprimer un client");
        printf("\n 5/  modifier un client");
        printf("\n 6/  sauvgarder la liste des clients");
        printf("\n 7/  verification des donnes du fichier txt");
        printf("\n 8/  importation des donnees des clients");
        
        printf("\n\t Saisir votre choix [0, 8] : ");
        scanf("%d", &choix);
        getchar();

        switch (choix)
        {
	        case 0:
	            printf("\n Sortie du programme");
				exit(0);
	        case 1:
	            AfficherClients();
	            break;
	        case 2:
	            AjouterClientDL();
	            break;
	        case 3:
	            AjouterClientFL();
	            break;
	        case 4:
	        	printf("\nEntrer id client a supprimer \n");
	        	scanf("%d",&code);
	        	getchar();
	            SupprimerClient(code);
	            break;
	        case 5:
	        	printf("\nEntrer id client a modifier \n");
	        	scanf("%d",&code);
	        	getchar();
	            ModifierClient(code);
	            break;
	        case 6:
	            sauvegarder_LSC() ;
	            break;
	        case 7:
	        	if(verif_file("client_data.txt"))
	        	{
	        		printf("\n============> les donnees du fichier sont valide\n\n");
				}
				else
				{
					printf("\n============>le format des donnees du fichier sont invalide\n\n");
				}
	        	
	        	break;
	        case 8:
	        	if(verif_file("client_data.txt"))
	        	{
	        		printf("\n=============>les donnees du fichier sont valide\n\n");
		        	get_data_file("client_data.txt");
				}
				else
				{
					printf("\n=============>le format des donnees du fichier sont invalide\n\n");
				}
	        	break;
	        default:
	            printf("\n Saisir une option entre 0 et 8\n");
	            break;
        }
	}
}

