#include "header.h"
#include <ncurses.h>
#define MAX_CLIENTS 100
#define MAX_STOCK 100


int main() {
    int choix;
    
    // Initialisation de ncurses
    initscr();
    clear();
    noecho();
    cbreak();
    
    // Affichage du menu d'accueil
    printw("------------------------------\n");
    message();
    printw("------------------------------\n\n");
    printw("Appuyez sur n'importe quelle touche pour continuer...\n");
    refresh();
    getch();
    clear();
    
    do {
        printw("----- Cy ShopShop -----\n");
        printw("\n");
        printw("You can choose between 2 modes:\n");
        printw("\n");
        printw("1. Buyer mode\n");
        printw("    -You are a buyer, you can look at the cars stock and command some vehicles.\n");
        printw("\n");
        printw("2. Manager mode\n");
        printw("     -You are the manager of the Cy ShopShop; you have write access on the cars stock and the client folder.\n");
        printw("\n");
        printw("3. Leave\n");
        printw("Choice : ");
        refresh();
        
        echo();
        scanw("%d", &choix);
        noecho();
        
        switch (choix) {
            case 1:
                clear();
                main_gp_buyer2();
                break;
            case 2:
                clear();
                main_manager();
                break;
            case 3:
                clear();
                printw("Merci d'avoir utilisé notre concession de voitures. Au revoir !\n");
                break;
            default:
                clear();
                printw("Choix invalide. Veuillez sélectionner une option valide.\n");
                break;
        }

        printw("\nAppuyez sur n'importe quelle touche pour continuer...\n");
        refresh();
        getch();
        clear();
    } while (choix != 3);

    // Restauration des paramètres du terminal
    endwin();

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