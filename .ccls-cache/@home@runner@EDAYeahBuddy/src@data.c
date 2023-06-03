#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/data.h"
#include "../headers/user.h"
#include "../headers/preferences.h"

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
  int contador = 0;
  while(fscanf(archivo, "%s %s %s %s %d %d %d %d %s %s %d %d",     
    &usuarios[contador].username,
    &usuarios[contador].name, 
    &usuarios[contador].mail_adress, 
    &usuarios[contador].description, &usuarios[contador].age, &usuarios[contador].sex, &usuarios[contador].body_weight, &usuarios[contador].city_id, &usuarios[contador].gym_id,&usuarios[contador].workout_days, &usuarios[contador].time_preference, &usuarios[contador].muscle_preference); 
 
  }

  
}
 
