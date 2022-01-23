/** @brief Module for implementation of Mergesort algorithm 
 * @file mergesort.c
 *
 * These functions perform the sorting of a randomized set of numbers using mergesort.
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/search_index.h"


/**
 *@brief this function merge two sorted sets of arrays into one Array
 *@param[in] input Randomized set of numbers stored in an Array of pointers
 *@param[in] low Represents the first element of the sorted array
 *@param[in] mid Represents the center element of a sorted array
 *@param[in] high Represents the last element of a sorted Array
 *@param[in] index Index is the Pointer within the double pointer which stores the address of the first element of an Array which is to be sorted
 *
 * Additional temporary array is used to store sorted numbers.
 */
void merge(int **input, int low, int mid, int high, int index) {

    //i...index for left partition | j ... index for right partition | 
    //k...index for original randomized_array
    //temp ... saves the sorted numbers in temporary array
    int i, j, k, *temp = malloc((high - low + 1)*sizeof(int));

    //Iterate through two partitions of arrays respectively comparing the smaller number and storing it in a temporary array
    for(i = low, j = mid + 1, k = 0; (i <= mid)&&(j <= high); k++){

        if(*(input[index] + i) < *(input[index] + j)){

            temp[k] = *(input[index] + i++);
        }else{

            temp[k] = *(input[index] + j++);
        }
    }
    //In case one of the arrays has reached their limited size to be compared, the remaining numbers will be stored in a temp[]
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
 *@brief This function partitions an array and respectively sorts each array, subsequently merge sorting the array recursively
 *@param[in] input Randomized set of numbers stored in an Array of pointers
 *@param[in] l Represents the first element of the current array
 *@param[in] r Represents the last element of the current array
 *@param[in] index Index is the Pointer within the double pointer which stores the address of the first element of an Array which is to be sorted
 */
void mergeSort(int **input, int l, int r, int index){
    //Partitions an array until only individual elements remain, subsequently mergesorting the elements recursively
    if(l < r){  //further recursion necessary?
        int mid = (l + r)/2;  //mid of array
        mergeSort(input, l, mid, index); //call for left part
        mergeSort(input, mid + 1, r, index);  //call for right part
        merge(input, l, mid, r, index); //merge the sorted output of left and right part
    }
}


