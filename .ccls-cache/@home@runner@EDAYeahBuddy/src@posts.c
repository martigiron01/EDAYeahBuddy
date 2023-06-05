#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../headers/posts.h"

void posts_init_stack() {
  postStack* stack = (postStack*) malloc(sizeof(postStack));
  stack->top = -1;
  stack->data = (char**) malloc(2 * sizeof(char*));
}

bool posts_is_empty(postStack* stack) {
  return stack->top == -1;
}

void push(postStack* stack, char* post) {
  stack->data = (char**) realloc(stack->data, sizeof(stack->data) + sizeof(char*));
  stack->top++;
  stack->data[stack->top] = post;
}

int pop(postStack* stack) {
  if(posts_is_empty(stack)) return 0;
  else {
    free(stack->data[stack->top]);
    stack->top--;
    return 1;
  }
}