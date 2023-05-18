// https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20

#include "../headers/interface.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * sex_char(int id) {
  char* sex_char = (char*) malloc(sizeof(char));
  if(id == 0) {
    sex_char = "F";
  } else if(id == 1) {
    sex_char = "M";
  }

  return sex_char;
}

char * spaces(char* str) {
  int spaces = MAX_LINE_LENGTH - strlen(str);
  char* spaces_str = (char*) malloc(sizeof(char) * spaces);
  
  for(int i = 0; i < spaces; i++) {
    spaces_str[i] = ' ';
  }
  return spaces_str;
}

char* divide_str(char* str, int line_length) {
  for(int i = line_length; i > 0; i--) {
    if(strcmp(&str[i], " ") == 0) {
      str[i] = '\n';
      return " ";
    } else return "n";
  }
  return "f";
}

void print_user_info(User* user) {
  char* username = user->username;
  char* description = user->description;
  int age = user->age;
  int sex = user->sex;
  int height = user->height;
  int weight = user->body_weight;

  /*
  Imprime la información del usuario con el formato siguiente:
  
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

  printf("\n* * * * * * * * * * * * * * * *\n*  %s%s  *\n*                             *\n*  %s%s  *\n* * * * * * * * * * * * * * * *\n*  Información personal       *\n*                             *\n*  Edad: %d                   *\n*  Sexo: %s                    *\n*  Altura: %d cm             *\n*  Peso: %d%s kg  *\n* * * * * * * * * * * * * * * *\n", username, spaces(username), description, spaces(description), age, sex_char(sex), height, weight, " ");

}