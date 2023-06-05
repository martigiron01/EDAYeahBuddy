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
* PRE: Receives a userArray
* POST: Saves the array siza and data into userArray.dat
*/
void save_data(userArray* array);

/* 
* PRE: Reads a "userArray.dat" file with the previous arrays saved
* POST: Returns the array in userArray format
*/
void import_data(userArray* importedUserArray);


void printUsers(User* usuarios, int num_users);

void processUsers();

#endif