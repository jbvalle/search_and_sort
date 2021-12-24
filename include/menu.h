/** .  
 * @file menu.h
 * 
 * 
 * 
 */

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h> // needed for function exit, dynamic memory mgmt
#include <ctype.h> // needed for function tolower

struct menu_s {
    char symbol; 
    char *text; 
    };
typedef struct menu_s menu_t;

void show_menu();
void parse_input();

#endif