/** Module performs checks whether arrays are in sorted order.
 * @file sortcheck.c
 * This module has a function implemented which checks whether the arrays in the input are already sorted. 
 * Returns an error to stdout if this is not the case.
 */


#include <stdio.h>
#include <stdlib.h>
#include "../include/sortcheck.h"
#include "../include/search_index.h"

//STDOUT Color
#define COLOR "\033[1;32m" // turquois
#define RESET "\033[0m"


int sortcheck(int **input, int sizeof_array){
    int index = search_index(sizeof_array);
    printf("Start checking sequence for array with %i elements starting at address", sizeof_array);
    printf(COLOR);printf(" %p\n",(void*)input[index]);printf(RESET);
    for (int j = 0; j < sizeof_array-1; j++) {

        if (*(input[index] + j) > *(input[index] + (j + 1))){
            printf(COLOR);
            printf("\t\t+--------------------------------------+\n");
            printf("\t\t|                Error!                |\n"); 
            printf("\t\t+--------------------------------------+\n");
            printf(RESET);
            printf("\a\n"); //BEEP
            printf("Value of array element with index [#%i, %6i] is higher than next element [#%i, %6i]!\n", j, *(input[index]+j), j+1, *(input[index]+(j+1)));
            return(EXIT_FAILURE);
        }
    }
    printf("Checking sequence finished successfully for");printf(COLOR);printf(" %p\n\n",(void*) input[index]);printf(RESET);
    return(EXIT_SUCCESS);
}
