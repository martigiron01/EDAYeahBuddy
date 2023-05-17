#include "../headers/txt.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Longitud máxima de una línea sin contar asteríscos y márgenes
#define MAX_LINE_LENGTH 25

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