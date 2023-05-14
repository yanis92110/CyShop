#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structures.c"

Client creer_client(){
    int verif=0;
    Client a;
    printf("nom ?\n");
    scanf("%s", a.nom);
    printf("prénom ?\n");
    scanf("%s", a.prenom);
    char tab[3];
    char oui[3]="oui";
    char non[3]="non";
    while ((strcmp(tab,"oui") != 0) && (strcmp(tab,"non") != 0) && (verif != 3)){
        printf("Avez-vous déjà acheté dans notre boutique(repondre oui ou non) ?\n");
        verif = scanf("%s",tab);
    }
    if (tab=="oui"){
        //importer historique 
    }
    else if (tab=="non"){
        //creer fichier historique pour ce client
    }
    return a;

}
int main(){
    FILE *source = fopen("structures.c", "rb");
    FILE *destination = fopen("creer_client.c", "wb");
     if (source == NULL || destination == NULL) { 
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return 1;
    }
    Client client;
    while (!feof(source) && fread(&client, sizeof(client), 1, source)) { 
        fwrite(&client, sizeof(client), 1, destination);  
    }
     fclose(source); 
    fclose(destination); 
    client=creer_client();
}