/** Header file for menu module.  
 * @file menu.h
 * Detailed description
 */

#ifndef MENU_H
#define MENU_H

struct menu_s {
    char symbol; 
    char *text; 
    };
typedef struct menu_s menu_t;

void show_menu();
void parse_input();

#endif