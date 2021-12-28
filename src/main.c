/** Main module for the program.  
 * @file main.c
 * Detailed description
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
#include "../include/testing.h"


int main(void) {
    printf("\nProgram starting...\n");
    show_menu();

    /** Just an Example for debugging */
    #if DEBUG 
	    printf("Debugging Test...\n");
        //Gibt das Generierte Array aus
        testing();  
    #endif

	//parse_input();
    exit(EXIT_SUCCESS);
}
