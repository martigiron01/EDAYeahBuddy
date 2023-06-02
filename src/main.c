#include "../headers/main.h"
#include "../headers/menu.h"
#include "../headers/preferences.h"
#include "../headers/user.h"
#include "../headers/data.h"
#include "../headers/logo.h"
#include <stdio.h>
#include <stdlib.h>



int main(void) {
  userArray* array = init_array();

  import_data(array);
  printyeahbuddy();
  show_menu(array);
  free(array->data);
  free(array);
  return 0;
}
