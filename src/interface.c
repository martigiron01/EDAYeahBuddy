// https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20

#include "../headers/interface.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_line(int i) {
  printf("\n");
  while (i > 0) {
    printf("-");
    i--;
  }
  printf("\n");
}

char *sex_char(int id) {
  char *sex_char = (char *)malloc(sizeof(char));

  if (id == 0) {
    sex_char = "F";
  } else if (id == 1) {
    sex_char = "M";
  }

  return sex_char;
}

int spaces(char *str) {
  int spaces = MAX_LINE_LENGTH - strlen(str);
  return spaces;
}

char *divide_str(char *str, int line_length) {
  for (int i = line_length; i > 0; i--) {

    if (strcmp(&str[i], " ") == 0) {
      str[i] = '\n';

      return " ";

    } else
      return "n";
  }
  return "f";
}

void print_user_info(User *user) {
  char *username = user->username;
  char *description = user->description;
  int age = user->age;
  int sex = user->sex;
  int height = user->height;
  int weight = user->body_weight;

  /*
  Prints the user information in the following format:

  * * * * * * * * * * * * * * * *
  *  [Username]                 *
  *                             *
  *  [Description]              *
  * * * * * * * * * * * * * * * *
  *  Información personal       *
  *                             *
  *  Edad: [Age]                *
  *  Sexo: [Sex]                *
  *  Altura: [Height]           *
  *  Peso: [Weight]             *
  * * * * * * * * * * * * * * * *
  */

  printf("\n* * * * * * * * * * * * * * * *\n*  %s", username);
  for (int i = 0; i < spaces(username); i++) {
    putchar(' ');
  }
  printf("  *\n*                             *\n*  %s", description);
  for (int i = 0; i < spaces(description); i++) {
    putchar(' ');
  }
  printf("  *\n* * * * * * * * * * * * * * * *\n");
  printf("*  Información personal       *\n*                             *\n");
  printf("*  Edad: %d                   *\n*  Sexo: %s                    *\n* "
         " Altura: %d cm             *\n*  Peso: %d kg                *\n* * * "
         "* * * * * * * * * * * * *\n",
         age, sex_char(sex), height, weight);
}