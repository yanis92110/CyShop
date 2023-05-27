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
      printf("Veuillez entrer un nombre positif\n");
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
      printf("%c",tab[i]);
      i++;
    }
  }
  void printArrayInt(int* tab){
  //Fonction qui affiche un tableau d'entiers
    int i=0;
    while(tab[i]!='\0'){
      printf("%d\n",tab[i]);
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

void createClient(Client* client, Date date, int count){
  char filename[30] = "clients.txt";
  FILE* file = fopen(filename,"a");

  clearTerminal();

  printf("Enter your name: ");
  scanf("%s", client->name);
  buffer();

  printf("Enter your surname: ");
  scanf("%s", client->surname);
  buffer();

  client->id = count + 1;

  if (file != NULL) {
    fprintf(file, "Account created on: %d/%d/%d at %d:%d:%d\n", date.day, date.month, date.year, date.hour, date.minute, date.second);
    fprintf(file, "Name: %s\n", client->name);
    fprintf(file, "Surname: %s\n", client->surname);
    fprintf(file, "ID: %d\n\n", client->id);
    fclose(file);
    printf("Client added in: %s\n", filename);
  } else {
    printf("Error creating client file.\n");
  }
  sleep(2);
  clearTerminal();
  
}

int yes_no(char* answer,int verif){
  //Fonction qui demande a l'utilisateur de repondre oui ou non, renvoie 1 si la reponse est oui et renvoie 0 si la reponse est non
  printf("Enter 'yes' or 'no': \n");
  printf("  ->  ");
  verif = scanf("%s",answer);
  buffer();
  convertMin(answer);
  if (verif == 1 && (strcmp(answer,"yes") == 0  || (strcmp(answer,"no") == 0))){
  //Si la chaine entrée est bien stockée dans la variable answer et qu'elle est égale a yes ou no
  }
  else {
    //Si non
    do {
      printf("Please, answer us correctly... (enter 'yes' or 'no') \n");
      printf("  ->  ");
      verif = scanf("%s",answer);
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
  //Fonction qui affiche les voitures du stock

  printf("REF || BRAND || MODEL || CATEGORY || PRICE   \n");
  printf("=============================================================\n");
  for (int i = 0; i < numCars; i++) { 
    //Tant que i est inferieur au nombre de voitures, parcours chaque ligne du tableau pour afficher chaque voiture une a une a la ligne
    printf("%d - %s - %s - %d - %.2f $\n", cars[i].reference, cars[i].brand, cars[i].model, cars[i].size, cars[i].price);
  }
}

void print_stock( Car* stock, int size) {
  //Pareil qu'au dessus, A VERIFIER
    printf("REF || BRAND || MODEL || CATEGORY || PRICE   \n");
    printf("=============================================================\n");
    for (int i = 0; i < size; i++) {
        printf("Product: %-4s %-s | Size: %-2d | Reference: %-2d | Quantity: %-2d | Price: %-4.2f $\n", stock[i].brand, stock[i].model, stock[i].size, stock[i].reference, stock[i].quantity, stock[i].price);
    }
}

void save_stock( Car* stock, int size, const char* stocktxt) {
  //Sauvegarde dans un fichier texte le stock de voitures du tableau
    FILE* file = fopen(stocktxt, "w");

    if (file == NULL) {
        printf("Error when trying to open the file.\n");
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
        printf("Error when trying to open the file.\n");
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
    }
    }
    if (tempsize == 2){
    //Si le modele entré est un SUV
    printf("Enter the reference of the product: \n");
    verif = scanf("%d", &a.reference);
    while (verif != 1 || a.reference < 101 || a.reference > 199 ) {
        printf("The reference has to be between 101 and 199 inclusive.\n");
        printf("Enter the reference: \n");
        verif = scanf("%d", &a.reference);
    }
    }
    if (tempsize == 1){
    //Si le modele entré est une voiture de ville
    printf("Enter the reference of the product: \n");
    verif = scanf("%d", &a.reference);
    while (verif != 1 || a.reference < 201 || a.reference > 299 ) {
        printf("The reference has to be between 201 and 299 inclusive.\n");
        printf("Enter the reference: \n");
        verif = scanf("%d", &a.reference);
    }
    }

    verif = 0;

    printf("Enter the quantity to add: \n");
    verif = scanf("%d", &a.quantity);
    while (verif != 1 || a.quantity < 1 || a.quantity > 15) {
        printf("The quantity has to be between 1 and 15\n");
        printf("Enter the quantity to add: \n");
        verif = scanf("%d", &a.quantity);
    }

    verif = 0;
    
    printf("How much does the car cost?\n");
    verif = scanf("%f", &a.price);
    while (verif != 1 || a.price < 500) {
        printf("Too cheap! The car must cost at least 500€\n");
        printf("How much does the car cost?\n");
        verif = scanf("%f", &a.price);
    }

    verif = 0;

    a.size=tempsize;

    if (a.size == 0) {
        if (*size + a.quantity > MAX_STOCK_SIZE) {
            printf("Not enough space in stock to add %d sportive cars.\n", a.quantity);
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
            printf("Not enough space in stock to add %d city-dweller cars.\n", a.quantity);
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
            printf("Not enough space in stock to add %d SUVs.\n", a.quantity);
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

    printf("Car(s) added to the stock.\n");
}

int main_manager() {
    int verif=0;
    char tab[4];
    int sizecita = 0;
    int sizesuv = 0;
    int sizesport = 0;
    int size0 = 0;
    int tempsize = 0;
    Car stockcita[MAX_STOCK_SIZE];
    Car stocksuv[MAX_STOCK_SIZE];
    Car stocksport[MAX_STOCK_SIZE];
    //Car tsportstock[MAX_STOCK_SIZE];
    //Car tsuvstock[MAX_STOCK_SIZE];
    //Car tcitastock[MAX_STOCK_SIZE];
    Car tstock[MAX_TAB];
    clearTerminal();
    load_stock(stockcita, &sizecita, "stockcita.txt");
    load_stock(stocksuv, &sizesuv, "stocksuv.txt");
    load_stock(stocksport, &sizesport, "stocksport.txt");
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
    printf("5 cars with the lowest quantity: \n");
    printf("\n");
    int da = 0;
    int mien = 0;
    int tsize = sizesport + sizesuv + sizecita;
    for(int o = 0; o < sizesport; o++){
       tstock[o] = stocksport[o];
    }
    for(int j = sizesport; j < sizesport + sizesuv; j++){
       tstock[j] = stocksuv[da];
       da++;
    }
    for(int k = sizesport + sizesuv; k < tsize; k++){
       tstock[k] = stockcita[mien];
       mien++;
    }
    tri5(tstock, tsize);
    printf("\n");
    comeBack :
    printf("Do you have some news cars to comand ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
       verif=0;
       printf("What type of vehicle do you want to add? (0=Sportive, 1=City-dweller car,2=SUV or enter '9' to go back)\n");
       verif=scanf("%d",&tempsize);
       while(verif != 1 || (tempsize != 0 && tempsize != 2 && tempsize != 1 && tempsize != 9)){
        buffer();
        printf("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
        verif = scanf("%d", &tempsize);
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
          printf("Invalid vehicle type.\n");
          return 1;
    }
    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");
    }
    else if(verif==-1){
      printf("Error when yes_no\n");
      return 0;
    }
    printf("Do you have some cars to delete ?\n");
    verif=yes_no(tab,verif);
    if(verif==1){
      printf("What type of car do you want to delete ? (0=Sportive, 1= City Dweller, 2= SUV or enter '9' to go back)\n");
      verif=scanf("%d",&tempsize);
      while(verif != 1 || (tempsize != 0 && tempsize != 2 && tempsize != 1 && tempsize != 9)){
       if (tempsize==9) {
        goto comeBack;
       }
       printf("Please enter a correct number, 0 for a Sportive Car, 1 for a City-dweller car or 2 SUV)\n");
       verif = scanf("%d", &tempsize);
       }
      if(tempsize==0){
        delete_car(stocksport, &sizesport,"stocksport.txt");
      }
      else if(tempsize==1){
        delete_car(stockcita, &sizecita,"stockcita.txt");
      }
      else if(tempsize==2){
        delete_car(stocksuv, &sizesuv,"stocksuv.txt");
      }

      
      }
    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");
    

  return 0;
}
int main_gp_buyer2() {
  Client* clients;
  Client client;
  Date today;
  int h = 0;
  char filename[50] = "historics.txt";
  char card[6];
  int category = 0;
  int reference = 0;
  int verif = 0;
  float cart = 0;
  float *kart = &cart;
  char answer[5];
  int choice = 0;
  int tempq = 1;
  int q = 0;
  int check,id;
  int i = 0;
  FILE *file = fopen(filename, "r+");
  int r = 0;
  int count = clientCount("clientCounter.txt");
  int v = 0;
  int index;
  int sizecita = 0;
  int sizesuv = 0;
  int sizesport = 0;
  int size0;
  Car stock0[MAX_STOCK_SIZE];
  Car stockcita[MAX_STOCK_SIZE];
  Car stocksuv[MAX_STOCK_SIZE];
  Car stocksport[MAX_STOCK_SIZE];
  load_stock(stock0, &size0, "stock0.txt");
  load_stock(stockcita, &sizecita, "stockcita.txt");
  load_stock(stocksuv, &sizesuv, "stocksuv.txt");
  load_stock(stocksport, &sizesport, "stocksport.txt");
  clientsFileToTab("clients.txt", &clients, &count);
  int tempsize = 0;
  
  
  today = getDate();
    // Nettoyer le terminal
  clearTerminal();
  
  printf("Hello ! Welcome to CYShopShop !\n");
  printf("=============================================================\n");
  printf("Did you already come in our store ? \n");
  index = yes_no(answer, verif);

  if (index == 1) {
    printf("Do you already have an account ? \n");
    index = yes_no(answer, verif);
    clearTerminal();
    if (index == 1) {
      printf("Let's check if you're in our datas...\n");
      sleep(2);
      printf("Please enter your id. (you had to remember it)\n");
      printf("  ->  ");
      verif = scanf("%d",&id);
      buffer();
      if (id<0 || verif != 1){
        do {
          printf("Please, enter a valid ID.\n");
          printf("  ->  ");
          verif = scanf("%d",&id);
          buffer();
        } while (id<0 || verif != 1);
      }
      check = verif_client(clients, id, count);
      clearTerminal();
      if (check == 1){
        printf("Perfect, we find you !\n");
        printf("===========================================================\n");
        printf("Your last buy here were :\n");
        threeLastBuy(file,id);
        printf("===========================================================\n");
        printf("Enter 'ok' when you're ready to start !\n");
        printf("  ->  ");
        verif = scanf("%s",answer);
        convertMin(answer);
        buffer();
        if (verif == 1 && strcmp(answer,"ok") == 0){
        }
        else {
          do{
            printf("Please, stay focused... Enter 'ok' to continue.\n");
            printf("  ->  ");
            verif = scanf("%s",answer);
          } while(verif != 1 || strcmp(answer,"ok") != 0);
        }
      }
      else {
        printf("Oh... We can't find your datas... Do you want to recreate a new account ?\n");
        index = yes_no(answer,verif);
        if (index == 1){
          createClient(&client,today,count);
          addClient();
          printf("Please remember your ID : %d.\n",client.id);
          sleep(3);
        }
        else {
          h = 1;
          printf("Well, let's start to shop !\n");
          sleep(1);
        }
      }
      v=1;
    } else if (index == 0) {
      clearTerminal();
      printf("Do you want to create an account in our shop ? \n");
      index = yes_no(answer, verif);
      if (index == 1) {
        createClient(&client,today,count);
        addClient();
        printf("Please remember your ID : %d.\n",client.id);
        sleep(3);
        v=1;
      } else if (index == 0) {
        h=1;
        printf("Let's start to shop !\n");
        sleep(1);
      }
    }
  } else if (index == 0) {
    clearTerminal();
    printf("Do you want to create an account in our shop ? \n");
    index = yes_no(answer, verif);
    if (index == 1) {
      createClient(&client,today,count);
      addClient();
      printf("Please remember your ID : %d.\n",client.id);
      sleep(3);
      v=1;
    } else if (index == 0) {
      clearTerminal();
      h = 1;
      printf("Let's start to shop !\n");
      sleep(1);
    }
  }
clearTerminal();
clientsFileToTab("clients.txt", &clients, &count);
goback:
  do {
      // show date and hour
    printf("Current date : %02d/%02d/%d\n", today.day, today.month, today.year);
    printf("Current time : %02d:%02d:%02d\n", today.hour, today.minute, today.second);
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
      } while (verif != 1 || (category != 1 && category != 2 && category != 3));
    } else {
    }
    buffer();
    verif = 0;
    clearTerminal();

    // Proposer les différentes voitures dispo selon la catégorie
    if (category == 1) {
      print_stock(stocksport, sizesport);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to the menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 1 && reference <= sizesport) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 1 || reference > sizesport);
      }
      buffer();
      choice = reference;
      clearTerminal();
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             stocksport[choice - 1].brand, stocksport[choice - 1].model);
      cart = cart + stocksport[choice - 1].price;
      stocksport[choice - 1].quantity= stocksport[choice - 1].quantity - 1;
      if(stocksport[choice -1].quantity == 0){
        size0 = size0 + 1;
        for(int k = size0; k < size0 + 1; k++){
            stocksport[choice - 1] = stock0[k];
        }
        for (int i = choice - 1; i < sizesport ; i++){
        stocksport[i] = stocksport[i+1];
    }
    sizesport = sizesport - 1;
      }
      reference = 0;
      if (h == 0){
        addHistoric(choice,today,stocksport,id);
      }else {
      }

    } else if (category == 2) {
      print_stock(stocksuv, sizesuv);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 101 && reference <= sizesuv + 100) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 101 || reference > sizesuv + 100);
      }
      buffer();
      choice = reference - 100;
      clearTerminal();
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             stocksuv[choice - 1].brand, stocksuv[choice - 1].model);
      cart = cart + stocksuv[choice - 1].price;
      stocksuv[choice - 1].quantity= stocksuv[choice - 1].quantity - 1;
      if(stocksuv[choice -1].quantity == 0){
        size0 = size0 + 1;
        for(int k = size0; k < size0 + 1; k++){
            stocksuv[choice - 1] = stock0[k];
        }
        for (int i = choice - 1; i < sizesuv ; i++){
        stocksuv[i] = stocksuv[i+1];
        }
        sizesuv = sizesuv - 1;
      }
      reference = 0;
      if (h == 0){
              addHistoric(choice,today,stocksuv,id);
      }else {
      }

    } else if (category == 3) {
      print_stock(stockcita, sizecita);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 201 && reference <= sizecita + 200) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 201 ||
                 reference > sizecita + 200);
      }
      buffer();
      choice = reference - 200;
      clearTerminal();
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             stockcita[choice - 1].brand, stockcita[choice - 1].model);
      cart = cart + stockcita[choice - 1].price;
      stockcita[choice - 1].quantity= stockcita[choice - 1].quantity - 1;
      if(stockcita[choice -1].quantity == 0){
         size0 = size0 + 1;
         for(int k = size0; k < size0 + 1; k++){
            stockcita[choice - 1] = stock0[k];
        }
        for (int i = choice - 1; i < sizesport ; i++){
        stockcita[i] = stockcita[i+1];
        }
    sizecita = sizecita - 1;
      }
      reference = 0;
      if (h == 0){
              addHistoric(choice,today,stockcita,id);
      }
      else {
      }
    }
    clearTerminal();
    printf("Do you want to continue your shopping ? (enter 'yes' or 'no')\n");
    printf("  ->  ");
    scanf("%s", answer);
    convertMin(answer);
    while (strcmp(answer, "yes") != 0 && strcmp(answer, "no") != 0) {
      printf("Please don't play and enter a correct answer...\n");
      printf("  ->  ");
      scanf("%s", answer);
    }
    clearTerminal();
    i = i + 1;
  } while (strcmp(answer, "yes") == 0);

  // Procéder au paiement
  clearTerminal();
  printf("OK ! So you have in your cart %d cars so you will have to pay %.2f $.\n",i, cart);
  printf("=============================================================\n");
  if (cart != 0) {
    printf("Please enter the 4 digits of your card code. (it's for a friend) \n");
    printf("  ->  ");
    verif = scanf("%s",card);
    buffer();
    if ((strlen(card) == 4) && (testAnswer(card) == 1)){
    }
    else{
      do {
        printf("Your datas are safe with us please enter your number card.\n");
        printf("  ->  ");
        verif = scanf("%s",card);
        buffer();
      } while ((strlen (card) != 4) || (testAnswer(card) == 0));
    }
    save_stock(stockcita, sizecita, "stockcita.txt");
    save_stock(stocksuv, sizesuv, "stocksuv.txt");
    save_stock(stocksport, sizesport, "stocksport.txt");
    save_stock(stock0, size0, "stock0.txt");
      // conclusion
      clearTerminal();
      printf("Have you been pleased with our services? \n");
      index = yes_no(answer,verif);
      if (index == 1){
      if (v==1){
      }
      else{
        clearTerminal();
        printf("Do you want an account in CYShopShop now ? \n");
        index = yes_no(answer,verif);
        if (index == 1){
          createClient(&client,today,count);
          addClient();
          v=1;
        }
        else{
        }
      }
    }
    else if (index == 0){
      if (v==1){
        clearTerminal();
        printf("Do you want to delete your CYShopShop account ( please give us a chance ;( ) \n");
        index = yes_no(answer,verif);
        if (index == 1){
          printf("So, your account will be deleted...\n");
          //fonction pour supprimer le compte du client
          deleteClient("clients.txt",clients);
          deletedClientCount("deletedClient.txt");
        }
        else{
          printf("Thank you my lord ! I promise we'll never disappoint you again !\n");
        }
      }
    }
    clearTerminal();
    printf("Well, glad to hear it and we hope we'll see you soon ;).\n"); 
    } else {
    printf("So we hope you will come back soon ! Bye bye !\n");
    }
    return 0;
}
void deleteClient(const char* filename, Client *clients) {
  FILE* file = fopen(filename, "r+");
  if (file == NULL) {
    printf("Can't open the file.\n");
    return;
  }

  char line[100];
  long int currentPosition = ftell(file);
  while (fgets(line, sizeof(line), file) != NULL) {
    if (strstr(line, "ID: ") != NULL) {
      int currentID;
      sscanf(line, "ID: %d", &currentID);
      if (currentID == clients->id) {
        fseek(file, currentPosition, SEEK_SET);
        fprintf(file, "ID: -1\n");
        fprintf(file, "\n");
        break;
      }
    }
    currentPosition = ftell(file);
  }

  fclose(file);
  printf("Your account has been deleted... Ciao !\n");
}
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
    printf("Today's date is: %s\n", buffer);
}
void delete_car(Car* stock, int* size, const char* stocktxt){
    print_stock(stock,size);
    int linenumber;
    printf("What is the line number of the car you want to delete ?\n");
    scanf("%d",&linenumber);
    for (int i = linenumber - 1; i < size ; i++){
        stock[i] = stock[i+1];
    }
    size = size - 1;
    print_stock(stock,size);
}

