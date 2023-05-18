#include "../headers/menu.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include "../headers/data.h"
#include "../headers/interface.h"
#include "../headers/friends.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
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
  char txt0_1_submenu[MAX_TEXT] = "\n0) Cerrar pantalla\n1) Enviar solicitud de amistad. \n2) Ver solicitud de amistad \n3) Ver lista de amigos\n\n";
  int option_friends = OPTION_INVALID;
    
  while(option_friends != OPTION_QUIT) {
      
    printf("%s", txt0_1_submenu); // Imprime el menú
    scanf("%d", &option_friends);
      
    flush_input(); // Vacía el buffer de entrada
    char searchUsername[MAX_LENGTH];
    if(option_friends  == 1) {  //Emviar solicitud de amistad.
      
      printf("Nombre del usuario:\n ");
      scanf("%s",searchUsername);
      User *foundUser = search_user(searchUsername, array);
      if(foundUser != NULL){
        printf("Usuario encontrado: %s \n", foundUser -> username);
            
      } else {
        printf("Usuario no encotrado \n");
        }
    } else if(option_friends  == 2) {  //Ver solicitud de amistad

    } else if(option_friends  == 3) { //Ver lista de amigos

    }
  }
}
/*
* Función submenú. Muestra un submenú cuando se escoge la opción
* 3) Operar como usuario específico en la función menu()
*/
void show_submenu(User* user, userArray* array){
  // Texto del submenú
  char txt_submenu[MAX_TEXT] = "\n0) Cerrar sesión\n1) Tu perfil \n2) Amigos \n3) Realizar una publicación\n\n";
  char searchUsername[MAX_LENGTH];
  
  int option_submenu = OPTION_INVALID;

  while(option_submenu != OPTION_QUIT) {
    printf("\n Has iniciado sesión como %s\n", user->username);
    printf("%s", txt_submenu); // Imprime el menú
    scanf("%d", &option_submenu); // Usuario escoge opción
    
    flush_input(); // Vacía el buffer de entrada
    
    if(option_submenu == 1) {  
      print_user_info(user);
    } else if(option_submenu == 2) {  //Amigo
      show_friends_menu(user, array);
    
    } else if(option_submenu == 3){  // Realizar una publicación
      
    } else if (option_submenu != OPTION_QUIT) {  // Opción inválida
      printf("¡Opción inválida!\n");
    }
  }
}

/*
* Función menú. Muestra el menú principal
*/
void show_menu(userArray* array) {
  // Texto del menú
  char txt_menu[MAX_TEXT] = "\n0) Salir\n1) Insertar nuevo usuario\n2) Lista de usuarios\n3) Operar como usuario específico\n\n";
  
  int option = OPTION_INVALID;
  
  while(option != OPTION_QUIT) {
    printf("%s", txt_menu); // Imprime el menú
    scanf("%d", &option); // Usuario escoge opción
    
    flush_input(); // Vacía el buffer de entrada
    
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
    } else if (option != OPTION_QUIT) {  // Opción inválida
        printf("¡Opción inválida!\n");
    }
  }
  save_data(array);
}