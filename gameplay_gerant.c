#include <stdio.h>
#include "structures.c"

int main() {
    int verif=0;
    char tab[3];
    char oui[3]="oui";
    char non[3]="non";
    //commande qui met tout en minuscule poru table ascii
    while ((strcmp(tab,"oui") != 0) && (strcmp(tab,"non") != 0) && (verif != 3)){
        printf("Hello, do you have some new cars to add AU STOCK?"\n");
        verif = scanf("%s",tab);
    }
    if(strcmp(tab,"oui")){
      printf("What is the brand of the car you want to add ?\n");
      verif=scanf("%s",& STOCK DE LA VOITURE);
      //si la marque n'est pas enregistrée, l'ajouter
      printf("What is the model of the car ?\n");
     
      verif=scanf("%s",& STOCK DE LA VOITURE);
	     //pareil
      printf("How many car do you want do command ?\n");
	  verif=scanf("%d",& STOCK DE LA VOITURE);
      while((verif!=1)&&(& STOCK DE LA VOITURE<1)(& STOCK DE LA VOITURE>50)){  //50 valeur arbitraire
        printf("You have to enter a number between 1 and 50\n");
        printf("How many car do you want do command ?\n");
        verif=scanf("%d"& STOCK DE LA VOITURE);
      }
    }
    printf("How ");
    verif=scanf("%s\n");
  
  
    while(verif!=1){
      printf("You have to enter a valid number (between 1 and 50)");
      printf("Enter how ")
    }
  
}