int clientCount(const char* namefile) {
    FILE *file = fopen(namefile, "r");
    if (file == NULL) {
        printf("Can't open the file.\n");
        return -1;
    }

    int count = 0;
    int chara;

    while ((chara = fgetc(file)) != EOF) {
        if (chara == '*') {
            count++;
        }
    }

    fclose(file);
    return count;
}

int deletedClientCount(const char* namefile) {
    FILE *file = fopen(namefile, "r");
    if (file == NULL) {
        printf("Can't open the file.\n");
        return -1;
    }

    int count = 0;
    int chara;

    while ((chara = fgetc(file)) != EOF) {
        if (chara == '%') {
            count++;
        }
    }

    fclose(file);
    return count;
}

Date getDate() {
  Date date;
  
  // def france UTC 
  const int delay = 2;

  // get current hour
  time_t now = time(NULL);
  struct tm *currentDate = gmtime(&now);

  // add UTC+2 to get hour in france
  currentDate->tm_hour += delay;
  mktime(currentDate);

  // divide the date 
  date.day = currentDate->tm_mday;
  date.month = currentDate->tm_mon + 1; 
  date.year = currentDate->tm_year + 1900; // year start at 1900

  // divide the hour
  date.hour = currentDate->tm_hour;
  date.minute = currentDate->tm_min;
  date.second = currentDate->tm_sec;


  return date;
}

