#include "../headers/menu.h"
#include "../headers/main.h"
#include "../headers/user.h"
#include "../headers/data.h"
#include "../headers/interface.h"
#include "../headers/friends.h"
#include "../headers/dict.h"
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
  
  char username[MAX_LENGTH], email[MAX_LENGTH], name[MAX_LENGTH], description[MAX_DESCRIPTION];
  
  printf("\nInsert username:\n");
  scanf("%s", username);
  printf("\nInsert email:\n");
  scanf("%s", email);
  
  int code = create_user(username, email, array);
  
  if(code == 0){
    printf("\nMemory allocation failure!\n");
    return;
  } else if(code == -1){
    printf("\nUsername and/or email already in use!\n");
    return;
  }
  
  User* user = search_user(username, array);
  
  printf("\nPerfect! Personal information:\n Name:\n");
  scanf("%s", name);
  printf("\nAge:\n");
  scanf("%d", &user->age);
  printf("\nSex (Female:0, Male:1) :\n");
  scanf("%d", &user->sex);
  printf("\nPostcode:\n");
  scanf("%d", &user->city_id);

  printf("\nNow let's create your fitness profile.\n");
  printf("\nTell us about you: (Max. %d characters)\n", MAX_DESCRIPTION);
  
  flush_input();
  fgets(description, sizeof(description), stdin);
  strcpy(description, user->description);
  
  printf("\nGym postcode:\n");
  scanf("%d", &user->gym_id);
  
  printf("\nHeight:\n");
  scanf("%d", &user->height);
  
  printf("\nCurrent body weight:\n");
  scanf("%d", &user->body_weight);
  
  printf("\nWorkout days (Monday:1, Tuesday:2, Wednesday:3, Thursday:4, Friday:5, Saturday:6 and  Sunday:7):\n");
  scanf("%d", &user->workout_days);
  
  printf("\nTime preference (00:00-6:00 -> 2406, 6:00-9:00 -> 0609, 9:00-12:00 -> 0912, 12:00-15:00 -> 1215, 15:00-19:00 -> 1519 and 19:00-00:00 -> 1924):\n");
  scanf("%d", &user->time_preference);
  
  printf("\nFavourite muscle group (Arms:1, Back:2, Chest:3, Legs:4 and Glutes:5):\n");
  scanf("%d", &user->muscle_preference);
  
 
  strcpy(user->name, name);

  // Store it in users.txt
  save_user(user, "users.txt");
}


void show_friends_menu(User* user, userArray* array){
  // Friends menu text
  char txt_friends_menu[MAX_TEXT] = "\n[0] - Go back\n[1] - Send friend request \n[2] - View friend requests \n[3] - Friends list\n\n";
  
  int option_friends = OPTION_INVALID;
    
  while(option_friends != OPTION_QUIT) {
    
    print_line(SEPARATION_LINE_LENGTH); // Separation line  
    
    printf("%s", txt_friends_menu); // Prints friends menu
    scanf("%d", &option_friends);
      
    flush_input(); // Empties input buffer
    
    char searchUsername[MAX_LENGTH];
    
    if(option_friends  == 1) {  // Send friend request
      printf("Username:\n ");
      scanf("%s",searchUsername);
      
      User* foundUser = search_user(searchUsername, array);
      
      if(foundUser != NULL){
        printf("\nUser found!\n");
        requests_enqueue(foundUser, user);
        printf("\nRequest sent to %s.", searchUsername);
        
      } else {
        printf("User not found!\n");
        }
    } else if(option_friends  == 2) {  // View friends requests
        requests_print(user);
      
    } else if(option_friends  == 3) { // Friends list
        print_friends_list(user);
      
        char option_username[50];
        printf("\nWrite friend username to see its profile: (0 to quit)\n");
        scanf("%s", option_username);
      
        if(option_username[0] == '0')continue;
      
        User* friend = search_user(option_username, array);
      
        if(friend == NULL){
          printf("User not found!\n");
        }else{
          print_user_info(friend);
        }
        
    }
  }
}

/*
* Sumbenu function. Shows the submenu.
*/
void show_submenu(User* user, userArray* array, Dictionary * dictionary){
  // Submenu text
  char txt_submenu[MAX_TEXT] = "\n[0] - Sign out\n[1] - Your profile\n[2] - Friends\n[3] - Add a post\n[4] - Feed\n\n";
  char searchUsername[MAX_LENGTH];
  int option_submenu = OPTION_INVALID;

  printf("\n You are logged in as %s\n", user->username);
  
  while(option_submenu != OPTION_QUIT) {
    
    print_line(SEPARATION_LINE_LENGTH); // Separation line
    
    printf("%s", txt_submenu); // Prints submenu
    scanf("%d", &option_submenu); // User choses option
    
    flush_input(); // Empties input buffer

    if(option_submenu == 1) {  // Your profile
      print_user_info(user);
    } else if(option_submenu == 2) {  // Friends
      show_friends_menu(user, array);
    
    } else if(option_submenu == 3){  // Post
      char* post = create_post();
      push_post(user->posts, post, dictionary);
      save_post(post, user, "posts.txt");
      printf("\nSuccesfully posted!");
      
    } else if(option_submenu == 4){ // View feed posts
        FILE * fp = fopen("posts.txt", "r");
        char caracter;
        if (fp == NULL) {
          printf("File opening error!\n");
        }
    
        // Reads and shows the file content
        while ((caracter = fgetc(fp)) != EOF) {
            printf("%c", caracter);
        }
      
        fclose(fp);
      
    } else if (option_submenu != OPTION_QUIT) {  // Invalid option
      printf("Invalid option!\n");
    }
  }
}



/*
* Menu function. Shows the main menu.
*/
void show_menu(userArray* array, Dictionary * dictionary) {
  // Menu text
  char txt_menu[MAX_TEXT] = "\n[0] - Exit\n[1] - Insert new user\n[2] - Users list\n[3] - Operate as specific user\n[4] - Most used words\n\n";
  
  int option = OPTION_INVALID;
  
  while(option != OPTION_QUIT) {

    print_line(SEPARATION_LINE_LENGTH); // Separation line
    
    printf("%s", txt_menu); // Prints the menu
    scanf("%d", &option); // User choses option
    
    flush_input(); // Empties the input buffer
    
    if(option == 1) {  // Insert new user
        ask_user(array);
      
    } else if(option == 2) {  // Users list
        print_user_list(array);
      
    } else if(option == 3){  // Operate as specific user
        char username[25];
        printf("\nEnter the username:\n");
        scanf("%s", username);
        User * user = (User*) malloc(sizeof(User));
        user = search_user(username, array);
        if(user == NULL) {
          printf("\nThis username is invalid.\n");
        } else {
          show_submenu(user, array, dictionary);
        }
      
    } else if(option == 4){  // Prints word count rank
        print_dictionary_ranking(dictionary);
      
    } else if (option != OPTION_QUIT) {  // Invalid option
        printf("Invalid option!\n");
    }
  }
}