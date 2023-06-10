#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/main.h"
#include "../headers/dict.h"

void init_dictionary(Dictionary* dictionary){
  dictionary->data = (Pair*) malloc(1000 * sizeof(Pair));
  if(dictionary->data == NULL){
    printf("Saving memory error!");
    return;
  }
  dictionary->actual_size = 0;
  dictionary->capacity = 1000;
}

void add_word(char * word, Dictionary* dictionary){
  
 //We search for the word on the dictionary
  for(int i = 0; i < dictionary->actual_size; i++){
    //If already on dictionary add one to count
    if(strcmp(dictionary->data[i].word, word) == 0){
      dictionary->data[i].count++;
      return;
    }
  }

  //If not on dictionary:
  //First we check if dictionary is full
  if(dictionary->actual_size >= dictionary->capacity){
    dictionary->capacity += 100;
    dictionary->data = (Pair*)realloc(dictionary->data, dictionary->capacity * sizeof(Pair));
  }
  
  //Now we add it
  strcpy(dictionary->data[dictionary->actual_size].word,word);
  dictionary->data[dictionary->actual_size].count = 0;
  dictionary->actual_size++;
}

void process_post(Dictionary* dictionary, const char* text) {
  char* word;
  
  //We make a copy of the original text
  char* textCopy = (char*)malloc(strlen(text) + 1);
  strcpy(textCopy, text);

  //We divide the text in words by spaces
  word = strtok(textCopy, " "); 

  //We add all words to the dictionary
  while (word != NULL) {
      add_word(word, dictionary);
      word = strtok(NULL, " ");  //Next word
  }

  free(textCopy);
}

void print_dictionary_ranking(const Dictionary* dictionary) {
  // We sort the dictionary based on word count using bubble sort
  Pair temp;
  int i, j;
  for (i = 0; i < dictionary->actual_size - 1; i++) {
    for (j = 0; j < dictionary->actual_size - i - 1; j++) {
      if (dictionary->data[j].count < dictionary->data[j + 1].count) {
          temp = dictionary->data[j];
          dictionary->data[j] = dictionary->data[j + 1];
          dictionary->data[j + 1] = temp;
      }
    }
  }

  // Now we print the ranking
  int count;
  if (dictionary->actual_size < 10) {
    count = dictionary->actual_size;
  } else {
    count = 10;
  }

  for (i = 0; i < count; i++) {
    if (i < dictionary->actual_size) {
      printf("%d. \"%s\": %d times\n", i + 1, dictionary->data[i].word, dictionary->data[i].count);
    }
  }
}

