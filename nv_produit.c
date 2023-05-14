#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structures.c"
#include "tests.c"

Produit nv_produit(){
        int verif=0;
        Produit a;
        printf("Enter the name of the product: \n");
        scanf("%s",a.nom);
        printf("Enter the reference of the product: \n");
        verif=scanf("%d",&a.ref);
        while((verif=!1)||(a.ref<1000)){
          printf("The reference has to be between 1000 and 9999 includes.\n");
          printf("Enter the reference: \n");
          verif=scanf("%d",&a.ref);
        }

          
        verif=0;
        
        printf("Enter the quantity to add: \n");
        verif=scanf("%d",&a.quant);
        while((verif=!1)||(a.quant<1)||(a.quant>15)){
          printf("The quantity has to be between 1 and 15\n");
          printf("Enter the quantity to add: \n");
          verif=scanf("%d",&a.quant);
        }
        verif=0;
        printf("How much costs the car ?\n");
        verif=scanf("%f",&a.prix);
        while((verif=!1)||(a.prix<500)){
          printf("Too cheap ! The car must be at 500€ minimum\n");
          printf("How much costs the car ?\n");
          verif=scanf("%f",&a.prix);
        }
        verif=0;
        printf("What is the object's size ?(0=Sportive, 1=City-dweller car, 2=SUV)\n");
        verif=scanf("%d",&a.taille);
        while((verif=!1)||(a.taille<0)||(a.taille>2)){
          printf("You have to chose between the numbers 0, 1 and 2");
          printf("What is the object's size ?(0=Sportive, 1=City-dweller car, 2=SUV)\n");
          verif=scanf("%d",&a.taille);
          
        }
        }

