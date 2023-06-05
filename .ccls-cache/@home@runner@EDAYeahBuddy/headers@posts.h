#ifndef POSTS_H

#include "main.h"
#include <stdio.h>
#include <stdbool.h>

#define MAX_POST_LENGTH 120

typedef struct _postStack {
  char** data;
  int top;
} postStack;

void posts_init_stack();
bool posts_is_empty(postStack* stack);
void push(postStack* stack, char* post);
int pop(postStack* stack);

#endif