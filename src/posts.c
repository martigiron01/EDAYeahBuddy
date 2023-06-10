#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/dict.h"
#include "../headers/posts.h"

char* create_post() {
  char * post_txt = (char*) malloc(sizeof(char) * MAX_POST_LENGTH);
  printf("ADD A POST\n\n");
  printf("What do you want to say? (Max. %d characters)\n", MAX_POST_LENGTH - 20);
  bool correct_input = false;
  while(!correct_input){
    
    fgets(post_txt, MAX_POST_LENGTH, stdin);

    //We delete the \n of the string
    post_txt[strcspn(post_txt, "\n")] = '\0';
    if(strlen(post_txt) > MAX_POST_LENGTH - 19) {
      printf("\nMax characters reached! [120]\nMessage cropped\n");
    }else{
    correct_input = true;
    }
  }
  return post_txt;
}

postStack* posts_init_stack() {
  postStack* stack = (postStack*) malloc(sizeof(postStack));
  stack->top = -1;
  stack->data = (char**) malloc(sizeof(char*));
  return stack;
}

bool posts_is_empty(postStack* stack) {
  return stack->top == -1;
}

void push_post(postStack* stack, char* post, Dictionary* dictionary) {
  stack->data = (char**) realloc(stack->data, (stack->top + 2) * sizeof(char*));
  stack->top++;
  //stack->data[stack->top] = post;
  stack->data[stack->top] = malloc((strlen(post)+1) * sizeof(char));

  strcpy(stack->data[stack->top], post);

  //We add the post words to the dictionary
  process_post(dictionary, post);
}

int pop_post(postStack* stack) {
  if(posts_is_empty(stack)) return 0;
  else {
    free(stack->data[stack->top]);
    stack->top--;
    return 1;
  }
}