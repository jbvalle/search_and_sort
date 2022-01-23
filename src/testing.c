/** @brief Module for output of each sorting algorithm on its own (testing).
 * @file testing.c
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/sortcheck.h"
#include "../include/mergesort.h"
#include "../include/search_index.h"
#include "../include/quicksort.h"
#include "../include/testing.h"
#include "../include/randomizer_8_16_64.h"


/** @brief Define \c stdout color */
#define COLOR "\033[1;31m"
/** @brief Define \c stdout color to Standard */
#define RESET "\033[0m"


/** @brief Function to output mergesort to @c stdout. 
 * 
 */
void ms(){
    int **input = (int **)malloc(3 * sizeof(int *));
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));
 printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|        Mergesort        |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    printf("\n\n");printf(COLOR);printf("+-------------------+\n");
    printf(COLOR);printf("| Randomized Arrays |\n");
    printf(COLOR);printf("+-------------------+\n");printf(RESET);
    //printf(RESET);
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
        //Show array elements
    show_8_16_64(input, 10);

    //-------------------------------------------------
    //Mergesort
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|   Sorted by Mergesort   |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    //Call Mergesort function
    mergeSort(input, 0, 7, search_index(8));
    sortcheck(input, 8);
    mergeSort(input, 0, 15, search_index(16));
    sortcheck(input, 16);
    mergeSort(input, 0, 63, search_index(64));
    sortcheck(input, 64);
    //Show array elements
    show_8_16_64(input, 10);
    printf("\n\n");
    free_8_16_64(input);

}

/** @brief Function to output insertionsort to @c stdout. 
 * 
 */
void is() {
    int **input = (int **)malloc(3 * sizeof(int *));
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|      Insertionsort      |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    printf("\n\n");printf(COLOR);printf("+-------------------+\n");
    printf(COLOR);printf("| Randomized Arrays |\n");
    printf(COLOR);printf("+-------------------+\n");printf(RESET);
    //printf(RESET);
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
    //Show array elements
    show_8_16_64(input, 10); //To display remove Backslashes

    //-------------------------------------------------
    //Insertionsort
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("| Sorted by Insertionsort |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    insertionsort(input, 8);
    sortcheck(input, 8);
    insertionsort(input, 16);
    sortcheck(input, 16);
    insertionsort(input, 64);
    sortcheck(input, 64);
    //Show array elements
    show_8_16_64(input, 10);
    printf("\n\n");
    free_8_16_64(input);
}

/** @brief Function to output bubblesort to @c stdout. 
 * 
 */
void bs() {
    int **input = (int **)malloc(3 * sizeof(int *));
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));
 printf("\n\n");printf(COLOR);printf("+----------------------+\n");
    printf(COLOR);printf("|      Bubblesort      |\n");
    printf(COLOR);printf("+----------------------+\n");printf(RESET);
    printf("\n\n");printf(COLOR);printf("+-------------------+\n");
    printf(COLOR);printf("| Randomized Arrays |\n");
    printf(COLOR);printf("+-------------------+\n");printf(RESET);
    //printf(RESET);
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
    //Show array elements
    show_8_16_64(input, 10);

    //-------------------------------------------------
    //Bubblesort
    printf("\n\n");printf(COLOR);printf("+----------------------+\n");
    printf(COLOR);printf("| Sorted by Bubblesort |\n");
    printf(COLOR);printf("+----------------------+\n");printf(RESET);
    //Testing sort algorithm for all 3 array of 1.1 
    bubblesort(input, 8);
    sortcheck(input, 8);
    #if ERRFLAG 
        **(input)=-1000;  //Added for testing purposes
        if (sortcheck(input,8) != 0) {
            printf(COLOR);printf("\nProblems in result of sorting algorithm found...\n\n");printf(RESET);
            //exit(EXIT_SUCCESS);
        }
    #endif
    bubblesort(input, 16);
    sortcheck(input,16);
    bubblesort(input, 64);
    sortcheck(input,64);
    //Show array elements
    show_8_16_64(input, 10);
    printf("\n\n");
    free_8_16_64(input);   
}

/** @brief Function to output quicksort to @c stdout. 
 * 
 */
void qs() {
     int **input = (int **)malloc(3 * sizeof(int *));
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));
printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|        Quicksort        |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    printf("\n\n");printf(COLOR);printf("+-------------------+\n");
    printf(COLOR);printf("| Randomized Arrays |\n");
    printf(COLOR);printf("+-------------------+\n");printf(RESET);
    //printf(RESET);
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
        //Show array elements
    show_8_16_64(input, 10);

    //-------------------------------------------------
    //Quicksort
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|   Sorted by Quicksort   |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    //Call Quicksort function
    quicksort(input, 0, 7, search_index(8));
    sortcheck(input, 8);
    quicksort(input, 0, 15, search_index(16));
    sortcheck(input, 16);
    quicksort(input, 0, 63, search_index(64));
    sortcheck(input, 64);
    //Show array elements
    show_8_16_64(input, 10);
    printf("\n\n");
    free_8_16_64(input);
}