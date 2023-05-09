#include "../headers/menu.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
};

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
  }else if(code == -1){
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

/*
* Función submenú. Muestra un submenú cuando se escoge la opción
* 3) Operar como usuario específico en la función menu()
*/
void show_submenu(){
  // Texto del submenú
  char txt_submenu[MAX_TEXT] = "\n0) Cancelar\n1) Enviar solicitud de amistad\n2) Gestionar solicitudes pendientes\n3) Realizar una publicación\n4) Ver publicaciones\n\n";
  int option_submenu = OPTION_INVALID;

  while(option_submenu != OPTION_QUIT) {
    printf("%s", txt_submenu); // Imprime el menú
    scanf("%d", &option_submenu); // Usuario escoge opción
    
    flush_input(); // Vacía el buffer de entrada
    
    if(option_submenu == 1) {  // Enviar solicitud de amistad
      
    } else if(option_submenu == 2) {  // Gestionar solicitudes pendientes
      
    } else if(option_submenu == 3){  // Realizar una publicación
      
    } else if (option_submenu == 4) {  // Ver publicaciones
      
    } else if (option_submenu != OPTION_QUIT) {  // Opción inválida
      printf("¡Opción inválida!\n");
    }
  }
};

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
        show_submenu();
    } else if (option != OPTION_QUIT) {  // Opción inválida
        printf("¡Opción inválida!\n");
    }
  }
}


