#ifndef TXT_H
#define TXT_H
#include "main.h"
#include "user.h"
#include <string.h>

/* PRE: receives an id
 * 
 */
char * sex_char(int id);

/* 
 * 
 */
char * spaces(char* str);

char* divide_str(char* str, int line_length);

void print_user_info(User* user);

#endif