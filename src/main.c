/** @brief Main module for the program
 * @file main.c
 * 
 * Simple program "search and sort algorithms" realized.
 * Calls user menu on start. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/testing.h"

/**
 *@brief Starting point of program, showing the user menu after start.
 *@param[out] status Success(0)/Fail(1)
 * 
 */
int main(void) {
    //Checking
    #if memleak
    bs();
    is();
    ms();
    qs();
    exit(EXIT_SUCCESS);
    #else
    printf("\nProgram starting...\n");
    show_menu();
	parse_input();
    exit(EXIT_SUCCESS);
    #endif
    return 0;
}
