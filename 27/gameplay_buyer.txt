#include "header.h"

// Tableau de voitures sportives
Car sportivesCars[] = {
    {"Audi", "Sportive", "R8", 001, 150000.0},     // sportivesCars[0]
    {"BMW", "Sportive", "M4", 002, 130000.0},      // sportivesCars[1]
    {"Porsche", "Sportive", "911", 003, 180000.0}, // sportivesCars[2]
    {"BMW", "Sportive", "M5", 004, 135000.0},       // sportivesCars[3]
    {"Honda", "Sportive", "Civic Type R", 005, 39000.0}, // sportivesCars[4]
    {"Ferrari", "Sportive", "F40", 006, 1300000.0},      // sportivesCars[5]
    {"Toyota", "Sportive", "Supra", 007, 52500.0},        // sportivesCars[6]
};
int numSportives = sizeof(sportivesCars) / sizeof(sportivesCars[0]);

// Tableau de voitures SUV
Car SUVCars[] = {
    {"Audi", "SUV", "Q7", 101, 90000.0},       // SUVCars[0]
    {"BMW", "SUV", "X5", 102, 95000.0},        // SUVCars[1]
    {"Mercedes", "SUV", "GLE", 103, 100000.0}, // SUVCars[2]
    {"Rolls Royce", "SUV", "Cullinan", 104, 400000.0}, // SUVCars[3]
    {"Lamborghini", "SUV", "Urus", 105, 205000.0}, // SUVCars[4]
    {"Honda", "SUV", "FR-V", 106, 24000.0}, // SUVCars[5]

};
int numSUV = sizeof(SUVCars) / sizeof(SUVCars[0]);

// Tableau de voitures citadines
Car cityCars[] = {
    {"Renault", "Citadine", "Clio", 201, 20000.0},    // cityCars[0]
    {"Peugeot", "Citadine", "208", 202, 22000.0},     // cityCars[1]
    {"Volkswagen", "Citadine", "Polo", 203, 19000.0}, // cityCars[2]
    {"Citroën", "Citadine", "C3", 204, 17000.0},     // cityCars[3]
    {"Cupra", "Citadine", "Born", 205, 39000.0}, // cityCars[2]

};
int numCityCars = sizeof(cityCars) / sizeof(cityCars[0]);

// Fonction principale
int main_gp_buyer() {
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
  FILE *file = fopen(filename, "w");
  Date today;
  int r = 0;
  int count = 0;
  int v = 0;

  // Nettoyer le terminal
  clearTerminal();

  int id = 0;
  int index;
  Client client;

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
             "'no')\n");
      index = yes_no(answer, verif);
      if (index == 1) {
        createClient(client);
        v=1;
      } else if (index == 0) {
        printf("No problem. Let's start to shop !\n");
      }
    }
  } 
  else if (index == 0) {
    printf("Do you want to create an account in our shop ? (enter 'yes' or "
           "'no')\n");
    index = yes_no(answer, verif);
    if (index == 1) {
      createClient(client);
      v=1;
    } else if (index == 0) {
      clearTerminal();
      printf("No problem. Let's start to shop !\n");
    }
  }

  clearTerminal();
goback:
  do {
    printCurrentDate();
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
      showCars(sportivesCars, numSportives);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to the menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 1 && reference <= numSportives) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 1 || reference > numSportives);
      }
      buffer();
      choice = reference;
      fprintf(file, "Date: %d/%d/%d à %d : %d : %d, Car: %s %s , Price: %.2f\n",
              today.day, today.month, today.year, today.hour, today.minute,
              today.second, sportivesCars[choice - 1].brand,
              sportivesCars[choice - 1].model, sportivesCars[choice - 1].price);
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             sportivesCars[choice - 1].brand, sportivesCars[choice - 1].model);
      cart = cart + sportivesCars[choice - 1].price;
      reference = 0;

    } else if (category == 2) {
      showCars(SUVCars, numSUV);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 101 && reference <= numSUV + 100) {
      } else if (verif == 1 && reference == 0) {
        clearTerminal();
        goto goback;
      } else {
        do {
          printf("Please enter a valid number.\n");
          buffer();
          verif = scanf("%d", &reference);
          printf("  ->  ");
        } while (verif != 1 || reference < 101 || reference > numSUV + 100);
      }
      buffer();
      choice = reference - 100;
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             SUVCars[choice - 1].brand, SUVCars[choice - 1].model);
      cart = cart + SUVCars[choice - 1].price;
      reference = 0;

    } else if (category == 3) {
      showCars(cityCars, numCityCars);
      printf("=============================================================\n");
      printf("Which car do you want to buy ? (enter the reference of the car that you want or enter '0' to come back to menu)\n");
      printf("  ->  ");
      verif = scanf("%d", &reference);
      if (verif == 1 && reference >= 201 && reference <= numCityCars + 200) {
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
                 reference > numCityCars + 200);
      }
      buffer();
      choice = reference - 200;
      printf("Congrats ! You're now the proud owner of a %s %s !\n",
             cityCars[choice - 1].brand, cityCars[choice - 1].model);
      cart = cart + cityCars[choice - 1].price;
      reference = 0;
    }

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
  if(v==1){
    if(client.points!=0){
      if(cart-client.points<0){
        printf("Thanks for being loyal to our services ! Thanks to your fidelity your cart is free ! :O\n");
        client.points=client.points-cart;
        cart=0;
      }
      else{
        cart=cart-client.points;
        printf("Jackpot ! You have %f fidelity points on your account !\n You have a sale of %f$ to your cart!\nYou will now pay %f$",client.points, client.points, cart);
        client.points=0;
      }
    }
  }
  if (cart != 0) {
    printf("Please enter your card number. (it's for a friend) \n");
    printf("  ->  ");
    verif = scanf("%s",card);
    buffer();
    if ((strlen(card) == 4) && (testInt(card) == 1)){
    }
    else{
      do {
        printf("Your datas are safe with us please enter your number card.\n");
        printf("  ->  ");
        verif = scanf("%s",card);
        buffer();
      } while ((strlen (card) != 4) || (testInt(card) == 0));
    }
      // conclusion
      printf("Have you been pleased with our services? (enter 'yes' or 'no')\n");
  index = yes_no(answer,verif);
  if (index == 1){
    if (v==1){
    }
    else{
      printf("Do you want an account in CYShopShop now ? (enter 'yes' or 'no')\n");
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
    printf("You have %f fidelity points ! 1 fidelity point = 1€\nSo you have a %f sale on your next buy!\n",sale ,sale);
  }
  else if (index == 0){
    if (v==1){
      clearTerminal();
      printf("Do you want to delete your CYShopShop account ( please give us a chance ;( ) (enter 'yes' or 'no')\n");
      index = yes_no(answer,verif);
      if (index == 1){
        printf("So, your account will be deleted...\n");
        //fonction pour supprimer le compte client
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
