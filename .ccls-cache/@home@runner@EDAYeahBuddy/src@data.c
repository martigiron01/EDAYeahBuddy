#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/data.h"
#include "../headers/user.h"
#include "../headers/preferences.h"

int line_count(const char * filename){

  //La ultima linea no contiene '\n'
  int lines = 1;
  char character;
  FILE * fp = fopen(filename, "r");
  
  //Error abriendo archivo
  if(fp == NULL) return 0;

  //Loop que recorre todo el archivo hasta el final copiando carácteres a character
  while((character = fgetc(fp)) != EOF){

    //Suma 1 a lines cuando encuentra saltos de linea
    if(character == '\n'){
      lines++;
    }
  }
  fclose(fp);
  return lines;
}

void import_data(userArray* array, char* users_filename, char* posts_filename){

  //Contamos el numero de lineas en el archivo de usuarios
  int num_users = line_count(users_filename);
  FILE* fp = fopen(users_filename, "r");

  //Parametros a leer del archivo:
  int id;
  char username[MAX_LENGTH];
  char name[MAX_LENGTH];
  char mail_adress[MAX_LENGTH];
  char description[MAX_DESCRIPTION];
  int age;
  int sex;
  int body_weight;
  int height;
  int city_id;
  int gym_id;
  int workout_days;
  int time_preference;
  int muscle_preference;

  //Creamos cada usuario del archivo
  for(int i = 0; i < num_users; i++){

    //Utilizamos %[-]%*c para determinar que lea texto de la descripción hasta el primer guión
    fscanf(fp, "%d %s %s %s %[^-]%*c", &id, username, name, mail_adress, description);
    fscanf(fp, "%d %d %d %d %d %d %d %d %d", &age, &sex, &body_weight, &height, &city_id,
    &gym_id, &workout_days, &time_preference, &muscle_preference);

    create_user(username, mail_adress, array);
    User* user = search_user(username, array);
    strcpy(user->name, name);
    strcpy(user->description, description);
    user->age = age;
    user->sex = sex;
    user->body_weight = body_weight;
    user->height = height;
    user->city_id = city_id;
    user->gym_id = gym_id;
    user->workout_days = workout_days;
    user->time_preference = time_preference;
    user->muscle_preference = muscle_preference;
    
  }
  fclose(fp);
}

void save_user(User* user, char* filename){
  
  int lines = line_count(filename);
  FILE* fp = fopen(filename, "a");

  //Error de apertura
  if(fp == NULL){
    printf("\nError abriendo archivo!\n");
    return;
  } 
  
  //Escribimos en la primera linea disponible los datos de usuario
  //Utilizamos un guión para marcar el final del texto de la descripción
  fprintf(fp, "\n%d %s %s %s %s- %d %d %d %d %d %d %d %d %d", lines, user->username, user->name,
    user->mail_adress, user->description, user->age, user->sex, user->body_weight, user->height, user->city_id,
    user->gym_id, user->workout_days, user->time_preference, user->muscle_preference);
  
   //Cerramos el archivo
  fclose(fp);
}

/*User* presentCSV(const char* preset, int*num_users){
  FILE* archivo = fopen(preset, "r");
  if(archivo == NULL) {
    printf("No se puede abriradf el archivo\n");
    return NULL;  
  }
  char linea[100];
  User* usuarios = malloc(sizeof(User) * 20);  //Tenim 20 usuaris 
  if (usuarios == NULL) {
    printf("Error al asignar memoria\n");
    fclose(archivo);
    return NULL;
  }
  int contador = 0;
  while(fscanf(archivo, "%s %s %s %s %d %d %d %d %d %d %d %d",     
    usuarios[contador].username,
    usuarios[contador].name, 
    usuarios[contador].mail_adress, 
    usuarios[contador].description, 
    &usuarios[contador].age, 
    &usuarios[contador].sex, 
    &usuarios[contador].body_weight, 
    &usuarios[contador].city_id, 
    &usuarios[contador].gym_id,
    &usuarios[contador].workout_days,   
    &usuarios[contador].time_preference, 
    &usuarios[contador].muscle_preference) == 12) {
    contador ++;
    }

  *num_users = contador;
  fclose(archivo);
  return usuarios;
 
  }*/


/*void printUsers(User* usuarios, int num_users) {
  printf("Usuarios cargados:\n");
  for (int i = 0; i < num_users; i++) {
    printf("Username: %s\n", usuarios[i].username);
    printf("Name: %s\n", usuarios[i].name);
    printf("Mail Address: %s\n", usuarios[i].mail_adress);
    printf("Description: %s\n", usuarios[i].description);
    printf("Age: %d\n", usuarios[i].age);
    printf("Sex: %d\n", usuarios[i].sex);
    printf("Body Weight: %d\n", usuarios[i].body_weight);
    printf("Height: %d\n", usuarios[i].height);
    printf("City ID: %d\n", usuarios[i].city_id);
    printf("Gym ID: %d\n", usuarios[i].gym_id);
    printf("Workout Days: %d\n", usuarios[i].workout_days);
    printf("Time Preference: %d\n", usuarios[i].time_preference);
    printf("Muscle Preference: %d\n", usuarios[i].muscle_preference);
    printf("-----------------------------\n");
  }
}*/

/*void processUsers() { 
  int num_users;
  User* usuarios = presentCSV("preset.txt", &num_users);

  if (usuarios != NULL) {
    printUsers(usuarios, num_users);
    free(usuarios);
  }
}*/