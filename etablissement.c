#include "etablissement.h"
#include<string.h>
//ajouuuuuuuuuuuuut
int ajouter(char * filename , etab e ){
int v1,v2,v3,v4,i;
FILE * f=fopen(filename, "r+");
 if(f!=NULL)
    {
  //deja existe ou non
etab p;
        rewind(f); // Rembobiner le fichier à la position de départ
        while (fscanf(f, "%s %s %s %s %s %s\n", p.nom_etablissement, p.region, p.capacite, p.adress, p.numero, p.responsable) != EOF) {
            if (strcmp(p.nom_etablissement, e.nom_etablissement) == 0) {
                fclose(f);
                return -2; // L'enregistrement existe déjà
            }
        }
     // controle du nom etablissement 
v1=1;
i=0;
if(strlen(e.nom_etablissement)!=0){
while(i<strlen(e.nom_etablissement)&&v1==1){
if(e.nom_etablissement[i]<'a'||'z'<e.nom_etablissement[i])
{v1=0;}
i++;
}}else v1=0;
    //controle saisie region 
v2=1;
i=0;
if(strlen(e.region)!=0){
while(i<strlen(e.region)&&v2==1){ 
if(e.region[i]<'a'||'z'<e.region[i])
{v2=0;}
i++;
}}else v2=0;
    //controle saisie numero
v3=1,i=0;
if(strlen(e.numero)==8)
{
while(i<strlen(e.numero)&&v3==1){
if(e.numero[i]<'0'||'9'<e.numero[i])
{v3=0;}
i++;
}
}else{v3=0;}
   //controle du saisie responsable 
v4=1;
i=0;
if(strlen(e.region)!=0){
while(i<strlen(e.region)&&v4==1){ 
if(e.responsable[i]<'a'||'z'<e.responsable[i])
{v4=0;}
i++;
}}else v4=0;
    //enregistrement dans le fichier ou erreur 
       if(v1==1&&v2==1&&v3==1&&v4==1){
        fprintf(f,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable);
        fclose(f);
        return 1;}
                 else return -1;
    }
    else return 0;
}

//modifiiiiiiiiiiiiiier
int modifier( char * filename, char * id, etab  nouv )
{
    int tr=0;
    etab p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable)!=EOF)
        {
            if(strcmp(p.nom_etablissement,id)==0)
            {
 
   //meme controle de saisie
int v1,v2,v3,v4,i;
   // controle du nom etablissement 
v1=1;
i=0;
if(strlen(nouv.nom_etablissement)!=0){
while(i<strlen(nouv.nom_etablissement)&&v1==1){
if(nouv.nom_etablissement[i]<'a'||'z'<nouv.nom_etablissement[i])
{v1=0;}
i++;
}}else v1=0;
   //controle saisie region 
v2=1;
i=0;
if(strlen(nouv.region)!=0){
while(i<strlen(nouv.region)&&v2==1){ 
if(nouv.region[i]<'a'||'z'<nouv.region[i])
{v2=0;}
i++;
}}else v2=0;
   //controle saisie numero
v3=1,i=0;
if(strlen(p.numero)==8)
{
while(i<strlen(p.numero)&&v3==1){
if(p.numero[i]<'0'||'9'<p.numero[i])
{v3=0;}
i++;
}
}else{v3=0;}
  //controle du saisie responsable 
v4=1;
i=0;
if(strlen(nouv.responsable)!=0){
while(i<strlen(nouv.responsable)&&v4==1){ 
if(nouv.responsable[i]<'a'||'z'<nouv.responsable[i])
{v4=0;}
i++;
}}else v4=0;
//ecrire dans le fichier
        if(v1==1&&v2==1&&v3==1&&v4==1){
                fprintf(f2,"%s %s %s %s %s %s\n",nouv.nom_etablissement,nouv.region,nouv.capacite,nouv.adress,nouv.numero,nouv.responsable);
                tr=1;}
                     else return(-1);//si la return -1 erreur cause par le saisie  si return 0  erreur causer par fichier 
            }
            else
                fprintf(f2,"%s %s %s %s %s %s\n",p.nom_etablissement,p.region,p.capacite,p.adress,p.numero,p.responsable);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
//suuuuuuuuuprimer
int supprimer(char * filename, char *id)
{
    int tr=0;
    etab e;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable)!=EOF)
        {
            if(strcmp(e.nom_etablissement ,id)==0)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
//chercher 
etab chercher(char * filename, char * id)
{ 
    etab e;
    int tr;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s\n",e.nom_etablissement,e.region,e.capacite,e.adress,e.numero,e.responsable)!=EOF)
        {
            if(strcmp(e.nom_etablissement, id)==0)
                tr=1;// 1 si on trrouve la valeur 
        }
    }
    fclose(f);
    if(tr==0)
       strcpy( e.numero,"-1");
    return e;
}
