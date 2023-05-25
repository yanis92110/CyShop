#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX_STOCK_SIZE 100
typedef struct{
      char brand[25];
      char model[30];
      char category[20];
      int reference;
      int quantity;
      float price;
      int size; //0=Sportive, 1=City-dweller car, 2=SUV
      
}Car;


typedef struct{
    int hour;
    int minute;
    int second;
    int day;
    int month;
    int year;
}Date;

typedef struct{
    char name[25];
    char surname[25];
    int id;
    float points;
}Client;

  void clearTerminal();
  int testInt(const char* chaine);
  void convertMin(char* chaine);
  void printArrayChar(char* tab);
  void printArrayInt(int* tab);
  void buffer();
  void createClient(Client client);
  int yes_no(char* answer,int verif);
  void showCars(Car* cars, int numCars);
  void print_stock(Car* stock, int size);
  void save_stock(Car* stock, int size, const char* stocktxt);
  void load_stock(Car* stock, int* size, const char* stocktxt);
  void new_car(Car* stock, int* size, int tempsize);
  void printCurrentDate();
  void delete_car(Car* stock, int size, const char* stocktxt);
  void message();
  int main_manager();
  int main_gp_buyer2();
  main_del();
  
  

#endif
