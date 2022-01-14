/**
 *@file quicksort.c
 *This modules applies the quicksort algorithm on randomized array
 */

#include<stdio.h>

/**
 *@param[in] arg1 First Array Element to be swapped
 *@param[in] arg2 Second Array Element to be swapped
 *Switches Values of two Array Elements
 */
void swap(int *arg1, int *arg2){

    int temp = *arg1;
    *arg1 = *arg2;
    *arg2 = temp;
}

/**
 *@param[in] input Array
 *@param[in] start_index First Element in Partition
 *@param[in] end_index Last element in a Partition 
 *@param[in] input_index Index number of Array of pointer of randomized array
 *@param[out] pivot_index position of current Pivot
 *Paritions an Array of Elements and sorts by comparing pivot element
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

/**
 *@param[in] input Array
 *@param[in] start_index First Element in Partition
 *@param[in] end_index Last element in a Partition 
 *@param[in] input_index Index number of Array of pointer of randomized array
 *Quicksorting Algorithm by recursively paritioning and sorting and Array
 */
void quicksort(int **input, int start_index, int end_index, int input_index){

    if(start_index < end_index){

        int pivot_index = partition(input, start_index, end_index, input_index);
        
        quicksort(input, start_index, pivot_index - 1, input_index);

        quicksort(input, pivot_index + 1, end_index, input_index);
    }
}


