/** @brief This module implements the performance test of all algorithms. 
 * @file randomizer_pt.c
 * 
 * Includes all functions to perform the performance test.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/mergesort.h"
#include "../include/quicksort.h"
#include "../include/randomizer_pt.h"
#include "../include/search_index.h"

/** @brief Define special \c stdout color */
#define COLOR "\033[1;31m"
/** @brief Setting special \c stdout color back to default */
#define RESET "\033[0m"

/** @brief Function produces input (random numbers) for performance check. 
 * @param[in] input Pointer to pointer array to multidimensional int array
 * @param[out] status Success(0)/Fail(1) 
 * 
 * Creates random numbers for each of the test arrays.
 */
int randomizer_pt(int **input){
    //0. 2 ^ exp = 8, 32, 128, etc.
    //1. 2 ^ (3 + 0) = 8
    //2. 2 ^ (3 + 2) = 32
    //3. 2 ^ (5 + 2) = 128
    if(input == NULL){
        perror("ERROR: NULL Pointer as Input Value");
        return 1;
    }
    /*
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));*/
    for(int i = 0, exp = 1; i < 7; i++){
        exp += 2;
        *(input + i) = (int*)malloc(pow(2,exp) * sizeof(int));
    }
    
    //Plant rand() seed
    srand(time(NULL));
    
    //Assign unique randoms to each input array element
    for(int i = 0, exp = 1; i < 7; i++){

        exp += 2;
        for(int j = 0; j < pow(2,exp);){
            
            //2 ^ 15 = 32768 | 2 ^ 16 = 65536
            int random_num = -32768 + 65536*(rand()/(RAND_MAX + 1.0));
            *(input[i] + j++) = random_num;
        }
    }   
    return 0;
}

/** @brief Function produces output printed on @c stdout. 
 * @param[in] input Pointer to pointer array to multidimensional int array
 * @param[in] max_cols Number of columns to be printed in one line 
 * 
 */
void show_randomizer_pt(int **input, int max_cols){
    
    int format_count;

    for(int i = 0, exp = 1; i < 7; i++){
        
        exp += 2;
       
        //Array Bezeichnung
    printf("\n\n  +-----------------------------------+\n");
        printf("  | %1d. Array with size %5d elements |\n", i + 1, (int)pow(2,exp));
        printf("  +-----------------------------------+\n");
        //Displays arrays in partitions with added formatting
        for(int j = 0; j < pow(2,exp);j++){
            
            if(j % max_cols == 0){
                printf("\n");
                if(j > 0){
                    for(int k = 0; k < max_cols; k++)printf("  +------+");
                    printf("\n");
                }
                for(format_count = 0; (format_count < max_cols) && (format_count < pow(2,exp) - j); format_count++)printf("  +------+");
                printf("\n");
            }
            
            printf("  |");printf(COLOR);
            printf("%6d",*(input[i] + j));printf(RESET);
            printf("|");
        }
        printf("\n");
        for(int i = 0; i < format_count; i++)printf("  +------+");
    } 
}

/** @brief Sub-function frees dynamically allocated memory. 
 * @param[in] input Pointer to pointer array to multidimensional int array
 * 
 */
void free_pt(int **input){
    for(int i = 0; i < 7; i++){
        free(input[i]);
    } 
    if (input) {
        free(input);
        input = NULL;
    }
}


/** @brief Function shows result of performance check on @c stdout. 
 * @param[out] status Success(0)/Fail(1)
 * 
 * First creates Random Numbers for performance test of array.
 * Then calls algorithms with input array in random, asc., then desc. order.
 * For asc. order the result of sorting of random numbers is used.
 * Result of asc. order is reversed to serve as input for sorting with desc. order input.
 */
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
    printf(COLOR);printf("Random Order\n");printf(RESET);
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
   
    printf(COLOR);printf("\nPerformance testing done!\n");printf(RESET);
    free_pt(input_pt);
    return 0;
}

