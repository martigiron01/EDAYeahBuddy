#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../headers/posts.h"

char* create_post() {
  char* post_txt = (char*) malloc(sizeof(char) * MAX_POST_LENGTH);
  
  printf("ADD A POST\n\n");
  printf("What do you want to say? (Max. %d characters)", MAX_POST_LENGTH);
  scanf("%s", post_txt);

  return post_txt;
}

void posts_init_stack() {
  postStack* stack = (postStack*) malloc(sizeof(postStack));
  stack->top = -1;
  stack->data = (char**) malloc(2 * sizeof(char*));
}

bool posts_is_empty(postStack* stack) {
  return stack->top == -1;
}

void push_post(postStack* stack, char* post) {
  stack->data = (char**) realloc(stack->data, sizeof(stack->data) + sizeof(char*));
  stack->top++;
  stack->data[stack->top] = post;
}

int pop_post(postStack* stack) {
  if(posts_is_empty(stack)) return 0;
  else {
    free(stack->data[stack->top]);
    stack->top--;
    return 1;
  }
}