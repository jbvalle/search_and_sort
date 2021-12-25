/** .  
 * @file randomizer_8_16_64.c
 * for doxy
 * 
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//STDOUT Color
#define COLOR "\033[0;33m"
#define RESET "\033[0m"

int randomizer_8_16_64(int **input){
    //0. 2 ^ exp = 8, 16, 64
    //1. 2 ^ (3 + 0) = 8
    //2. 2 ^ (3 + 1) = 16
    //3. 2 ^ (4 + 2) = 64
    if(input == NULL){
        perror("ERROR: NULL Pointer as Input Value");
        return 1;
    }

    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));

    //Plant rand() seed
    srand(time(NULL));
    //Assign unique randoms to each input array element
    for(int i = 0, exp = 3; i < 3; i++){

        exp += i;
        for(int j = 0; j < pow(2,exp);){
            
            //2 ^ 15 = 32768 | 2 ^ 16 = 65536
            int x, random_num = -pow(2,15) + rand()%(int)pow(2,16);
            //Check for duplicates, if found -> break and continue searching
            for(x = 0; x < j; x++){

                if(*(input[i] + x) == random_num)break;
            }
            //No duplicates found assign random_num to array
            if(x == j)*(input[i] + j++) = random_num;
        }
    }   
    return 0;
}

void show_8_16_64(int **input, int max_cols){
    
    int format_count;

    for(int i = 0, exp = 3; i < 3; i++){
        
        exp += i;
       
        //Array Bezeichnung
        printf("\n\n  +---------------------+\n");
        printf("  |%1d. Array with size %2d|\n", i + 1, (int)pow(2,exp));
        printf("  +---------------------+\n");
        //Displays arrays in 8 | 16 | 64 partitions with added formatting
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

void free_8_16_64(int **input){

    for(int i = 0; i < 3; i++){
        
        free(input[i]);
    } 
    free(input);
}


