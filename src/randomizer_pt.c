/** .
 * @file randomizer_pt.c
 * for doxy
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//STDOUT Color
#define COLOR "\033[0;93m"
#define RESET "\033[0m"

//Randomizer PERFORMANCE TEST
int randomizer_pt(int **input){
    //0. 2 ^ exp = 8, 32, 128, etc.
    //1. 2 ^ (3 + 0) = 8
    //2. 2 ^ (3 + 2) = 32
    //3. 2 ^ (5 + 2) = 128
    if(input == NULL){
        perror("ERROR: NULL Pointer as Input Value");
        return 1;
    }
    /*
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));*/
    for(int i = 0, exp = 1; i < 7; i++){
        exp += 2;
        *(input + i) = (int*)malloc(pow(2,exp) * sizeof(int));
    }
    
    //Plant rand() seed
    srand(time(NULL));
    
    //Assign unique randoms to each input array element
    for(int i = 0, exp = 1; i < 7; i++){

        exp += 2;
        for(int j = 0; j < pow(2,exp);){
            
            //2 ^ 15 = 32768 | 2 ^ 16 = 65536
            int random_num = -32768 + 65536*(rand()/(RAND_MAX + 1.0));
            *(input[i] + j++) = random_num;
        }
    }   
    return 0;
}

void show_randomizer_pt(int **input, int max_cols){
    
    int format_count;

    for(int i = 0, exp = 1; i < 7; i++){
        
        exp += 2;
       
        //Array Bezeichnung
    printf("\n\n  +-----------------------------------+\n");
        printf("  | %1d. Array with size %5d elements |\n", i + 1, (int)pow(2,exp));
        printf("  +-----------------------------------+\n");
        //Displays arrays in partitions with added formatting
        for(int j = 0; j < pow(2,exp);j++){
            
            if(j % max_cols == 0){
                printf("\n");
                if(j > 0){
                    for(int k = 0; k < max_cols; k++)printf("  +------+");
                    printf("\n");
                }
                for(format_count = 0; (format_count < max_cols) && (format_count < pow(2,exp) - j); format_count++)printf("  +------+");
                printf("\n");
            }
            
            printf("  |");printf(COLOR);
            printf("%6d",*(input[i] + j));printf(RESET);
            printf("|");
        }
        printf("\n");
        for(int i = 0; i < format_count; i++)printf("  +------+");
    } 
}

void free_pt(int **input){

    /* for(int i = 0; i < 7; i++){
        
        free(input[i]);
    }  */
    free(input);
}


