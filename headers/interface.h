#ifndef TXT_H
#define TXT_H
#include "main.h"
#include "user.h"
#include <string.h>

// Longitud máxima de una línea sin contar asteríscos y márgenes
#define MAX_LINE_LENGTH 25

/* PRE: receives an id
 * 
 */
char * sex_char(int id);

/* PRE: receives a pointer to a string
 * POST: returns x number of such that x + string length = MAX_LINE_LENGTH
 */
char * spaces(char* str);

char* divide_str(char* str, int line_length);

void print_user_info(User* user);

#endif