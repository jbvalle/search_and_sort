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


void randomizer_debug(){
    
    int **input = (int **)malloc(3 * sizeof(int *));
    
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
    
    //Show array elements
    show_8_16_64(input); //To display remove Backslashes
        
    //Free input arrays
    free_8_16_64(input);
}

int main(void) {
    printf("\nProgram starting...\n");
    show_menu();

    /** Just an Example for debugging */
    #if DEBUG 
	    printf("Debugging Test...\n");
      //Gibt das Generierte Array aus
      randomizer_debug();  
    #endif

	  parse_input();
    exit(EXIT_SUCCESS);
}
