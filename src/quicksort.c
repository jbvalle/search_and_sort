/** @brief This module applies the quicksort algorithm on randomized array
 *@file quicksort.c
 *
 */

#include<stdio.h>

/** @brief Switches values of two array elements
 *@param[in] arg1 First array element to be swapped
 *@param[in] arg2 Second array element to be swapped
 *
 */
void swap(int *arg1, int *arg2){
    int temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

/** @brief Partitions an array of elements and sorts by comparing pivot element
 *@param[in] input Array
 *@param[in] start_index First element in a partition
 *@param[in] end_index Last element in a partition 
 *@param[in] input_index Index number of array
 *@param[out] pivot_index position of current pivot
 */
int partition(int **input, int start_index, int end_index, int input_index){

    int pivot_value = *(input[input_index] + end_index);
    int pivot_index = start_index;

    for(int i = start_index; i < end_index; i++){
    
        if(*(input[input_index] + i) < pivot_value){

            swap((input[input_index] + i), (input[input_index] + pivot_index));
            pivot_index++;
        }
    }

    swap((input[input_index] + pivot_index), (input[input_index] + end_index));

    return pivot_index;
}

/** @brief Quicksorting algorithm by recursively partitioning and sorting an array
 *@param[in] input Array
 *@param[in] start_index First element in a partition
 *@param[in] end_index Last element in a partition 
 *@param[in] input_index Index number of array
 *
 */
void quicksort(int **input, int start_index, int end_index, int input_index){

    if(start_index < end_index){

        int pivot_index = partition(input, start_index, end_index, input_index);
        
        quicksort(input, start_index, pivot_index - 1, input_index);

        quicksort(input, pivot_index + 1, end_index, input_index);
    }
}


