#include<stdio.h>
#include<Clients.h>

static unsigned int NBC = 0 ; // Variable globale : Compteur de clients devant �tre auto-incr�ment� 
static unsigned int CC = 0 ; // Cle primaire de la structure Client
static Client * TC = NULL ; // Variable globale : Pointeur pour creer un tableau dynamique de clients
