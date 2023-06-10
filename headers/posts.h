#ifndef POSTS_H
#define POSTS_H

#include "main.h"
#include "dict.h"
#include <stdio.h>
#include <stdbool.h>


#define MAX_POST_LENGTH 140

typedef struct _postStack {
  char** data;
  int top;
} postStack;

char* create_post();

postStack* posts_init_stack();
bool posts_is_empty(postStack* stack);
void push_post(postStack* stack, char* post, Dictionary * dictionary);
int pop_post(postStack* stack);

#endif