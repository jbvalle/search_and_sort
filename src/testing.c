/** @brief just for testing...
 * @file testing.c
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "../include/node_t.h"
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/randomizer_8_16_64.h"
#include "../include/randomizer_pt.h"
#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/sortcheck.h"
#include "../include/mergesort.h"
#include "../include/search_index.h"
#include "../include/quicksort.h"
#include "../include/testing.h"
#include "../include/bubblesort_timing_pt.h"
#include "../include/insertion_sort_arr_ll.h"

/** @brief Define \c stdout Color */
#define COLOR "\033[1;31m"
#define RESET "\033[0m"


/** @brief Function to create and call free dyn. memory as well as call subfunctions for performance test. 
 * @param[in] arg1 First Array Element to be swapped
 * @param[in] arg2 Second Array Element to be swapped
 * @param[out] arg3 
 * 
 */
void testing(){
    
    int **input = (int **)malloc(3 * sizeof(int *));
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));

    printf("\n\n");printf(COLOR);printf("+-------------------+\n");
    printf(COLOR);printf("| Randomized Arrays |\n");
    printf(COLOR);printf("+-------------------+\n");printf(RESET);
    //printf(RESET);
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
     //Show array elements
    show_8_16_64(input, 10); //To display remove Backslashes
   
    //==============
    //Bubblesort
    //==============
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+----------------------+\n");
    printf(COLOR);printf("| Sorted by Bubblesort |\n");
    printf(COLOR);printf("+----------------------+\n");printf(RESET);
    //Testing sort algorithm for all 3 array of 1.1 
    bubblesort(input, 8);
    #if ERRFLAG 
        **(input)=-1000;  //Added for testing purposes
        if (sortcheck(input,8) != 0) {
            printf(COLOR);printf("\nProblems in result of sorting algorithm found...\n\n");printf(RESET);
            //exit(EXIT_SUCCESS);
        }
    #endif
    bubblesort(input, 16);
    //sortcheck(input,16);
    bubblesort(input, 64);
    //sortcheck(input,64);
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
        

    //-------------------------------------------------
    //Mergesort
    //Create Randomized Arrays
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|   Sorted by Mergesort   |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    //Implement Mergesort
    //1. generate Index for array size
    //Call Mergesort function
    mergeSort(input, 0, 7, search_index(8));
    mergeSort(input, 0, 15, search_index(16));
    mergeSort(input, 0, 63, search_index(64));
    //Show array elements
    show_8_16_64(input, 10);

    //-------------------------------------------------
    //Quicksort
    //Create Randomized Arrays
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|   Sorted by Quicksort   |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    //Implement Quicksort
    //1. generate Index for array size
    //Call Quicksort function
    quicksort(input, 0, 7, search_index(8));
    quicksort(input, 0, 15, search_index(16));
    quicksort(input, 0, 63, search_index(64));
    //Show array elements
    show_8_16_64(input, 10);
    //Free input arrays
    free_8_16_64(input);

    //Perform Insertion Sort Performance Test Array List
    insertionsort_arr_ll();

    //Performs bubblesort algorithm on a generated randomized array of size 2000
    //Subsequently sorting the same set of numbers 20 times and comparing cpu time
    int randomized[2000];

    srand(time(NULL));

    for(int x = 0; x<2000; x++)
    {
        randomized[x] = (double)65536*((double)rand()/(double)RAND_MAX) - 32768.;
    }
    bubblesort_timing_pt(randomized);
}
