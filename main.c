#include "header.h"
#define MAX_CLIENTS 100
#define MAX_STOCK 100


int main() {
    int choix;

    message();

    do {
        printf("----- Cy ShopShop -----\n");
        printf("\n");
        printf("You can choose between 2 modes:\n");
        printf("\n");
        printf("1. Buyer mode\n");
        printf("    -You are a buyer, you can look at the cars stock and command some vehicles.\n");
        printf("\n");
        printf("2. Manager mode\n");
        printf("     -You are the manager of the Cy ShopShop; you have write access on the cars stock and the client folder.\n");
        printf("\n");
        printf("3. Leave\n");
        printf("Choice : ");
        
        

        scanf("%d", &choix);

        
        switch (choix) {
            case 1:
                clearTerminal();
                main_gp_buyer2();
                break;
            case 2:
                clearTerminal();
                main_manager();
                break;
            case 3:
                clearTerminal();
                printf("Merci d'avoir utilisé notre concession de voitures. Au revoir !\n");
                sleep(1);
                break;
            default:
                clearTerminal();
                printf("=============================================\n");
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
                sleep(2);
                clearTerminal();
                break;
        }
        

    } while (choix != 3);


    return 0;
}


/*int main() {
    message();
    printf("Welcome to CyShopShop !\n");
    printf("There are 2 modes:\n");
    printf("-Manager mode: You have access to the stock, the clients folder and you can command cars.\n");
  printf("===============================================\n");
  printf("-Buyer mode: You are a consumer and you can purchase cars on our shop.\n");

  int verif=0;
  char choose[10];
  do{
    printf("Which mode do you want to play ? (type 'buyer' or 'manager'\n");
    verif=scanf("%s",choose);
    testInt(choose);
    convertMin(choose);
  }while((verif!=1) || (strcmp(choose, "buyer") != 0 && strcmp(choose, "manager") != 0));
  if(strcmp(choose,"buyer")==0){
    printf("You have chosen the buyer mode, have fun !\n");
    sleep(1);
    main_gp_buyer2();
  }
  else if(strcmp(choose,"manager")==0){
    printf("You have chosen the manager mode, have fun !\n");
    sleep(2);
    main_manager();
  }
return 0;
}*/