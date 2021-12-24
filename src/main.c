/** .  
 * @file main.c
 * for doxy
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../include/main.h"
#include "../include/menu.h"
#include "../include/randomizer_8_16_64.h"

int main(void) {
    printf("\nProgram starting...\n");
    show_menu();

    /** Just an Example for debugging */
    #if DEBUG 
	    printf("Debugging Test...\n");
    #endif

	  parse_input();
    exit(EXIT_SUCCESS);
}
