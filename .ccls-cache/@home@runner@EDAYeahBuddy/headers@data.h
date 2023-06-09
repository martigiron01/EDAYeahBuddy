#ifndef DATA_H
#define DATA_H
#include "user.h"
#include <stdio.h>

/* 
* PRE: Receives the filename as a string
* POST: Counts the number of lines
*/
int line_count(const char * filename);

/* 
* PRE: Reads the files with users and posts
* POST: Imports it all
*/
void import_data(userArray* array, char* users_filename, char* posts_filename, Dictionary * dictionary);

/* 
* PRE: Receives a user and a .txt file name as string
* POST: Writes the user data on a file .txt
*/
void save_user(User* user, char* filename);

void save_post(char* post, User * user, char* filename);

#endif