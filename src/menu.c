#include "../headers/menu.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include "../headers/data.h"
#include "../headers/interface.h"
#include "../headers/friends.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

bool yes_or_no(char* option){
  if((strcmp(option,"y") == 0) || (strcmp(option, "yes") == 0) || (strcmp(option, "accept") == 0) || (strcmp(option, "a") == 0))return true;
  else if ((strcmp(option, "n") == 0)  || (strcmp(option, "no") == 0) || (strcmp(option, "decline") == 0) || (strcmp(option, "d") == 0)) return false;
  else return NULL;
}

void ask_user(userArray* array){
  
  char username[MAX_LENGTH], email[MAX_LENGTH], name[MAX_LENGTH];
  int age, city_id;
  printf("\nInserte nombre de usuario:\n");
  scanf("%s", username);
  printf("\nInserte correo electrónico:\n");
  scanf("%s", email);
  
  int code = create_user(username, email, array);
  if(code == 0){
    printf("\nFallo en la asignación de memória!\n");
    return;
  } else if(code == -1){
    printf("\nUsuario y/o correo electónico ya en uso!\n");
    return;
  }
  
  printf("\nPerfecto! Datos personales:\n Nombre:\n");
  scanf("%s", name);
  printf("\nEdad:\n");
  scanf("%d", &age);
  printf("\nCódigo postal:\n");
  scanf("%d", &city_id);
  
  User *usuario = search_user(username, array);
  strcpy(usuario->name, name);
  usuario->age = age;
  usuario->city_id = city_id;
}


void show_friends_menu(User* user, userArray* array){
  // Texto del submenú
  char txt_friends_menu[MAX_TEXT] = "\n[0] - Volver atrás\n[1] - Enviar solicitud de amistad \n[2] - Ver solicitudes de amistad \n[3] - Ver lista de amigos\n\n";
  int option_friends = OPTION_INVALID;
    
  while(option_friends != OPTION_QUIT) {
    
    print_line(SEPARATION_LINE_LENGTH); // Separation line  
    
    printf("%s", txt_friends_menu); // Prints friends menu
    scanf("%d", &option_friends);
      
    flush_input(); // Empties input buffer
    
    char searchUsername[MAX_LENGTH];
    
    if(option_friends  == 1) {  // Send friend request
      printf("Nombre del usuario:\n ");
      scanf("%s",searchUsername);
      
      User *foundUser = search_user(searchUsername, array);
      
      if(foundUser != NULL){
        printf("\nUsuario encontrado!\n");
        requests_enqueue(foundUser, user);
        printf("\nRequest sent to %s.", searchUsername);
        
      } else {
        printf("Usuario no encontrado!\n");
        }
    } else if(option_friends  == 2) {  // Ver solicitudes de amistad
        requests_print(user);
      
    } else if(option_friends  == 3) { // Ver lista de amigos
        print_friends_list(user);
    }
  }
}

/*
* Función submenú. Muestra un submenú cuando se escoge la opción
* 3) Operar como usuario específico en la función menu()
*/
void show_submenu(User* user, userArray* array){
  // Texto del submenú
  char txt_submenu[MAX_TEXT] = "\n[0] - Cerrar sesión\n[1] - Tu perfil\n[2] - Amigos\n[3] - Realizar una publicación\n[4] - Ver publicaiones de los usuarios\n\n";
  
  char searchUsername[MAX_LENGTH];
  int option_submenu = OPTION_INVALID;

  printf("\n Has iniciado sesión como %s\n", user->username);
  
  while(option_submenu != OPTION_QUIT) {
    
    print_line(SEPARATION_LINE_LENGTH); // Separation line
    
    printf("%s", txt_submenu); // Imprime el menú
    scanf("%d", &option_submenu); // Usuario escoge opción
    
    flush_input(); // Vacía el buffer de entrada

    if(option_submenu == 1) {  // Your profile
      print_user_info(user);
    } else if(option_submenu == 2) {  // Friends
      show_friends_menu(user, array);
    
    } else if(option_submenu == 3){  // Realizar una publicación
   
    } else if(option_submenu == 4){ //Ver publicaiones de los usuarios
    
    } else if (option_submenu != OPTION_QUIT) {  // Opción inválida
      printf("¡Opción inválida!\n");
    }
  }
}



/*
* Menu function. Shows the main menu.
*/
void show_menu(userArray* array) {
  // Menu text
  char txt_menu[MAX_TEXT] = "\n[0] - Salir\n[1] - Insertar nuevo usuario\n[2] - Lista de usuarios\n[3] - Operar como usuario específico\n\n";
  
  int option = OPTION_INVALID;
  
  while(option != OPTION_QUIT) {

    print_line(SEPARATION_LINE_LENGTH); // Separation line
    
    printf("%s", txt_menu); // Prints the menu
    scanf("%d", &option); // User choses option
    
    flush_input(); // Empties the input buffer
    
    if(option == 1) {  // Insertar nuevo usuario
        ask_user(array);
      
    } else if(option == 2) {  // Lista de usuarios
        print_user_list(array);
      
    } else if(option == 3){  // Operar como usuario específico
        char username[25];
        printf("\nIntroduce el nombre de usuario:\n");
        scanf("%s", username);
        User * user = (User*) malloc(sizeof(User));
        user = search_user(username, array);
        if(user == NULL) {
          printf("\nEste usuario no es válido.\n");
        } else {
          show_submenu(user, array);
        }
    } else if (option != OPTION_QUIT) {  // Invalid option
        printf("¡Opción inválida!\n");
    }
  }
  save_data(array);
}