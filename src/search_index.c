/** Module for getting the index of arrays.
 * @file search_index.c
 * Detailed description
 */
#include <stdio.h>
#include <stdlib.h>

//**input stores array values in *input[0 - x] 
//i.e. 32 Number Array is accessable through *(input[index] + x) | with index = 1
//To create a **input which can be used for arr_long/short a generic algorithm like
//search_index is used to return index without the need to specify long or short index
int search_index(int num){

    int arr_long[] = {8, 32, 128, 512, 2048, 8192, 32768};
    int arr_short[] = {8, 16, 64};
    int index;

    for(index = 0; ; index++){
        if((arr_long[index%7] == num)||(arr_short[index%3] == num))break;
    }
    return index;
}
