#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#define MAX_STOCK_SIZE 100
#define MAX_TAB 304
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
  void createClient(Client* client, Date date, int count);
  int yes_no(char* answer,int verif);
  void showCars(Car* cars, int numCars);
  void print_stock(Car* stock, int size);
  void save_stock(Car* stock, int size, const char* stocktxt);
  void load_stock(Car* stock, int* size, const char* stocktxt);
  void new_car(Car* stock, int* size, int tempsize);
  void printCurrentDate();
  void delete_car(Car* stock, int* size, const char* stocktxt);
  int clientCount(const char* namefile);
  int deletedClientCount(const char* namefile);
  Date getDate();
  void moveToLine(int lineNumber, FILE* file);
  void threeLastBuy(FILE *file, int id);
  int addClient();
  void toLower(char *word);
  int testAnswer(const char* tab);
  void clientsFileToTab(const char* filename, Client** clients, int* numClients);
  int verif_client(Client* clients, int id, int size);
  void printClientInfo(const Client* clients, int numClients, int clientID);
  void addHistoric(int choice, Date date, Car* stock, int id);
  void deleteClient(const char* filename, Client *clients);
  void tri5(Car* stock,int size);
  void message();

#endif
