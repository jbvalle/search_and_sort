#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/randomizer_8_16_64.h"

#define DEBUG 1

void randomizer_debug(){
    
    int **input = (int **)malloc(3 * sizeof(int *));
    
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
    
    //Show array elements
    show_8_16_64(input); //To display remove Backslashes
        
    //Free input arrays
    free_8_16_64(input);
}


int main(void){

    if(DEBUG)randomizer_debug();    
    
    return 0;
}
