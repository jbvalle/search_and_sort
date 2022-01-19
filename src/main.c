/** @brief Main module for the program.  
 * @file main.c
 * 
 * Calls user menu on start. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/randomizer_8_16_64.h"
#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/mergesort.h"
#include "../include/testing.h"
#include "../include/quicksort.h"


int main(void) {
    //Checking
    #if memleak
    testing();
    exit(EXIT_SUCCESS);
    #else
    printf("\nProgram starting...\n");
    show_menu();
	parse_input();
    exit(EXIT_SUCCESS);
    #endif
    return 0;
}
