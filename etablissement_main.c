#include<stdio.h>
#include<string.h>
#include"etablissement.h"
void main(){
  etab e,e1,p3;

strcpy(e.nom_etablissement,"sirayen");
strcpy(e.region,"tun");
strcpy(e.capacite,"50");
strcpy(e.adress,"wddj52");
strcpy(e.numero,"05555554");
strcpy(e.responsable,"rayen");

strcpy(e1.nom_etablissement,"tp");
strcpy(e1.region,"benarous");
strcpy(e1.capacite,"505");
strcpy(e1.adress,"efg54rf");
strcpy(e1.numero,"20809891");
strcpy(e1.responsable,"rayenn");



int x= ajouter("etablissement.txt",e);
 if (x == 1) {
        printf("Ajout de point avec succès\n");
    } else if (x == -1) {
        printf("Erreur causée par la saisie\n");
    } else if(x==-2){
printf("le nom de l etablissement deja existe  \n");
}
else  {
        printf("Erreur causée par le fichier\n");
    }

/*int x=modifier("etablissement.txt","rayen",e1);
printf("%d",x);

    if(x==1)
        printf("\nModification de point avec succés");
    else printf("\nechec Modification");
 /*int   x=supprimer("etablissement.txt","20809891" );
    if(x==1)
        printf("\nSuppression de point avec succés");
    else printf("\nechec Suppression");*/
 /*  p3=chercher("etablissement.txt","20809890" );
    if(p3.numero=="-1")
        printf("introuvable");
    else printf("bien trouver");*/
    


}