void moveToLine(int lineNumber, FILE* file){
  rewind(file);  
  int currentLine = 1;
  char ch;

  while (currentLine < lineNumber) {
    ch = fgetc(file);
    if (ch == '\n') {
        currentLine++;
    }
  }
}

void threeLastBuy(FILE* file, int id) {
  char ch;
  moveToLine(id,file);
  for (int i=0;i<3;i++){
    while ((ch = fgetc(file)) != '|') {
        if (ch == '\n' || ch == EOF) {
            break;  
        }

        printf("%c", ch);
    }
    printf("\n");
  }
  printf("\n");
}

int addClient() {
    FILE *file = fopen("clientCounter.txt", "a");
    if (file == NULL) {
        printf("Can't open the file.\n");
        return 1;
    }

    fputc('*', file);

    fclose(file);
    return 0;
}

void toLower(char *word) {
  int i = 0;
  while (word[i] != '\0') {
    word[i] = tolower(word[i]);
    i++;
  }
}

int testAnswer(const char* tab){
  int i = 0;
  while(tab[i] != '\0'){
    if ((tab[i] < '0') || (tab[i] > '9')){
      return 0;
    }
    i++;
  }
  return 1;
}

void clientsFileToTab(const char* filename, Client** clients, int* numClients) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Can't open the file.\n");
    return;
  }

  // Compter le nombre de clients dans le fichier
  int count = 0;
  char line[100];
  while (fgets(line, sizeof(line), file) != NULL) {
    if (strstr(line, "Name:") != NULL) {
      count++;
    }
  }

  // Allouer de la mémoire pour le tableau de clients
  *clients = (Client*)malloc(count * sizeof(Client));
  *numClients = count;

  // Lire les informations des clients à partir du fichier
  rewind(file);
  int index = 0;
  Client* currentClient = *clients;
  while (fgets(line, sizeof(line), file) != NULL) {
    if (strstr(line, "Name:") != NULL) {
      sscanf(line, "Name: %s", currentClient->name);
      fgets(line, sizeof(line), file); // Sauter la ligne "Surname: "
      sscanf(line, "Surname: %s", currentClient->surname);
      fgets(line, sizeof(line), file); // Sauter la ligne "ID: "
      sscanf(line, "ID: %d", &(currentClient->id));
      currentClient++;
      index++;
    }
  }

  fclose(file);
}

