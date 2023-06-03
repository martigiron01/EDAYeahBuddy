#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/main.h"
#include "../headers/preferences.h"
#include "../headers/user.h"
#include "../headers/friends.h"
#include "../headers/menu.h"

//***REQUESTS QUEUE***

void requests_init_queue(User* user) {
  user->requests_first = NULL;
  user->requests_size = 0;
  user->requestsQueue = (User **) malloc(sizeof(User *));
}

bool requests_is_empty(User* user){
  if (user->requests_size == 0) return true;
  return false;
}

void requests_enqueue(User* user, User* new_friend){
  user->requestsQueue = (User **) realloc(user->requestsQueue, (user->requests_size + 2) * sizeof(User*));
  
  if (user->requestsQueue == NULL) {
    printf("\nMemory error!\n");
    return;
  }
  if (requests_is_empty(user)){
    user->requests_first = new_friend;
  }
  
  user->requestsQueue[user->requests_size] = new_friend;
  user->requests_size ++;
}

void requests_dequeue(User* user){
  if (user->requests_size > 0) {
    User *firstUser = user->requestsQueue[0];
    for (int i = 0; i < user->requests_size - 1; i++) {
      user->requestsQueue[i] = user->requestsQueue[i + 1];
    }
    user->requestsQueue[user->requests_size - 1] = NULL;
    user->requests_size--;
    user->requests_first = user->requestsQueue[0];
    free(firstUser);
  }
}

void requests_print(User * user){
  printf("*** SOLICITUDES DE AMISTAD ***\n");
  
  if(requests_is_empty(user)) {
    printf("\nYou have no requests!\n");
    return;
  }

  int requests_num = user->requests_size;
  for(int i = 0; i < requests_num; i++){
    //Asks for accept or decline
    printf("\n%d. %s\n", i, user->requestsQueue[i]->username);
    printf("[accept] or [decline]:\n");
    char option[MAX_LENGTH];
    bool choice = false;
    bool validInput = false;
    while (!validInput) {
      scanf("%s", option);
    
      choice = yes_or_no(option);

      switch (choice) {
        case true:
          printf("Solicitud aceptada!\n");
          add_friend(user, user->requestsQueue[i]);
          requests_dequeue(user);
          validInput = true;
          break;

        case false:
          printf("Solicitud denegada!\n");
          requests_dequeue(user);
          validInput = true;
          break;

        default:
          printf("Opción incorrecta! Introduzca [accept] o [decline]:\n");
          flush_input();
          break;
      }
      flush_input();
    }

    //
  }
}


//***FRIENDS LIST***

void print_friends_list(User* user) {
  friendsNode* current = user->friends_first;
  
  // If the linked list is empty, user has no added friends
  if(current == NULL) printf("Aún no has agregado a nadie.");
  else printf("Lista de amigos:\n\n");

  // Print all friends names until it reaches the last
  while(current != NULL) {
    printf("%s\n", current->name);
    current = current->next;
  }
}

void add_friend(User* user, User* sender) {
  friendsNode* current = user->friends_first;
  friendsNode* newFriend = (friendsNode*) malloc(sizeof(friendsNode));

  strcpy(newFriend->name, sender->name);
  newFriend->next = NULL;

  if(current == NULL) {
    // If the linked list is empty, add the new friend as the head
    user->friends_first = newFriend;
  } else {
    // Find the last friend in the linked list
    while(current->next != NULL) {
      current = current->next;
    }
    // Add the new friend to the end of the list
    current->next = newFriend;
  }

}