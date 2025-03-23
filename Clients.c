#include<stdio.h>
#include<stdlib.h>
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
        printf("\n=> Prénom\t : %s", clt->Prenom) ; 
        printf("\n=> Email\t : %s", clt->Email) ; 
        printf("\n=> Adresse\t : %s", clt->Adresse) ; 
        printf("\n=> Nationalite\t : %s", clt->Nationalite) ; 
        printf("\n=> Code_Postale\t : %s", clt->Code_Postale) ; 
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
     
    while(clt != NULL) 
    { 
        AfficherClient(clt) ; 
        clt = clt->suivant ;     
    }    
} 

void SaisirClient(Client * clt) 
{ 
    if(clt != NULL) 
    { 
        clt->id_Client = ++CClient ; 
        printf("\n=> Saisir le nom du client : ") ; 
        clt->Nom = SaisirChaine() ; 

        printf("\n=> Saisir le prénom du client : ") ; 
        clt->Prenom = SaisirChaine() ; 

        printf("\n=> Saisir l'Email du client : ") ; 
        clt->Email = SaisirChaine() ; 

        printf("\n=> Saisir l'Adresse du client : ") ; 
        clt->Adresse = SaisirChaine() ; 

        printf("\n=> Saisir la Nationalite du client : ") ; 
        clt->Nationalite = SaisirChaine() ; 

        printf("\n=> Saisir le Code Postale du client : ") ; 
        scanf("%d",clt->Code_Postale);

        printf("\n\t Saisir la date de naissance jj/mm/aaaa : ") ; 
        scanf("%u/%u/%u", &(clt->Date_Naissance.j), &(clt->Date_Naissance.m), &(clt->Date_Naissance.a)) ; 
    } 
} 

void AjouterClientDL() 
{ 
    Client * clt = malloc(sizeof(Client)) ; 
    if(clt == NULL) 
    { 
        printf("\n Barrette mémoire saturée !!!") ; 
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
        printf("\n Barrette mémoire saturée !!!") ; 
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

    printf("\n=> Saisir le prénom du client : ") ;
    u->Prenom = SaisirChaine() ; 

    printf("\n=> Saisir l'Email du client : ") ; 
    u->Email = SaisirChaine() ; 

    printf("\n=> Saisir l'Adresse du client : ") ; 
    u->Adresse = SaisirChaine() ; 

    printf("\n=> Saisir la Nationalite du client : ") ; 
    u->Nationalite = SaisirChaine() ; 

    printf("\n=> Saisir le Code Postale du client : ") ; 
    scanf("%d",u->Code_Postale);

    printf("\n\t Saisir la date de naissance jj/mm/aaaa : ") ; 
    scanf("%u/%u/%u", &(u->Date_Naissance.j), &(u->Date_Naissance.m), &(u->Date_Naissance.a)) ;
}


