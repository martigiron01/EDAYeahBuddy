#ifndef TXT_H
#define TXT_H
#include "main.h"
#include "user.h"
#include <string.h>

// Maximum length of a line not counting asterisks and margins
#define MAX_LINE_LENGTH 25


/* PRE: receives a positive integer i
 * POST: prints a line of i "-"
 */
void print_line(int i);

/* PRE: receives an id
 * 
 */
char * sex_char(int id);

/* PRE: receives a pointer to a string
 * POST: returns x number of such that x + string length = MAX_LINE_LENGTH
 */
int spaces(char* str);

char* divide_str(char* str, int line_length);

void print_user_info(User* user);

#endif