int verif_client(Client* clients, int id, int size){
  int count = 0;
  for(int i = 0; i < size ; i++){
    if (clients[i].id == id){
      count = 1;
    }
  }
  if (count == 1){
    return 1;
  }
  else{
    return 0;
  }
}

void printClientInfo(const Client* clients, int numClients, int clientID) {
  for (int i = 0; i < numClients; i++) {
    printf("Affichage boucle pour cherchert client");
    if (clients[i].id == clientID) {
      printf("Here are your informations :\n");
      printf("Nom : %s\n", clients[i].name);
      printf("Prénom : %s\n", clients[i].surname);
      printf("ID : %d\n", clients[i].id);
      return; // Sortir de la fonction une fois les informations affichées
    }
  }
}

//fonction qui ajoute à l'historique associé au client les voitures qu'il achète
void addHistoric(int choice, Date date, Car* stock, int id) {
  char filename[50] = "historics.txt";
  FILE* file = fopen(filename, "a");
  if (file == NULL) {
    printf("Can't open the file.\n");
  }
 
  
  fprintf(file, " ->  %d/%d/%d : Bought %s %s for %.2f $ |", date.day, date.month, date.year, stock[choice - 1].brand, stock[choice - 1].model, stock[choice - 1].price );
}
void tri5(Car* stock, int size){

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (stock[j].quantity > stock[j + 1].quantity) {
                Car temp = stock[j];
                stock[j] = stock[j + 1];
                stock[j + 1] = temp;
                
            }
        }
     }
     print_stock(stock, 5);
}
void message(){
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
}