#ifndef DICT_H
#define DICT_H
#define MAX_WORD_LENGTH 30
#include "main.h"

typedef struct _pair{
  char word[MAX_WORD_LENGTH];
  int count;
}Pair;

typedef struct _dictionary{
  Pair* data;
  int actual_size;
  int capacity;
}Dictionary;

void init_dictionary(Dictionary* dictionary);

/* PRE: Receives a word and a dictionary
 * POST: Adds the word or increments it's count
 */
void add_word(char * word, Dictionary* dictionary);

void process_post(Dictionary* dictionary, const char* text);

void print_dictionary_ranking(const Dictionary* dictionary);
#endif