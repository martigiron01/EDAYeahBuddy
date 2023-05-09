#ifndef MENU_H
#include "user.h"

#define MENU_H
#define OPTION_QUIT 0
#define OPTION_INVALID -1

void ask_user(userArray* array);

void show_menu();

void flush_input();

void show_submenu();

#endif