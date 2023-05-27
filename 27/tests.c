#include "header.h"


//FICHIER POUR TESTER LES CONDITIONS ET FONCTIONS
void clearTerminal() {
  // Fonction qui réinitialise l'affichage du terminal 
    system("clear");
}
  int testInt(const char* chaine){ 
//Fonction qui prend en parametre une chaine de caractere et qui renvoie 1 si c'est un entier naturel et 0 si non
    
    int i=0;
  //Teste si l'entier est négatif
    if(chaine[i]=='-'){
<<<<<<< HEAD
      printf("Veuillez entrer un nombre positif\n");
=======
      printw("Veuillez entrer un nombre positif\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      return 0;
    }
  //Parcours la chaine et compare chaque caractere pour voir si c'est un chiffre
  while(chaine[i]!='\0'){
    if((chaine[i]<'0')||(chaine[i]>'9')){
      return 0;
    }
    i++;
    }
    return 1;
    }
  void convertMin(char* chain){
  //Fonction qui convertit une chaine de caracteres en minuscule
    int i=0;
    while(chain[i]!='\0'){
      chain[i]=tolower(chain[i]);
      i++;
    }
  }
  void printArrayChar(char* tab){
  //Fonction qui affiche un tableau de caracteres
    int i=0;
    while(tab[i]!='\0'){
<<<<<<< HEAD
      printf("%c",tab[i]);
=======
      printw("%c",tab[i]);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      i++;
    }
  }
  void printArrayInt(int* tab){
  //Fonction qui affiche un tableau d'entiers
    int i=0;
    while(tab[i]!='\0'){
<<<<<<< HEAD
      printf("%d\n",tab[i]);
=======
      printw("%d\n",tab[i]);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      i++;
    }
  }
  void buffer(){
    //Fonction qui vide l'entrée clavier
    int i=0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    //Tant que c est différent du caractere de fin
  }
void createClient(Client client) {
  //Fonction qui créer un client, son "fichier client" et son historique
  char filename[50];

  clearTerminal();

<<<<<<< HEAD
  printf("Enter your name: \n");
  scanf("%s", client.name);

  clearTerminal();

  printf("Enter your surname: \n");
  scanf("%s", client.surname);
=======
  printw("Enter your name: \n");
  scanw("%s", client.name);

  clearTerminal();

  printw("Enter your surname: \n");
  scanw("%s", client.surname);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c

  clearTerminal();

  sprintf(filename, "%s_%s.txt", client.name, client.surname);
  //Change le nom du fichier

  FILE *file = fopen(filename, "w");
  if (file != NULL) {
    //Si le fichier a correctement été crée et ouvert, écrit les infos du client dans le fichier
    fprintf(file, "Name: %s\n", client.name);
    fprintf(file, "Surname: %s\n", client.surname);
    fprintf(file, "ID: %d\n", client.id);
    fprintf(file, "Purchase history:\n");
    fclose(file);
<<<<<<< HEAD
    printf("Client file created: %s\n", filename);
  } 
  else {
    
    printf("Error creating client file.\n");
=======
    printw("Client file created: %s\n", filename);
  } 
  else {
    
    printw("Error creating client file.\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
  }
  char filenamehistoric[50];
  sprintf(filenamehistoric, "%s.%s.historic.txt", client.name, client.surname);
  FILE* filehistoric=fopen(filenamehistoric,"r");
  if(filehistoric!=NULL){
<<<<<<< HEAD
    printf("Historic file was sucessfully created.\n");
    fclose(filehistoric);
  }
  else{
    printf("Error creating historic file.\n");
=======
    printw("Historic file was sucessfully created.\n");
    fclose(filehistoric);
  }
  else{
    printw("Error creating historic file.\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
  }
  clearTerminal();
}

int yes_no(char* answer,int verif){
  //Fonction qui demande a l'utilisateur de repondre oui ou non, renvoie 1 si la reponse est oui et renvoie 0 si la reponse est non
<<<<<<< HEAD
  printf("Enter 'yes' or 'no': \n");
  printf("  ->  ");
  verif = scanf("%s",answer);
=======
  printw("Enter 'yes' or 'no': \n");
  printw("  ->  ");
  verif = scanw("%s",answer);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
  buffer();
  convertMin(answer);
  if (verif == 1 && (strcmp(answer,"yes") == 0  || (strcmp(answer,"no") == 0))){
  //Si la chaine entrée est bien stockée dans la variable answer et qu'elle est égale a yes ou no
  }
  else {
    //Si non
    do {
<<<<<<< HEAD
      printf("Please, answer us correctly... (enter 'yes' or 'no') \n");
      printf("  ->  ");
      verif = scanf("%s",answer);
=======
      printw("Please, answer us correctly... (enter 'yes' or 'no') \n");
      printw("  ->  ");
      verif = scanw("%s",answer);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      buffer();
    } while (verif != 1 || (strcmp(answer,"yes") != 0 && strcmp(answer,"no") != 0));
  }
  if (strcmp(answer,"yes") == 0){
    return 1;
  }
  else {
    return 0;
  }
}
void showCars(Car* cars, int numCars) {
  //Fonction quk affiche les voitures du stock

<<<<<<< HEAD
  printf("REF || BRAND || MODEL || CATEGORY || PRICE   \n");
  printf("=============================================================\n");
  for (int i = 0; i < numCars; i++) { 
    //Tant que i est inferieur au nombre de voitures, parcours chaque ligne du tableau pour afficher chaque voiture une a une a la ligne
    printf("%d - %s - %s - %d - %.2f $\n", cars[i].reference, cars[i].brand, cars[i].model, cars[i].size, cars[i].price);
=======
  printw("REF || BRAND || MODEL || CATEGORY || PRICE   \n");
  printw("=============================================================\n");
  for (int i = 0; i < numCars; i++) { 
    //Tant que i est inferieur au nombre de voitures, parcours chaque ligne du tableau pour afficher chaque voiture une a une a la ligne
    printw("%d - %s - %s - %d - %.2f $\n", cars[i].reference, cars[i].brand, cars[i].model, cars[i].size, cars[i].price);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
  }
}
void print_stock( Car* stock, int size) {
  //Pareil qu'au dessus, A VERIFIER
    for (int i = 0; i < size; i++) {
<<<<<<< HEAD
        printf("Product: %-4s %-s | Size: %-2d | Reference: %-2d | Quantity: %-2d | Price: %-4.2f $\n", stock[i].brand, stock[i].model, stock[i].size, stock[i].reference, stock[i].quantity, stock[i].price);
=======
        printw("Product: %-4s %-s | Size: %-2d | Reference: %-2d | Quantity: %-2d | Price: %-4.2f $\n", stock[i].brand, stock[i].model, stock[i].size, stock[i].reference, stock[i].quantity, stock[i].price);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }
}

void save_stock( Car* stock, int size, const char* stocktxt) {
  //Sauvegarde dans un fichier texte le stock de voitures du tableau
    FILE* file = fopen(stocktxt, "w");

    if (file == NULL) {
<<<<<<< HEAD
        printf("Error when trying to open the file.\n");
=======
        printw("Error when trying to open the file.\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        return;
    }

    for (int i = 0; i < size; i++) {
        //Ajoute dans le fichier les caracteristiques de chaque voiture
        fprintf(file, "Brand: %s\n", stock[i].brand);
        fprintf(file, "Model: %s\n", stock[i].model);
        fprintf(file, "Reference: %d\n", stock[i].reference);
        fprintf(file, "Price: %.2f\n", stock[i].price);
        fprintf(file, "Size: %d\n", stock[i].size);
        fprintf(file, "Quantity: %d\n", stock[i].quantity);
        fprintf(file, "\n");
    }

    fclose(file);
}

void load_stock(Car* stock, int* size, const char* stocktxt) {
    //Importe les caracteristiques de chaque voiture depuis le fichier texte et le rentre dans le tableau stock
    FILE* file = fopen(stocktxt, "r");

    if (file == NULL) {
<<<<<<< HEAD
        printf("Error when trying to open the file.\n");
=======
        printw("Error when trying to open the file.\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        return ;
    }

    int i = 0;
    while (i < MAX_STOCK_SIZE && fscanf(file, "Brand: %s\n", stock[i].brand) != EOF) {
        fscanf(file, "Model: %s\n", stock[i].model);
        fscanf(file, "Reference: %d\n", &stock[i].reference);
        fscanf(file, "Price: %f\n", &stock[i].price);
        fscanf(file, "Size: %d\n", &stock[i].size);
        fscanf(file, "Quantity: %d\n", &stock[i].quantity);
        fscanf(file, "\n");
        i++;
    }

    *size = i;

    fclose(file);
}
void new_car(Car* stock, int* size, int tempsize) {
  //Fonction qui ajoute une nouvelle voiture au stock
    int verif = 0;
    Car a;

<<<<<<< HEAD
    printf("Enter the name of the brand: \n");
    verif = scanf("%s", a.brand);
    while (verif !=1){
      printf("Enter the name of the brand: \n");
      verif = scanf("%s", a.brand);
    }
    printf("Enter the name of the model: \n");
    verif=scanf("%s", a.model);
    while (verif !=1){
      printf("Enter the name of the model: \n");
      verif=scanf("%s", a.model);
    }
  if (tempsize == 0){
    //Si le modele entré est une sportive
    printf("Enter the reference of the product: \n");
    verif = scanf("%d", &a.reference);
    while (verif != 1 || a.reference < 1 || a.reference > 99 ) {
        printf("The reference has to be between 1 and 99 inclusive.\n");
        printf("Enter the reference: \n");
        verif = scanf("%d", &a.reference);
=======
    printw("Enter the name of the brand: \n");
    verif = scanw("%s", a.brand);
    while (verif !=1){
      printw("Enter the name of the brand: \n");
      verif = scanw("%s", a.brand);
    }
    printw("Enter the name of the model: \n");
    verif=scanw("%s", a.model);
    while (verif !=1){
      printw("Enter the name of the model: \n");
      verif=scanw("%s", a.model);
    }
  if (tempsize == 0){
    //Si le modele entré est une sportive
    printw("Enter the reference of the product: \n");
    verif = scanw("%d", &a.reference);
    while (verif != 1 || a.reference < 1 || a.reference > 99 ) {
        printw("The reference has to be between 1 and 99 inclusive.\n");
        printw("Enter the reference: \n");
        verif = scanw("%d", &a.reference);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }
    }
    if (tempsize == 2){
    //Si le modele entré est un SUV
<<<<<<< HEAD
    printf("Enter the reference of the product: \n");
    verif = scanf("%d", &a.reference);
    while (verif != 1 || a.reference < 101 || a.reference > 199 ) {
        printf("The reference has to be between 101 and 199 inclusive.\n");
        printf("Enter the reference: \n");
        verif = scanf("%d", &a.reference);
=======
    printw("Enter the reference of the product: \n");
    verif = scanw("%d", &a.reference);
    while (verif != 1 || a.reference < 101 || a.reference > 199 ) {
        printw("The reference has to be between 101 and 199 inclusive.\n");
        printw("Enter the reference: \n");
        verif = scanw("%d", &a.reference);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }
    }
    if (tempsize == 1){
    //Si le modele entré est une voiture de ville
<<<<<<< HEAD
    printf("Enter the reference of the product: \n");
    verif = scanf("%d", &a.reference);
    while (verif != 1 || a.reference < 201 || a.reference > 299 ) {
        printf("The reference has to be between 201 and 299 inclusive.\n");
        printf("Enter the reference: \n");
        verif = scanf("%d", &a.reference);
=======
    printw("Enter the reference of the product: \n");
    verif = scanw("%d", &a.reference);
    while (verif != 1 || a.reference < 201 || a.reference > 299 ) {
        printw("The reference has to be between 201 and 299 inclusive.\n");
        printw("Enter the reference: \n");
        verif = scanw("%d", &a.reference);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }
    }

    verif = 0;

<<<<<<< HEAD
    printf("Enter the quantity to add: \n");
    verif = scanf("%d", &a.quantity);
    while (verif != 1 || a.quantity < 1 || a.quantity > 15) {
        printf("The quantity has to be between 1 and 15\n");
        printf("Enter the quantity to add: \n");
        verif = scanf("%d", &a.quantity);
=======
    printw("Enter the quantity to add: \n");
    verif = scanw("%d", &a.quantity);
    while (verif != 1 || a.quantity < 1 || a.quantity > 15) {
        printw("The quantity has to be between 1 and 15\n");
        printw("Enter the quantity to add: \n");
        verif = scanw("%d", &a.quantity);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }

    verif = 0;
    
<<<<<<< HEAD
    printf("How much does the car cost?\n");
    verif = scanf("%f", &a.price);
    while (verif != 1 || a.price < 500) {
        printf("Too cheap! The car must cost at least 500€\n");
        printf("How much does the car cost?\n");
        verif = scanf("%f", &a.price);
=======
    printw("How much does the car cost?\n");
    verif = scanw("%f", &a.price);
    while (verif != 1 || a.price < 500) {
        printw("Too cheap! The car must cost at least 500€\n");
        printw("How much does the car cost?\n");
        verif = scanw("%f", &a.price);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }

    verif = 0;

    a.size=tempsize;

    if (a.size == 0) {
        if (*size + a.quantity > MAX_STOCK_SIZE) {
<<<<<<< HEAD
            printf("Not enough space in stock to add %d sportive cars.\n", a.quantity);
=======
            printw("Not enough space in stock to add %d sportive cars.\n", a.quantity);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
            return;
        }

        for (int i = 0; i < 1; i++) {
            strcpy(stock[*size].brand, a.brand);
            strcpy(stock[*size].model, a.model);
            stock[*size].price = a.price;       
            stock[*size].reference = a.reference;
            stock[*size].size = 1;
            stock[*size].quantity = a.quantity;
            (*size)++;
        }
    } else if (a.size == 1) {
        if (*size + a.quantity * 2 > MAX_STOCK_SIZE) {
<<<<<<< HEAD
            printf("Not enough space in stock to add %d city-dweller cars.\n", a.quantity);
=======
            printw("Not enough space in stock to add %d city-dweller cars.\n", a.quantity);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
            return;
        }

        for (int i = 0; i < 1; i++) {
            strcpy(stock[*size].brand, a.brand);
            strcpy(stock[*size].model, a.model);
            stock[*size].price = a.price;       
            stock[*size].reference = a.reference;
            stock[*size].size = 2;
            stock[*size].quantity = a.quantity;
            (*size)++;
        }
    } else if (a.size == 2) {
        if (*size + a.quantity * 4 > MAX_STOCK_SIZE) {
<<<<<<< HEAD
            printf("Not enough space in stock to add %d SUVs.\n", a.quantity);
=======
            printw("Not enough space in stock to add %d SUVs.\n", a.quantity);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
            return;
        }

        for (int i = 0; i < 1; i++) {
            strcpy(stock[*size].brand, a.brand);
            strcpy(stock[*size].model, a.model);
            stock[*size].price = a.price;       
            stock[*size].reference = a.reference;
            stock[*size].size = 4;
            stock[*size].quantity = a.quantity;
            (*size)++;
        }
    }

<<<<<<< HEAD
    printf("Car(s) added to the stock.\n");
=======
    printw("Car(s) added to the stock.\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
}

/*
Car low_stock(Car* cars,int numCars){
  //fonction qui parcourt le stock et qui affiche les voitures en ruptures et les 5 voitures qui ont le moins de stock, POUR GP MANAGER
}

void clientHistoric(Client client){
  //fonction qui cherche les trois derniers achats d'un client dans son historique d'achat
}

void deleteClient(Client client){
  //fonction qui supprime le dossier d'un client 
}*/

void printCurrentDate() {
    time_t currentTime;
    struct tm* timeInfo;
    char buffer[80];

    // Obtention de l'heure actuelle
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    // Formatage de la date en anglais
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", timeInfo);

    // Affichage de la date
<<<<<<< HEAD
    printf("Today's date is: %s\n", buffer);
=======
    printw("Today's date is: %s\n", buffer);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
}
void delete_car(Car* stock, int size, const char* stocktxt){
    print_stock(stock,size);
    int linenumber;
<<<<<<< HEAD
    printf("What is the line number of the car you want to delete ?\n");
    scanf("%d",&linenumber);
=======
    printw("What is the line number of the car you want to delete ?\n");
    scanw("%d",&linenumber);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    for (int i = linenumber - 1; i < size ; i++){
        stock[i] = stock[i+1];
    }
    size = size - 1;
    print_stock(stock,size);
}
void message(){
<<<<<<< HEAD
    printf("===========================================================================================================\n");
    printf("  /$$$$$$             /$$$$$$\  |$$|                          \n");
    printf(" /$$__  $$           /$$__  $$| |$$|                          /$$__  $$| $$                          \n");
    printf("| $$  \\__/ /$$   /$$| $$  \\__/| $$$$$$$   /$$$$$$   /$$$$$$ | $$  \\__/| $$$$$$$   /$$$$$$   /$$$$$$ \n");
    printf("| $$      | $$  | $$|  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$|  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$\n");
    printf("| $$      | $$  | $$ \\____  $$| $$  \\ $$| $$  \\ $$| $$  \\ $$ \\____  $$| $$  \\ $$| $$  \\ $$| $$  \\ $$\n");
    printf("| $$    $$| $$  | $$ /$$  \\ $$| $$  | $$| $$  | $$| $$  | $$ /$$  \\ $$| $$  | $$| $$  | $$| $$  | $$\n");
    printf("|  $$$$$$/|  $$$$$$$|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/\n");
    printf(" \\______/  \\____  $$ \\______/ |__/  |__/ \\______/ | $$____/  \\______/ |__/  |__/ \\______/ | $$____/ \n");
    printf("           /$$  | $$                              | $$                                    | $$      \n");
    printf("          |  $$$$$$/                              | $$                                    | $$      \n");
    printf("           \\______/                               |__/                                    |__/      \n");
    printf("===========================================================================================================\n");
    printf("\n");
    printf("\n");
=======
    printw("===========================================================================================================\n");
    printw("  /$$$$$$             /$$$$$$\  |$$|                          \n");
    printw(" /$$__  $$           /$$__  $$| |$$|                          /$$__  $$| $$                          \n");
    printw("| $$  \\__/ /$$   /$$| $$  \\__/| $$$$$$$   /$$$$$$   /$$$$$$ | $$  \\__/| $$$$$$$   /$$$$$$   /$$$$$$ \n");
    printw("| $$      | $$  | $$|  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$|  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$\n");
    printw("| $$      | $$  | $$ \\____  $$| $$  \\ $$| $$  \\ $$| $$  \\ $$ \\____  $$| $$  \\ $$| $$  \\ $$| $$  \\ $$\n");
    printw("| $$    $$| $$  | $$ /$$  \\ $$| $$  | $$| $$  | $$| $$  | $$ /$$  \\ $$| $$  | $$| $$  | $$| $$  | $$\n");
    printw("|  $$$$$$/|  $$$$$$$|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/\n");
    printw(" \\______/  \\____  $$ \\______/ |__/  |__/ \\______/ | $$____/  \\______/ |__/  |__/ \\______/ | $$____/ \n");
    printw("           /$$  | $$                              | $$                                    | $$      \n");
    printw("          |  $$$$$$/                              | $$                                    | $$      \n");
    printw("           \\______/                               |__/                                    |__/      \n");
    printw("===========================================================================================================\n");
    printw("\n");
    printw("\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
}
int main_manager() {
    int verif=0;
    char tab[4];
    int sizecita = 0;
    int sizesuv = 0;
    int sizesport = 0;
    int tempsize = 0;
    Car stockcita[MAX_STOCK_SIZE];
    Car stocksuv[MAX_STOCK_SIZE];
    Car stocksport[MAX_STOCK_SIZE];
    clearTerminal();
    load_stock(stockcita, &sizecita, "stockcita.txt");
    load_stock(stocksuv, &sizesuv, "stocksuv.txt");
    load_stock(stocksport, &sizesport, "stocksport.txt");
<<<<<<< HEAD
    printf("Hey, here is the today's stock !\n");
    printf("\n");
    printf("City dweller cars : \n");
    printf("\n");
    print_stock(stockcita,sizecita);
    printf("\n");
    printf("Sports cars : \n");
    printf("\n");
    print_stock(stocksport,sizesport);
    printf("\n");
    printf("SUV cars: \n");
    printf("\n");
    print_stock(stocksuv,sizesuv);
    printf("\n");

    comeBack :
    printf("Do you have some news cars to comand ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
       verif=0;
       printf("What type of vehicle do you want to add? (0=Sportive, 1=City-dweller car,2=SUV or enter '9' to go back)\n");
       verif=scanf("%d",&tempsize);
       while(verif != 1 || tempsize != 0 || tempsize != 2 || tempsize !=1 || tempsize != 9){
        buffer();
        printf("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
        verif = scanf("%d", &tempsize);
=======
    printw("Hey, here is the today's stock !\n");
    printw("\n");
    printw("City dweller cars : \n");
    printw("\n");
    print_stock(stockcita,sizecita);
    printw("\n");
    printw("Sports cars : \n");
    printw("\n");
    print_stock(stocksport,sizesport);
    printw("\n");
    printw("SUV cars: \n");
    printw("\n");
    print_stock(stocksuv,sizesuv);
    printw("\n");

    comeBack :
    printw("Do you have some news cars to comand ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
       verif=0;
       printw("What type of vehicle do you want to add? (0=Sportive, 1=City-dweller car,2=SUV or enter '9' to go back)\n");
       verif=scanw("%d",&tempsize);
       while(verif != 1 || tempsize != 0 || tempsize != 2 || tempsize !=1 || tempsize != 9){
        buffer();
        printw("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
        verif = scanw("%d", &tempsize);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
       }
       
      if (tempsize == 0) {
          new_car(stocksport, &sizesport, tempsize);
      } else if (tempsize == 1) {
          new_car(stockcita, &sizecita, tempsize);
      } else if (tempsize == 2) {
          new_car(stocksuv, &sizesuv, tempsize);
      } else if (tempsize == 9) {
        goto comeBack;
      } else {
<<<<<<< HEAD
          printf("Invalid vehicle type.\n");
=======
          printw("Invalid vehicle type.\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
          return 1;
    }
    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");
    }
    else if(verif==-1){
<<<<<<< HEAD
      printf("Error when yes_no\n");
      return 0;
    }
    printf("Do you have some cars to delete ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
      printf("What type of car do you want to delete ? (0=Sportive, 1= City Dweller, 2= SUV or enter '9' to go back)\n");
      verif=scanf("%d",&tempsize);
=======
      printw("Error when yes_no\n");
      return 0;
    }
    printw("Do you have some cars to delete ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
      printw("What type of car do you want to delete ? (0=Sportive, 1= City Dweller, 2= SUV or enter '9' to go back)\n");
      verif=scanw("%d",&tempsize);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      while(verif != 1 || tempsize!= 0 || tempsize!= 2||tempsize!=9|| tempsize!=1){
       if (tempsize==9) {
        goto comeBack;
       }
<<<<<<< HEAD
       printf("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
       verif = scanf("%d", &tempsize);
=======
       printw("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
       verif = scanw("%d", &tempsize);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
       }
      if(tempsize==0){
        delete_car(stocksport, sizesport,"stocksport.txt");
      }
      else if(tempsize==1){
        delete_car(stockcita, sizecita,"stockcita.txt");
      }
      else if(tempsize==2){
        delete_car(stocksuv, sizesuv,"stocksuv.txt");
      }

      
      }
    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");
    

  return 0;
}
int main_gp_buyer2() {
  char filename[50];
  char card[6];
  int category = 0;
  int reference = 0;
  int verif = 0;
  float cart = 0;
  float *kart = &cart;
  char answer[5];
  int choice = 0;
  int i = 0;
  FILE *file = fopen("historique", "w");
  Date today;
  int r = 0;
  int count = 0;
  int v = 0;
  int sizecita = 0;
  int sizesuv = 0;
  int sizesport = 0;
  Car stockcita[MAX_STOCK_SIZE];
  Car stocksuv[MAX_STOCK_SIZE];
  Car stocksport[MAX_STOCK_SIZE];
    
  load_stock(stockcita, &sizecita, "stockcita.txt");
  load_stock(stocksuv, &sizesuv, "stocksuv.txt");
  load_stock(stocksport, &sizesport, "stocksport.txt");
    int tempsize = 0;

  // Nettoyer le terminal
  clearTerminal();

  int id = 0;
  int index;
  Client client;

<<<<<<< HEAD
  printf("Hello ! Welcome to CYShopShop !\n");
  printf("=============================================================\n");
  printf("Did you already come in our store ? (enter 'yes' or 'no') \n");
  index = yes_no(answer, verif);

  if (index == 1) {
    printf("Do you already have an account ? (enter 'yes' or 'no') \n");
    index = yes_no(answer, verif);
    clearTerminal();
    if (index == 1) {
      printf("OK. Let's start to shop !\n");
      v=1;
      // vérifier si il y a bien le dossier
    } else if (index == 0) {
      printf("Do you want to create an account in our shop ? (enter 'yes' or "
=======
  printw("Hello ! Welcome to CYShopShop !\n");
  printw("=============================================================\n");
  printw("Did you already come in our store ? (enter 'yes' or 'no') \n");
  index = yes_no(answer, verif);

  if (index == 1) {
    printw("Do you already have an account ? (enter 'yes' or 'no') \n");
    index = yes_no(answer, verif);
    clearTerminal();
    if (index == 1) {
      printw("OK. Let's start to shop !\n");
      v=1;
      // vérifier si il y a bien le dossier
    } else if (index == 0) {
      printw("Do you want to create an account in our shop ? (enter 'yes' or "
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
             "'no')\n");
      index = yes_no(answer, verif);
      if (index == 1) {
        createClient(client);
        v=1;
      } else if (index == 0) {
<<<<<<< HEAD
        printf("No problem. Let's start to shop !\n");
=======
        printw("No problem. Let's start to shop !\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      }
    }
  } 
  else if (index == 0) {
<<<<<<< HEAD
    printf("Do you want to create an account in our shop ? (enter 'yes' or "
=======
    printw("Do you want to create an account in our shop ? (enter 'yes' or "
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
           "'no')\n");
    index = yes_no(answer, verif);
    if (index == 1) {
      createClient(client);
      v=1;
    } else if (index == 0) {
      clearTerminal();
<<<<<<< HEAD
      printf("No problem. Let's start to shop !\n");
=======
      printw("No problem. Let's start to shop !\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }
  }

  clearTerminal();
goback:
  do {
    printCurrentDate();
<<<<<<< HEAD
    printf("=============================================================\n");
    printf("                                                          Cars in "
           "the cart : %d\n",
           i);
    printf("So first, choose a category of cars (1,2 or 3) :\n");
    printf("         1. Sportives\n");
    printf("         2. SUV\n");
    printf("         3. City cars\n");
    printf("Your choice : ");
    verif = scanf("%d", &category);
    if (verif != 1 || (category != 1 && category != 2 && category != 3)) {
      do {
        printf("The selected category is not valid. Please retry.\n");
        buffer();
        printf("  ->  ");
        verif = scanf("%d", &category);
=======
    printw("=============================================================\n");
    printw("                                                          Cars in "
           "the cart : %d\n",
           i);
    printw("So first, choose a category of cars (1,2 or 3) :\n");
    printw("         1. Sportives\n");
    printw("         2. SUV\n");
    printw("         3. City cars\n");
    printw("Your choice : ");
    verif = scanw("%d", &category);
    if (verif != 1 || (category != 1 && category != 2 && category != 3)) {
      do {
        printw("The selected category is not valid. Please retry.\n");
        buffer();
        printw("  ->  ");
        verif = scanw("%d", &category);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      } while (verif != 1 || (category != 1 && category != 2 && category != 3));
    } else {
    }
    buffer();
    verif = 0;
    clearTerminal();

    // Proposer les différentes voitures dispo selon la catégorie
    if (category == 1) {
      print_stock(stocksport, sizesport);
<<<<<<< HEAD
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to the menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
=======
      printw("=============================================================\n");
      printw("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to the menu)\n");
      printw("  ->  ");
      verif = scanw("%d", &reference);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      if (verif == 1 && reference >= 1 && reference <= sizesport) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
<<<<<<< HEAD
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
=======
          printw("Please enter a valid number.\n");
          buffer();
          verif = scanw("%d", &reference);
          printw("  ->  ");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        } while (verif != 1 || reference < 1 || reference > sizesport);
      }
      buffer();
      choice = reference;
      //demander a elyes
      fprintf(file, "Date: %d/%d/%d à %d : %d : %d, Car: %s %s , Price: %.2f\n",
             today.day, today.month, today.year, today.hour, today.minute,
             today.second, stocksport[choice - 1].brand,
             stocksport[choice - 1].model, stocksport[choice - 1].price);
<<<<<<< HEAD
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
=======
      printw("Congrats ! You're now the proud owner of a %s %s !\n",
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
             stocksport[choice - 1].brand, stocksport[choice - 1].model);
      cart = cart + stocksport[choice - 1].price;
      reference = 0;

    } else if (category == 2) {
      print_stock(stocksuv, sizesuv);
<<<<<<< HEAD
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
=======
      printw("=============================================================\n");
      printw("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printw("  ->  ");
      verif = scanw("%d", &reference);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      if (verif == 1 && reference >= 101 && reference <= sizesuv + 100) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
<<<<<<< HEAD
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
=======
          printw("Please enter a valid number.\n");
          buffer();
          verif = scanw("%d", &reference);
          printw("  ->  ");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        } while (verif != 1 || reference < 101 || reference > sizesuv + 100);
      }
      buffer();
      choice = reference - 100;
<<<<<<< HEAD
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
=======
      printw("Congrats ! You're now the proud owner of a %s %s !\n",
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
             stocksuv[choice - 1].brand, stocksuv[choice - 1].model);
      cart = cart + stocksuv[choice - 1].price;
      reference = 0;

    } else if (category == 3) {
      print_stock(stockcita, sizecita);
<<<<<<< HEAD
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
=======
      printw("=============================================================\n");
      printw("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printw("  ->  ");
      verif = scanw("%d", &reference);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      if (verif == 1 && reference >= 201 && reference <= sizecita + 200) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
<<<<<<< HEAD
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
=======
          printw("Please enter a valid number.\n");
          buffer();
          verif = scanw("%d", &reference);
          printw("  ->  ");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        } while (verif != 1 || reference < 201 ||
                 reference > sizecita + 200);
      }
      buffer();
      choice = reference - 200;
<<<<<<< HEAD
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
=======
      printw("Congrats ! You're now the proud owner of a %s %s !\n",
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
             stockcita[choice - 1].brand, stockcita[choice - 1].model);
      cart = cart + stockcita[choice - 1].price;
      reference = 0;
    }

<<<<<<< HEAD
    printf("Do you want to continue your shopping ? (enter 'yes' or 'no')\n");
    printf("  ->  ");
    scanf("%s", answer);
    convertMin(answer);
    while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0) {
      printf("Please don't play and enter a correct answer...\n");
      printf("  ->  ");
      scanf("%s", answer);
=======
    printw("Do you want to continue your shopping ? (enter 'yes' or 'no')\n");
    printw("  ->  ");
    scanw("%s", answer);
    convertMin(answer);
    while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0) {
      printw("Please don't play and enter a correct answer...\n");
      printw("  ->  ");
      scanw("%s", answer);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    }
    clearTerminal();
    i = i + 1;
  } while (strcmp(answer, "yes") == 0);

  // Procéder au paiement
  clearTerminal();
<<<<<<< HEAD
  printf("OK ! So you have in your cart %d cars so you will have to pay %.2f $.\n",i, cart);
  printf("=============================================================\n");
  if(v==1){
    if(client.points!=0){
      if(cart-client.points<0){
        printf("Thanks for being loyal to our services ! Thanks to your fidelity your cart is free ! :O\n");
=======
  printw("OK ! So you have in your cart %d cars so you will have to pay %.2f $.\n",i, cart);
  printw("=============================================================\n");
  if(v==1){
    if(client.points!=0){
      if(cart-client.points<0){
        printw("Thanks for being loyal to our services ! Thanks to your fidelity your cart is free ! :O\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        client.points=client.points-cart;
        cart=0;
      }
      else{
        cart=cart-client.points;
<<<<<<< HEAD
        printf("Jackpot ! You have %f fidelity points on your account !\n You have a sale of %f$ to your cart!\nYou will now pay %f$",client.points, client.points, cart);
=======
        printw("Jackpot ! You have %f fidelity points on your account !\n You have a sale of %f$ to your cart!\nYou will now pay %f$",client.points, client.points, cart);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        client.points=0;
      }
    }
  }
  if (cart != 0) {
<<<<<<< HEAD
    printf("Please enter your card number. (it's for a friend) \n");
    printf("  ->  ");
    verif = scanf("%s",card);
=======
    printw("Please enter your card number. (it's for a friend) \n");
    printw("  ->  ");
    verif = scanw("%s",card);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
    buffer();
    if ((strlen(card) == 4) && (testInt(card) == 1)){
    }
    else{
      do {
<<<<<<< HEAD
        printf("Your datas are safe with us please enter your number card.\n");
        printf("  ->  ");
        verif = scanf("%s",card);
=======
        printw("Your datas are safe with us please enter your number card.\n");
        printw("  ->  ");
        verif = scanw("%s",card);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
        buffer();
      } while ((strlen (card) != 4) || (testInt(card) == 0));
    }
      // conclusion
<<<<<<< HEAD
      printf("Have you been pleased with our services? (enter 'yes' or 'no')\n");
=======
      printw("Have you been pleased with our services? (enter 'yes' or 'no')\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
  index = yes_no(answer,verif);
  if (index == 1){
    if (v==1){
    }
    else{
<<<<<<< HEAD
      printf("Do you want an account in CYShopShop now ? (enter 'yes' or 'no')\n");
=======
      printw("Do you want an account in CYShopShop now ? (enter 'yes' or 'no')\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      index = yes_no(answer,verif);
      if (index == 1){
        createClient(client);
        v=1;
      }
      else{
      }
    }
  }
  if(v==1){
    float sale;
    sale=cart*0.05;
<<<<<<< HEAD
    printf("You have %f fidelity points ! 1 fidelity point = 1€\nSo you have a %f sale on your next buy!\n",sale ,sale);
=======
    printw("You have %f fidelity points ! 1 fidelity point = 1€\nSo you have a %f sale on your next buy!\n",sale ,sale);
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
  }
  else if (index == 0){
    if (v==1){
      clearTerminal();
<<<<<<< HEAD
      printf("Do you want to delete your CYShopShop account ( please give us a chance ;( ) (enter 'yes' or 'no')\n");
      index = yes_no(answer,verif);
      if (index == 1){
        printf("So, your account will be deleted...\n");
        //fonction pour supprimer le compte client
      }
      else{
        printf("Thank you my lord ! I promise we'll never disappoint you again !\n");
=======
      printw("Do you want to delete your CYShopShop account ( please give us a chance ;( ) (enter 'yes' or 'no')\n");
      index = yes_no(answer,verif);
      if (index == 1){
        printw("So, your account will be deleted...\n");
        //fonction pour supprimer le compte client
      }
      else{
        printw("Thank you my lord ! I promise we'll never disappoint you again !\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
      }
    }
  }
  clearTerminal();
  
<<<<<<< HEAD
  printf("Well, glad to hear it and we hope we'll see you soon ;).\n"); 
  } else {
    printf("So we hope you will come back soon ! Bye bye !\n");
=======
  printw("Well, glad to hear it and we hope we'll see you soon ;).\n"); 
  } else {
    printw("So we hope you will come back soon ! Bye bye !\n");
>>>>>>> f7637541ed8642629444225a1e7f855fe7aa166c
  }
  return 0;
}
int main_del(){
    int sizecita = 0;
    int sizesuv = 0;
    int sizesport = 0;
    Car stockcita[MAX_STOCK_SIZE];
    Car stocksuv[MAX_STOCK_SIZE];
    Car stocksport[MAX_STOCK_SIZE];
    //load_stock(stocksuv,&sizesuv, "stocksuv.txt");
    //delete_car(stocksuv, sizesuv, "stocksuv.txt");
    load_stock(stocksport,&sizesport, "stocksport.txt");
    delete_car(stocksport, sizesport, "stocksport.txt");
    return 0;
}
