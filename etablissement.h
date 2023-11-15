#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
typedef struct etablissement{
char nom_etablissement[20];
char region[20];
char capacite[20];
char adress[20];
char numero[20];
char responsable[20];}etab;

int ajouter(char *, etab );
int modifier( char *, char *, etab );
int supprimer(char *, char * );
etab chercher(char *, char *);
#endif
