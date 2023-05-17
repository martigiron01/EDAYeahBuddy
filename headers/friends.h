#ifndef FRIENDS_H
#define FRIENDS_H

#include "main.h"
#include "user.h"
#include <stdbool.h>

bool friends_is_empty(User * user);

void friends_enqueue(User * user, User * new_friend);

#endif