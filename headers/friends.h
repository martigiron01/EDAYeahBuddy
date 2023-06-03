#ifndef FRIENDS_H
#define FRIENDS_H

#include "main.h"
#include "user.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//***REQUESTS QUEUE***

void requests_init_queue(User* user);

/* PRE: Receives an initialized user
 * POST: Return true if the user do not have friend requests, else false
 */
bool requests_is_empty(User* user);

/* PRE: Receives an initialized user and a user who requests friendship
 * POST: Adds the user to the requests queue
 */
void requests_enqueue(User* user, User* new_friend);

/* PRE: Receives an initialized user
 * POST: Dequeues the first request of the user
 */
void requests_dequeue(User* user);

/* PRE: Receives an initialized user
 * POST: Prints it's requests queue
 */
void requests_print(User* user);

//***FRIENDS LIST***
void add_friend(User* user, User* sender);
void print_friends_list(User* user);

#endif