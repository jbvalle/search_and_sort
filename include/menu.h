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


//needed here in .h??? - pls give feedback in code review
void show_menu();
void parse_input();


/** example to show how to do simple debugging
 * should be brought to start of main.c???
 * the way to comment here also here a test for doxygen - very very first draft
   */
#define D 1 //DEBUG_LEVEL


#endif