#ifndef USER_H
#define USER_H

#include "main.h"
#include "posts.h"
#include <stdbool.h>

typedef struct _friendsNode {
  char username[MAX_LENGTH];
  struct _friendsNode* next;
} friendsNode;

typedef struct _user {
  char username[MAX_LENGTH];
  char name[MAX_LENGTH];
  char mail_adress[MAX_LENGTH];
  struct _user** requestsQueue;
  struct _user* requests_first;
  struct _friendsNode* friends_first;
  int requests_size;
  postStack* posts;
  char description[MAX_DESCRIPTION];
  int age;
  int sex;
  int body_weight;
  int height;
  int city_id;
  int gym_id;
  int workout_days;
  int time_preference;
  int muscle_preference;
} User;

typedef struct _userArray {
  int size;
  User* data;
} userArray;


/* PRE: -
 * POST: Return an empty Array
 */
userArray* init_array();

/* PRE: 
 * POST:
 */
void add_user(User user,userArray * array);

/* PRE: Receives a username and the main array
 * POST: Returns the user address or NULL if not found
 */
User* search_user(char* username, userArray* array);

/* PRE: Receives a username and an email
 * POST: Checks it's validity and returns TRUE or FALSE
 */
bool check_data(char * username, char * email);

/* PRE: Receives a username, an email and the array
 *POST: Creates the user struct and adds it to the array
 */
int create_user(char * username, char * email, userArray * array);

/* PRE: Receives an initialized array struct
 * POST: Prints the user list
 */
void print_user_list(userArray* array);

#endif