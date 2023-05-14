#include <stdio.h>
#include <stdlib.h>


//FICHIER POUR TESTER LES CONDITIONS ET FONCTIONS

int testInt(int a){
  if (typeof(a)!= typeof(int)){
    printf("Vous n'avez pas entrer d'entier.");
    return -1;
  }
  else{
    return 1;
  }
}