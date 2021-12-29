/** .  
 * @file testing.c
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
#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/randomizer_pt.h"
#include "../include/sortcheck.h"

//STDOUT Color
#define COLOR "\033[1;31m"
#define RESET "\033[0m"

void testing(){
    
    int **input = (int **)malloc(3 * sizeof(int *));
    
    
    printf("\n\n");printf(COLOR);printf("+-------------------+\n");
    printf(COLOR);printf("| Randomized Arrays |\n");
    printf(COLOR);printf("+-------------------+\n");printf(RESET);
    //printf(RESET);
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
     //Show array elements
    show_8_16_64(input, 10); //To display remove Backslashes

    
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+----------------------+\n");
    printf(COLOR);printf("| Sorted by Bubblesort |\n");
    printf(COLOR);printf("+----------------------+\n");printf(RESET);
    //Testing sort algorithm for all 3 array of 1.1 
    bubblesort(input, 8);

    **(input)=-1000;  //Added for testing purposes
    if (sortcheck(input,8) != 0) {
        printf(COLOR);printf("\nProblems in result of sorting algorithm found...\n\n");printf(RESET);
        //exit(EXIT_SUCCESS);
    };
    bubblesort(input, 16);
    sortcheck(input,16);
    bubblesort(input, 64);
    sortcheck(input,64);
    //Display
    show_8_16_64(input, 10); //To display remove Backslashes

    
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("| Sorted by Insertionsort |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    insertionsort(input, 8);
    insertionsort(input, 16);
    insertionsort(input, 64);
    //Show array elements
    show_8_16_64(input, 10); //To display remove Backslashes
        
    //Free input arrays
    free_8_16_64(input);

    //Create Random Numbers for performance test of array
    //8 | 32  | 64 | 128 | .... etc
    printf("\n\n");printf(COLOR);printf("+-------------------------------------------+\n");
    printf(COLOR);printf("| Randomized Arrays for performance testing |\n");
    printf(COLOR);printf("+-------------------------------------------+\n");printf(RESET);

    int **input_pt = (int **)malloc(7 * sizeof(int*));

    randomizer_pt(input_pt);
    show_randomizer_pt(input_pt, 20);
    free_pt(input_pt);
}
