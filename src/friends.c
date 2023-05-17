#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/main.h"
#include "../headers/preferences.h"
#include "../headers/user.h"
#include "../headers/friends.h"

bool friends_is_empty(User * user){
  if (user->friend_size == 0) return true;
  return false;
}

void friends_enqueue(User * user, User * new_friend){
  if (friends_is_empty(user)){
    user->friend_first = new_friend;
  }
  user->friendQueue[user->friend_size] = new_friend;
  user->friend_size ++;
}