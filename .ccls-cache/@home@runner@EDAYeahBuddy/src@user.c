#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/main.h"
#include "../headers/preferences.h"
#include "../headers/user.h"

userArray * init_array() {
  userArray * u = malloc(sizeof(userArray));
  u->size = 0;
  return u;
}

void add_user(User user,userArray * array){
  array -> size++;
  array -> data = malloc(array -> size * sizeof(User));
  array -> data[array->size - 1] = user;
}

User* search_user(char * username, userArray * array){
  for(int i = 0; i < array->size; i++){
    if(strcmp(username, array->data[i].username) == 0){
      return &array->data[i];
    }
  }
  return NULL;
}



bool check_data(char * username, char * email){
  // Comprueba que el nombre de usuario contenga al menos 4 caracteres
    if (strlen(username) < 4) {
        return false;
    }

    // Comprueba que el correo electrónico contenga al menos 5 caracteres (por ejemplo, "a@b.c")
    if (strlen(email) < 5) {
        return false;
    }

  // Comprueba que el correo electrónico contenga exactamente un @
    int at_count = 0;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            at_count++;
        }
    }
    if (at_count != 1) {
        return false;
    }

    // Comprueba que no haya espacios en blanco en el nombre de usuario o en el correo
    for (int i = 0; i < strlen(username); i++) {
        if (isspace(username[i])) {
            return false;
        }
    }
    for (int i = 0; i < strlen(email); i++) {
        if (isspace(email[i])) {
            return false;
        }
    }

    // Comprueba que el correo electrónico tenga solo caracteres permitidos antes y después del @
    bool before_at = true;
    bool after_at = false;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            before_at = false;
            after_at = true;
        } else if (before_at && !isalnum(email[i]) && email[i] != '.' && email[i] != '-' && email[i] != '_') {
            return false;
        } else if (after_at && !isalnum(email[i]) && email[i] != '.' && email[i] != '-') {
            return false;
        }
    }

    // Si todo lo anterior fue válido devuleve el usario y correo electrónico
    return true;
}

int create_user(char * username, char * email, userArray * array){
  if (check_data(username, email) == false){
    printf("\nIntroduce un usuario y/o correo electrónico válidos!\n");
    return -1;
  }

  // Comprobamos si el username o correo electrónico ya están en uso
  for(int i = 0; i < array->size; i++){
    if((strcmp(array->data[i].username, username) == 0) || (strcmp(array->data[i].mail_adress, email) == 0)){
      return -1;
    }
  }

  // Finalmente creamos el nuevo usuario
    User* new_user = (User *) malloc(sizeof(User));
  strcpy(new_user->username, username);
  strcpy(new_user->mail_adress, email);

  // Guardamos espacio extra en el array, si es necesario
  if (array->size >= sizeof(array->data) / sizeof(User)) {
        User *new_data = realloc(array->data, (array->size + 1) * sizeof(User));
        if (new_data == NULL) {
            free(new_user); // Liberamos la memoria del nuevo usuario
            return 0; // Fallo en la asignación de memoria
        }
        array->data = new_data;
    }

    // Agregamos el nuevo usuario al final del array
    array->data[array->size] = *new_user;
    array->size++;

    // Devolvemos 1 indicando que el usuario fue creado correctamente
    return 1;
}

void print_user_list(userArray * array){
  printf("\n ***LISTA DE USUARIOS ACTUAL***:\n");
  for(int i = 0; i < array->size; i++){
    printf("%s\n", array->data[i].username);
  }
}