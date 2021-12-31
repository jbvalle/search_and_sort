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
#include "../include/mergesort.h"
#include "../include/testing.h"


int main(void) {
    printf("\nProgram starting...\n");
    show_menu();
	parse_input();

    exit(EXIT_SUCCESS);
}
