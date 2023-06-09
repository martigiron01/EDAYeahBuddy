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
  user->requestsQueue = (User**) malloc(sizeof(User*));
}

bool requests_is_empty(User* user){
  if (user->requests_size == 0) return true;
  return false;
}

void requests_enqueue(User* user, User* new_friend){
  user->requestsQueue = (User**) realloc(user->requestsQueue, (user->requests_size + 2) * sizeof(User*));
  
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

void requests_print(User* user){
  printf("*** FRIENDSHIP REQUESTS ***\n");
  
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
          printf("Request accepted!\n");
          add_friend(user, user->requestsQueue[i]);
          requests_dequeue(user);
          validInput = true;
          break;

        case false:
          printf("Request denied!\n");
          requests_dequeue(user);
          validInput = true;
          break;

        default:
          printf("Wrong choice! Please enter [accept] or [decline]:\n");
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
  if(current == NULL) printf("You haven't added anyone yet.");
  else printf("Friends list:\n\n");

  // Print all friends names until it reaches the last
  while(current != NULL) {
    printf("%s\n", current->username);
    current = current->next;
  }
}

void add_friend(User* user, User* sender) {
  friendsNode* current = user->friends_first;
  friendsNode* newFriend = (friendsNode*) malloc(sizeof(friendsNode));

  strcpy(newFriend->username, sender->username);
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

  //Now the same but for the sender
  friendsNode* current2 = sender->friends_first;
  friendsNode* newFriend2 = (friendsNode*) malloc(sizeof(friendsNode));

  strcpy(newFriend2->username, user->username);
  newFriend2->next = NULL;

  if(current2 == NULL) {
    // If the linked list is empty, add the new friend as the head
    sender->friends_first = newFriend2;
  } else {
    // Find the last friend in the linked list
    while(current2->next != NULL) {
      current2 = current2->next;
    }
    // Add the new friend to the end of the list
    current2->next = newFriend2;
  }
}