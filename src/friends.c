#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/main.h"
#include "../headers/preferences.h"
#include "../headers/user.h"
#include "../headers/friends.h"


bool requests_is_empty(User * user){
  if (user->requests_size == 0) return true;
  return false;
}


void requests_enqueue(User * user, User * new_friend){
  if (requests_is_empty(user)){
    user->requests_first = new_friend;
  }
  user->requestsQueue[user->requests_size] = new_friend;
  user->requests_size ++;
}

void requests_dequeue(User * user){
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