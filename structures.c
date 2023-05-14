#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nom[50];
    int ref;
    int quant;
    float prix;
    int taille;//0=petit, 1=moyen, 2=grand
}Produit;

typedef struct {
    int heure;
    int minute;
    int seconde;
}Heure;

typedef struct{
    int jour;
    int mois;
    int annee;
}Date;


typedef struct{
    Produit p;
    Date d;
    Heure h;
}Historique;

typedef struct{
    char nom[25];
    char prenom[25];
    Historique histo;
}Client;