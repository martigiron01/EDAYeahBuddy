#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/main.h"
#include "../headers/preferences.h"
#include "../headers/user.h"
#include "../headers/menu.h"
#include "../headers/friends.h"

userArray * init_array() {
  userArray * u = malloc(sizeof(userArray));
  u->size = 0;
  return u;
}

void add_user(User user,userArray * array){
  array -> size++;
  array -> data = malloc(array -> size * sizeof(User));
  array -> data[array->size - 1] = user;
  user.requestsQueue = (User **)malloc(sizeof(User*));
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
  // Check that the username contains at least 4 characters
    if (strlen(username) < 4) {
        return false;
    }

    // Check that the email contains at least 5 characters (for example, "a@b.c")
    if (strlen(email) < 5) {
        return false;
    }

  // Check that the email contains exactly one @
    int at_count = 0;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            at_count++;
        }
    }
    if (at_count != 1) {
        return false;
    }

    // Check that there are no blank spaces in the username or email
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

    // Check that the email has only allowed characters before and after the @
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

    // If all of the above was valid, return the username and email
    return true;
}

int create_user(char * username, char * email, userArray * array){
  if (check_data(username, email) == false){
    printf("\nIntroduce un usuario y/o correo electrónico válidos!\n");
    return -1;
  }

  // We check if the username or email is already in use
  for(int i = 0; i < array->size; i++){
    if((strcmp(array->data[i].username, username) == 0) || (strcmp(array->data[i].mail_adress, email) == 0)){
      return -1;
    }
  }

  //Finally we create the new user
  User* new_user = (User *) malloc(sizeof(User));
  strcpy(new_user->username, username);
  strcpy(new_user->mail_adress, email);
  new_user->posts = posts_init_stack();
  // We save extra space in the array, if necessary
  if (array->size >= sizeof(array->data) / sizeof(User)) {
    User *new_data = realloc(array->data, (array->size + 1) * sizeof(User));
      if (new_data == NULL) {
        free(new_user); // We free the memory of the new user
        printf("Memory allocation failure!\n");
        return 0; // Memory allocation failure
      }
      array->data = new_data;
  }

  // We add the new user to the end of the array
  array->data[array->size] = *new_user;
  array->size++;

  //We start your substructures
  requests_init_queue(new_user);
  

  // We return 1 indicating that the user was created correctly
  return 1;
}

void print_user_list(userArray * array){
  printf("\n ***LIST OF CURRENT USERS***\n");
  for(int i = 0; i < array->size; i++){
    printf("%s\n", array->data[i].username);
  }
}