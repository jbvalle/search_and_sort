/** .
 * @file bubblesort.c
 * for doxy
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/search_index.h"

void bubblesort(int **input, int sizeof_array){

  int index = search_index(sizeof_array);

  for (int i = 0; i < sizeof_array-1; i++) {

    int allignment_flag = 0;

    for (int j = 0; j < sizeof_array-1; j++) {

      if (*(input[index] + j) > *(input[index] + (j + 1))){

        int initial_value_buffer = *(input[index] + j);
        *(input[index] + j) = *(input[index] + (j + 1));
        *(input[index] + (j + 1)) = initial_value_buffer;
        allignment_flag = 1;
      }
    }
    //Once all numbers have been ordered break the loop
    if (allignment_flag == 0) break;
  }
}
