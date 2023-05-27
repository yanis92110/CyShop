#include "header.h"
#define MAX_CLIENTS 100
#define MAX_STOCK 100


int main() {
    int choix;
    
    // Affichage du menu d'accueil
    printf("------------------------------\n");
    message();
    printf("------------------------------\n\n");
    printf("Appuyez sur n'importe quelle touche pour continuer...\n");
    clearTerminal();

    
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
                main_gp_buyer2();
                break;
            case 2:
                main_manager();
                break;
            case 3:
                printf("Merci d'avoir utilisé notre concession de voitures. Au revoir !\n");
                break;
            default:

                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
                break;
        }

        printf("\nAppuyez sur n'importe quelle touche pour continuer...\n");
        clearTerminal();
    } while (choix != 3);
    return 0;
}