/** @brief Sub-function of performance test stepping through each algorithm and each size. 
 * @param[in] begarr_pt Pointer to pointer to int array
 * 
 * Clock function measures ticks (not seconds).
 */
void run_algos(int **begarr_pt) {
    printf("Array\t |   BS   |\t |   IS   |\t |   MS   |\t |   QS   |\n");

    int **endarr_pt = (int**)malloc(7 * sizeof(int *)); 

    for (int i = 0, exp = 1; i < 7; i++) {
        exp += 2;
        printf("%5i ", (int)pow(2,exp));
        clock_t start = 0, end = 0;
        
        *(endarr_pt+i) = (int*)malloc(pow(2,exp) * sizeof(int));
       
        //take over "default" values for the current algo to run through array
        for(int j = 0; j < pow(2,exp);j++){
            *(endarr_pt[i] + j) = *(begarr_pt[i] + j);
        }

        /* for(int j = 0; j < pow(2,exp);j++){
            printf("%d ", *(endarr_pt[i] + j));
        } */
        start = clock();
        bubblesort(endarr_pt, pow(2,exp));
        end = clock();
        printf("\t  %8ld", (end-start));
        /*  for(int j = 0; j < pow(2,exp);j++){
            printf("%d ", *(endarr_pt[i] + j));
        } */
        #if !DEBUG
        reset_values(endarr_pt, begarr_pt, exp, i);
        start = clock();
        insertionsort(endarr_pt, pow(2,exp));
        end = clock();
        printf("\t  %8ld", (end-start));

        reset_values(endarr_pt, begarr_pt, exp, i);
        start = clock();
        mergeSort(endarr_pt, 0, pow(2,exp)-1, search_index(pow(2,exp)));
        end = clock();
        printf("\t  %8ld", (end-start));

        reset_values(endarr_pt, begarr_pt, exp, i);
        start = clock();
        quicksort(endarr_pt, 0, pow(2,exp)-1, search_index(pow(2,exp)));
        end = clock();
        printf("\t  %8ld", (end-start));
        #endif
        printf("\n");
    }
    free_pt(endarr_pt);
    //elapsedsec = (double)(end - start)/CLOCKS_PER_SEC;  //Linux gets CPU time, on Windows wall time
    //printf("2Time measured: %d ticks / %.3f seconds.\n", elapsedticks,  elapsedsec);
    
}

/** @brief Sub-function of performance test providing default numbers each algorithm. 
 * @param[in] output Pointer to pointer array to multidimensional int array - values to be sorted
 * @param[in] input Pointer to pointer array to multidimensional int array - default values
 * @param[in] exp Exponential number to calculate elements of array
 * @param[in] i Index of output and input array
 * 
*/
void reset_values(int **output, int **input, int exp, int i){
    for(int j = 0; j < pow(2,exp);j++){
       *(output[i] + j) = *(input[i] + j);
    }
}

/** @brief Sub-function of performance test reversing the order of input array. 
 * @param[in] input Pointer to int array
 * @param[in] index Index number of array (2nd dimension of multidimensional array)
 * @param[in] sizeof_array Number of elements of array
 * 
 * Simple swapping of values.
 */
void reverse(int **input, int index, int sizeof_array) {
    int fwdIndex = 0;
    int rewIndex = sizeof_array - 1;
    int tempValue;  
    while(rewIndex > fwdIndex) {
        tempValue = *(input[index]+rewIndex);
        *(input[index]+rewIndex) = *(input[index]+fwdIndex);
        *(input[index]+fwdIndex) = tempValue;
        fwdIndex++;
        rewIndex--;
    }
    #if DEBUG
        fwdIndex = 0;
        while(fwdIndex < sizeof_array) {
            printf("%i\n", *(input_pt[no]+fwdIndex));
            fwdIndex++;
        }
        printf("\n\n");
    #endif
}
