#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/data.h"
#include "../headers/user.h"

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