#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../include/randomizer_8_16_64.h"

void show_input(int **input){
    
    for(int i = 0, exp = 3; i < 3; i++){
        
        exp += i;
        for(int j = 0; j < pow(2,exp);j++){
            
            printf("%d| %d: %d\n", i, j, *(input[i] + j));
        }
    } 
}

void free_input(int **input){

    for(int i = 0; i < 3; i++){
        
        free(input[i]);
    } 
    free(input);
}

int main(void){

    int **input = (int **)malloc(3 * sizeof(int *));
    
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
    
    //Show array elements
    show_input(input); //To display remove Backslashes
    
    //Free input arrays
    free_input(input);
    return 0;
}
