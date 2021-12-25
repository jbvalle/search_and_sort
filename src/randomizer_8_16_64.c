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

void show_8_16_64(int **input){
    
    for(int i = 0, exp = 3; i < 3; i++){
        
        exp += i;
        for(int j = 0; j < pow(2,exp);j++){
            
            if(j%14 == 0){
                printf("\n");
                for(int i = 0; (i < 14) && (i < pow(2,exp)); i++)printf("+------+");
                printf("\n");
            }
            printf("|%6d|", *(input[i] + j));
        }
        printf("\n");
        for(int i = 0; (i < 14) && (i < pow(2,exp)); i++)printf("+------+");
        printf("\n");
    } 
}

void free_8_16_64(int **input){

    for(int i = 0; i < 3; i++){
        
        free(input[i]);
    } 
    free(input);
}


