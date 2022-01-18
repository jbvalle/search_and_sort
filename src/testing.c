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
#include <string.h>
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/randomizer_8_16_64.h"
#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/randomizer_pt.h"
#include "../include/sortcheck.h"
#include "../include/mergesort.h"
#include "../include/search_index.h"
#include "../include/quicksort.h"
#include "../include/testing.h"

//STDOUT Color
#define COLOR "\033[1;31m"
#define RESET "\033[0m"

//Error Checking macros


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

    // Call 1.2. Comparison
    //perf_test();
}

int perf_test(){
    //Create Random Numbers for performance test of array
    //8 | 32  | 64 | 128 | .... etc
    printf("\n\n");
    printf(COLOR);printf("+--------------------------------+\n");
    printf(COLOR);printf("| Arrays for performance testing |\n");
    printf(COLOR);printf("+--------------------------------+\n");
    printf(RESET);
    printf("\nAll values in ticks\n\n");
    
    int **input_pt = (int **)malloc(7 * sizeof(int*)); 

    if (randomizer_pt(input_pt) != 0) {
        perror("ERROR: Problem in Random Number generation");
        return 1;
    }

    //show_randomizer_pt(input_pt, 20);
    printf(COLOR);printf("Randomized\n");printf(RESET);
    run_algos(input_pt);
    printf("\n");
    
    // now arrays are sorted in ascending order, so are used for this test
    printf(COLOR);printf("Ascending Order\n");printf(RESET);
    run_algos(input_pt);
    printf("\n");
    
    //sort array in descending order
    int  exp = 1;
    for (int i = 0; i < 7; i++) {
        exp += 2;
        reverse(input_pt, i, pow(2,exp));
    }
    

    // now arrays are sorted in descending order, so are used for this test
    printf(COLOR);printf("Descending Order\n");printf(RESET);
    run_algos(input_pt);
    printf("\n");
    
    free_pt(input_pt);
    return 0;
}

void run_algos(int **begarr_pt) {
    
    printf("Array\t | BS |\t | IS |\t | MS |\t | QS |\n");

    //define new pointer to pointer to int
    int **endarr_pt = (int**)malloc(7 * sizeof(int)); 

    for (int i = 0, exp = 1; i < 7; i++) {
        exp += 2;
        printf("%5i ", (int)pow(2,exp));
        clock_t start = 0, end = 0;
        //get memory for array 
        *(endarr_pt+i) = (int*)malloc(pow(2,exp) * sizeof(int));   //do i need i here???
       
       
        //take over (each time) "default" values for the current algo to run through array

            
            for(int j = 0; j < pow(2,exp);j++){
                //*(endarr_pt[i] + j) = *(begarray_pt[i] + j); // do i have to have [i] here????
                *(endarr_pt[i] + j) = *(begarr_pt[i] + j);
            }

        for(int j = 0; j < pow(2,exp);j++){
            printf("%d ", *(endarr_pt[i] + j));
        }
        printf("\n");
        start = clock();
        bubblesort(endarr_pt, pow(2,exp));
        end = clock();
        printf("\t%6ld", (end-start));
       /*  for(int j = 0; j < 8;){
            printf("%d ", *(endarr_pt[i] + j));
        } */
        #if DEBU
        //reset values
            for(int j = 0; j < pow(2,exp);j++){
               *(endarr_pt[i] + j) = *(begarr_pt[i] + j);
            }

        start = clock();
        insertionsort(input_pt, pow(2,exp));
        end = clock();
        printf("\t%6ld", (end-start));

        //reset values
            for(int j = 0; j < pow(2,exp);j++){
                *(endarr_pt[i] + j) = *(begarr_pt[i] + j);
            }


        start = clock();
        mergeSort(input_pt, 0, pow(2,exp)-1, search_index(pow(2,exp)));
        end = clock();
        printf("\t%6ld", (end-start));

        //reset values
            for(int j = 0; j < pow(2,exp);j++){
                *(endarr_pt[i] + j) = *(begarr_pt[i] + j);
            }

        start = clock();
        quicksort(input_pt, 0, pow(2,exp)-1, search_index(pow(2,exp)));
        end = clock();
        printf("\t%6ld", (end-start));
        #endif
        printf("\n");

        free(endarr_pt[i]);  // *(endarr_pt[i] + j)
       
        /*
        if (endarr_pt) {
            free(endarr_pt);
            endarr_pt = NULL;
        } */
    }
    free_pt(endarr_pt);
    //elapsedsec = (double)(end - start)/CLOCKS_PER_SEC;  //Linux gets CPU time, on Windows wall time
    //printf("2Time measured: %d ticks / %.3f seconds.\n", elapsedticks,  elapsedsec);
    //show_randomizer_pt(endarr_pt, 15);
}

void reverse(int **input, int no, int size){
    int fwdIndex = 0;
    int rewIndex = size - 1;
    int tempValue;  
    // no pointer arithmetic due to using one array only
    while(rewIndex > fwdIndex) {
        tempValue = *(input[no]+rewIndex);
        *(input[no]+rewIndex) = *(input[no]+fwdIndex);
        *(input[no]+fwdIndex) = tempValue;
        fwdIndex++;
        rewIndex--;
    }

    #if DEBU
    fwdIndex = 0;
    //while(*default_pt != NULL)
    while(fwdIndex < size)
    {
        printf("%i\n", *(input_pt[no]+fwdIndex));
        fwdIndex++;
    }
    printf("\n\n");
    #endif
}

