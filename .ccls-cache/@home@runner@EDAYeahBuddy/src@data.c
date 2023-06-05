#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/data.h"
#include "../headers/user.h"
#include "../headers/preferences.h"

int line_count(const char * filename){
  int lines = 1;
  char character;
  FILE * fp = fopen(filename, "r");
  
  //Error abriendo archivo
  if(fp == NULL) return 0;

  //Loop que recorre todo el archivo hasta el final copiando carácteres a character
  while((character = fgetc(fp)) != EOF){

    //Suma 1 a lines cuando encuentra saltos de linea
    if(character == '\n'){
      lines++;
    }
  }
  return lines;
}

void save_data(userArray* array){
  FILE* file = fopen("userArray.dat", "wb");
  if (file != NULL) {
    fwrite(&array->size, sizeof(array->size), 1, file); // Guarda el tamaño del array dinámico
    fwrite(array->data, sizeof(User), array->size, file); // Guarda los datos del array dinámico
    fclose(file);
  }
}

void import_data(userArray* importedUserArray){
  FILE* file = fopen("userArray.dat", "rb");
  if (file != NULL) {
    fread(&importedUserArray->size, sizeof(importedUserArray->size), 1, file); // Lee el tamaño del array dinámico
    importedUserArray->data = malloc(importedUserArray->size * sizeof(User)); // Asigna memoria para el array dinámico
    fread(importedUserArray->data, sizeof(User), importedUserArray->size, file); // Lee los datos del array dinámico
    fclose(file);
  }
}

User* presentCSV(const char* preset, int*num_users){
  FILE* archivo = fopen(preset, "r");
  if(archivo == NULL) {
    printf("No se puede abrir el archivo\n");
    return NULL;  
  }
  char linea[100];
  User* usuarios = malloc(sizeof(User) * 20);  //Tenim 20 usuaris 
  if (usuarios == NULL) {
    printf("Error al asignar memoria\n");
    fclose(archivo);
    return NULL;
  }
  int contador = 0;
  while(fscanf(archivo, "%s %s %s %s %d %d %d %d %d %d %d %d",     
    usuarios[contador].username,
    usuarios[contador].name, 
    usuarios[contador].mail_adress, 
    usuarios[contador].description, 
    &usuarios[contador].age, 
    &usuarios[contador].sex, 
    &usuarios[contador].body_weight, 
    &usuarios[contador].city_id, 
    &usuarios[contador].gym_id,
    &usuarios[contador].workout_days,   
    &usuarios[contador].time_preference, 
    &usuarios[contador].muscle_preference) == 12) {
    contador ++;
    }

  *num_users = contador;
  fclose(archivo);
  return usuarios;
 
  }


void printUsers(User* usuarios, int num_users) {
  printf("Usuarios cargados:\n");
  for (int i = 0; i < num_users; i++) {
    printf("Username: %s\n", usuarios[i].username);
    printf("Name: %s\n", usuarios[i].name);
    printf("Mail Address: %s\n", usuarios[i].mail_adress);
    printf("Description: %s\n", usuarios[i].description);
    printf("Age: %d\n", usuarios[i].age);
    printf("Sex: %d\n", usuarios[i].sex);
    printf("Body Weight: %d\n", usuarios[i].body_weight);
    printf("Height: %d\n", usuarios[i].height);
    printf("City ID: %d\n", usuarios[i].city_id);
    printf("Gym ID: %d\n", usuarios[i].gym_id);
    printf("Workout Days: %d\n", usuarios[i].workout_days);
    printf("Time Preference: %d\n", usuarios[i].time_preference);
    printf("Muscle Preference: %d\n", usuarios[i].muscle_preference);
    printf("-----------------------------\n");
  }
}

void processUsers() { 
  int num_users;
  User* usuarios = presentCSV("preset.txt", &num_users);

  if (usuarios != NULL) {
    printUsers(usuarios, num_users);
    free(usuarios);
  }
}