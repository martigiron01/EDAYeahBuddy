#ifndef MENU_H
#include "user.h"

#define MENU_H
#define OPTION_QUIT 0
#define OPTION_CLOSE_APP X
#define OPTION_INVALID -1

void ask_user(userArray* array);

bool yes_or_no(char* option);

void show_menu(userArray* array, Dictionary * dictionary);

void show_friends_menu(User* user, userArray* array);

void flush_input();

void show_submenu(User* user, userArray* array, Dictionary * dictionary);



#endif