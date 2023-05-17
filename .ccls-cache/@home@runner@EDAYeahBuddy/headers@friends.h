#ifndef FRIENDS_H
#define FRIENDS_H

#include "main.h"
#include "user.h"
#include <stdbool.h>

/* PRE: Receives an initialized user
 * POST: Return true if the user do not have friend requests, else false
 */
bool requests_is_empty(User * user);

/* PRE: Receives an initialized user and a user who requests friendship
 * POST: Adds the user to the requests queue
 */
void requests_enqueue(User * user, User * new_friend);

#endif