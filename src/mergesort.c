/** .
 * @file mergesort.h
 * for doxy
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "../include/search_index.h"

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
}

void mergeSort(int **input, int l, int r, int index){

    if(l < r){
        int mid = (l + r)/2;
        mergeSort(input, l, mid, index);
        mergeSort(input, mid + 1, r, index);
        merge(input, l, mid, r, index);
    }
}


