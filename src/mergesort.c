/** @brief Module for implementation of Mergesort algorithm 
 * @file mergesort.c
 *
 * These functions perform the sorting algortihm for an array using merge sort.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/search_index.h"


/**
 *@brief This function performs the merging part of mergesort.
 *@param[in] input Array
 *@param[in] low left partition of array
 *@param[in] mid Index of the split between left and right array
 *@param[in] high right partition of array
 *@param[in] index Index of multidim. array
 *
 * Additional temporary array is used to store sorted numbers.
 */
void merge(int **input, int low, int mid, int high, int index) {

    //i...index for left partition | j ... index for right partition | 
    //k...index for original randomized_array
    //temp ... saves the sorted numbers in temporary array
    int i, j, k, *temp = malloc((high - low + 1)*sizeof(int));

    for(i = low, j = mid + 1, k = 0; (i <= mid)&&(j <= high); k++){

        if(*(input[index] + i) < *(input[index] + j)){

            temp[k] = *(input[index] + i++);
        }else{

            temp[k] = *(input[index] + j++);
        }
    }

    while(i <= mid){

        temp[k++] = *(input[index] + i++);   
    }

    while(j <= high){

        temp[k++] = *(input[index] + j++);
    }

    for(int x = low, y = 0; x <= high; x++){

        *(input[index] + x) = temp[y++];
    }
    free(temp);
}

/**
 *@brief Recursive function of merge sort.
 *@param[in] input Array
 *@param[in] l Begin of array
 *@param[in] r End of array
 *@param[in] index Index of multidim. array
 *
 */
void mergeSort(int **input, int l, int r, int index){
    
    if(l < r){  //further recursion necessary?
        int mid = (l + r)/2;  //mid of array
        mergeSort(input, l, mid, index); //call for left part
        mergeSort(input, mid + 1, r, index);  //call for right part
        merge(input, l, mid, r, index); //merge the sorted output of left and right part
    }
}


