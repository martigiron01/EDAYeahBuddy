#include "../headers/main.h"
#include "../headers/menu.h"
#include "../headers/preferences.h"
#include "../headers/user.h"
#include "../headers/data.h"
#include "../headers/logo.h"
#include "../headers/dict.h"
#include <stdio.h>
#include <stdlib.h>



int main(void) {
  userArray* array = init_array();
  Dictionary* global_words = (Dictionary*)malloc(sizeof(Dictionary));
  init_dictionary(global_words);
  import_data(array, "users.txt", "posts.txt", global_words);
  printyeahbuddy();  // Print logo
  show_menu(array, global_words);
  free(array);
  free(global_words->data);
  return 0;
}
