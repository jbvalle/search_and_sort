/** @brief just for testing...
 * @file testing.c
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "../include/node_t.h"
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/randomizer_8_16_64.h"
#include "../include/randomizer_pt.h"
#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/sortcheck.h"
#include "../include/mergesort.h"
#include "../include/search_index.h"
#include "../include/quicksort.h"
#include "../include/testing.h"

/** @brief Define \c stdout Color */
#define COLOR "\033[1;31m"
#define RESET "\033[0m"

void append_node(node_t **head, int num){

    node_t *ptr = *head;

    node_t *new = malloc(sizeof(node_t));
    new->num = num;
    new->next = NULL;

    if(*head == NULL){

        *head = new;
        return;
    }

    for(; ptr->next != NULL; ptr = ptr->next);
    
    ptr->next = new;
}

void populate_list(node_t **head, int *arr, int size){

   for(int i = 0; i < size; i++)append_node(head, arr[i]); 

}

void sorted_insert(node_t **sorted, node_t *new){


    if((*sorted) == NULL || ((*sorted)->num) >= new->num){

        new->next = *sorted;
        *sorted = new;
    }else{

        node_t *curr_ptr = *sorted;

        while(curr_ptr->next != NULL && (curr_ptr->next->num <= new->num)){
            
            curr_ptr = curr_ptr->next;
        }

        new->next = curr_ptr->next;
        curr_ptr->next = new;
    }
}


void insertionSort(node_t **head){

    node_t *sorted = NULL;

    node_t *curr_ptr = *head;

    while(curr_ptr != NULL){

        node_t *temp = curr_ptr->next;

        sorted_insert(&sorted, curr_ptr);
        
        curr_ptr = temp;
    }

    *head = sorted;
}

void free_list(node_t *head){

    node_t *ptr = head;

    while(ptr != NULL){

        node_t *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}
/** @brief Function to create and call free dyn. memory as well as call subfunctions for performance test. 
 * @param[in] arg1 First Array Element to be swapped
 * @param[in] arg2 Second Array Element to be swapped
 * @param[out] arg3 
 * 
 */
void testing(){
    
    int **input = (int **)malloc(3 * sizeof(int *));
    *input       = malloc(8 * sizeof(int));
    *(input + 1) = malloc(16 * sizeof(int));
    *(input + 2) = malloc(64 * sizeof(int));

    printf("\n\n");printf(COLOR);printf("+-------------------+\n");
    printf(COLOR);printf("| Randomized Arrays |\n");
    printf(COLOR);printf("+-------------------+\n");printf(RESET);
    //printf(RESET);
    //inputs are accessible through 
    //input[0]...8, input[1]...16, input[2]...64
    randomizer_8_16_64(input);
     //Show array elements
    show_8_16_64(input, 10); //To display remove Backslashes
    
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+----------------------+\n");
    printf(COLOR);printf("| Sorted by Bubblesort |\n");
    printf(COLOR);printf("+----------------------+\n");printf(RESET);
    //Testing sort algorithm for all 3 array of 1.1 
    bubblesort(input, 8);
    #if ERRFLAG 
        **(input)=-1000;  //Added for testing purposes
        if (sortcheck(input,8) != 0) {
            printf(COLOR);printf("\nProblems in result of sorting algorithm found...\n\n");printf(RESET);
            //exit(EXIT_SUCCESS);
        }
    #endif
    bubblesort(input, 16);
    //sortcheck(input,16);
    bubblesort(input, 64);
    //sortcheck(input,64);
    //Display
    show_8_16_64(input, 10); //To display remove Backslashes

    
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("| Sorted by Insertionsort |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    insertionsort(input, 8);
    insertionsort(input, 16);
    insertionsort(input, 64);
    //Show array elements
    show_8_16_64(input, 10); //To display remove Backslashes
        

    //-------------------------------------------------
    //Mergesort
    //Create Randomized Arrays
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|   Sorted by Mergesort   |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    //Implement Mergesort
    //1. generate Index for array size
    //Call Mergesort function
    mergeSort(input, 0, 7, search_index(8));
    mergeSort(input, 0, 15, search_index(16));
    mergeSort(input, 0, 63, search_index(64));
    //Show array elements
    show_8_16_64(input, 10);

    //-------------------------------------------------
    //Quicksort
    //Create Randomized Arrays
    randomizer_8_16_64(input);
    printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
    printf(COLOR);printf("|   Sorted by Quicksort   |\n");
    printf(COLOR);printf("+-------------------------+\n");printf(RESET);
    //Implement Quicksort
    //1. generate Index for array size
    //Call Quicksort function
    quicksort(input, 0, 7, search_index(8));
    quicksort(input, 0, 15, search_index(16));
    quicksort(input, 0, 63, search_index(64));
    //Show array elements
    show_8_16_64(input, 10);
    //Free input arrays
    free_8_16_64(input);


    //===================================================
    //Insertionsort ARRAYS-LINKED-LIST Perfomance test
    //===================================================
    //Saves CPU Runtime value of a single function
    double pt_cpu_time_sec[2] = {0, 0};

    //Save temporary clocks at current time
    clock_t cpu_time_clk;

    //Allocate HEAD Node for Linked list
    node_t *head = NULL;
    //Allocate Memory for Randomized ARRAY
    int **input_pt = (int **)malloc(7 * sizeof(int *));
    randomizer_pt(input_pt);

    //Fill linked list with values of randomized list of size 2048
    populate_list(&head, input_pt[search_index(2048)], 2048);

    //==============================================
    // INSERTION SORT FOR LINKED LIST 
    //==============================================
    //Measure Clock at current time
    cpu_time_clk = clock();
    //Perform Insertionsort for Linked List
    insertionSort(&head);
    //Measure Clock at current time
    cpu_time_clk = clock();
    pt_cpu_time_sec[0] = (double)cpu_time_clk/(double)CLOCKS_PER_SEC;
    //==============================================

    //==============================================
    // INSERTION SORT FOR ARRAY
    //==============================================
    //Measure Clock at current time
    cpu_time_clk = clock();
    //Perform Insertionsort for Array
    insertionsort(input_pt, 2048);
    //Measure Clock at current time
    cpu_time_clk = clock();
    pt_cpu_time_sec[1] = (double)cpu_time_clk/(double)CLOCKS_PER_SEC;
    //==============================================

    //Show list for linked list
    show_randomizer_pt_list(head, search_index(2048),15);

    //Show list of array
    show_randomizer_pt_index(input_pt, search_index(2048),15);
    
    printf("\033[1;93m");
    printf("\n\n+-----------------------------------------------------------------+");
    printf("\n| RUNTIME-LINKED-LIST[ms]: %2.3fms | RUNTIME-ARRAY[ms]: %2.3fms |", pt_cpu_time_sec[0]*1000., pt_cpu_time_sec[1]*1000.);
    printf("\n+-----------------------------------------------------------------+\n");
    printf("\033[0m");

    free_pt(input_pt); 
    free_list(head);
}
