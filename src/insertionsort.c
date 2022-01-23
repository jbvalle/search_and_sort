/** @brief Module for the implementation of insertionsort algorithm.
 * @file insertionsort.c
 * 
 * 
 */
#include <stdio.h>
#include "../include/search_index.h"

/**
 *@brief This function performs the sorting algortihm for an array using insertion sort.
 *@param[in] input Array
 *@param[in] sizeof_array Number of elements of array
 *
 */
void insertionsort(int **input, int sizeof_array){

    int index = search_index(sizeof_array);

    for(int i = 1; i < sizeof_array; i++){

        int j, temp = *(input[index] + i);

        for(j = i - 1; (j >= 0) && (*(input[index] + j) > temp); j--){

            *(input[index] + j + 1) = *(input[index] + j);
        }
        
        *(input[index] + j + 1) = temp;
    }
}

