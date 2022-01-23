/**
 *@brief This Module includes all function needed for performing a cpu runtime measurement assessing the performance of the insertionsort algorithm applied on a array and a linked list
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "../include/node_t.h"
#include "../include/randomizer_8_16_64.h"
#include "../include/randomizer_pt.h"
#include "../include/insertionsort.h"
#include "../include/sortcheck.h"
#include "../include/mergesort.h"
#include "../include/search_index.h"
#include "../include/quicksort.h"

/**
 *@brief This function appends a new node with a given number element
 *@param[in] head Head of current list
 *@param[in] num Number element of new node
 *
 */
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

/**
 *@brief Appends new nodes with provided number element from randomized array
 *@param[in] head Current Head of list 
 *@param[in] arr Array of randomized numbers
 *@param[in] size Array size 
 *
 */
void populate_list(node_t **head, int *arr, int size){

   for(int i = 0; i < size; i++)append_node(head, arr[i]); 

}

/**
 *@brief This function inserts the new node in an alphabetical order
 *@param[in] sorted Head of sorted list
 *@param[in] new Current node element  
 *
 */
void sorted_insert(node_t **sorted, node_t *new){


    ///1. Checks if first element is null or if first element's word is a 'subsequent' word of new
    if((*sorted) == NULL || ((*sorted)->num) >= new->num){

        ///2. Stack new word unto list if first element is either Null or a subsequent word 
        new->next = *sorted;
        *sorted = new;
    }else{

        ///3. Traverse through list until elements list is a subsequent element to new element
        node_t *curr_ptr = *sorted;

        while(curr_ptr->next != NULL && (curr_ptr->next->num <= new->num)){
            
            curr_ptr = curr_ptr->next;
        }

        ///4. Insert new element behind the supposedly subsequent list's element
        new->next = curr_ptr->next;
        curr_ptr->next = new;
    }
}


/**
 *@brief This function traverses though list and adds any subsequent word into the sorted list
 *@param[in] head Head of current Bucket
 */


void insertionSort(node_t **head){


    ///1. Initialize head of sorted list
    node_t *sorted = NULL;

    node_t *curr_ptr = *head;

    ///2. Traverse through list and add subsequnent elements to the sorted list
    while(curr_ptr != NULL){

        node_t *temp = curr_ptr->next;

        sorted_insert(&sorted, curr_ptr);
        
        curr_ptr = temp;
    }

    ///3. Assign new head of sorted list to original head
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
/**
 *@brief This function Performs the complete performance test of insertion sort algorithm for lists and arrays
 *
 */
void insertionsort_arr_ll(){

    //===================================================
    ///1. Insertionsort ARRAYS-LINKED-LIST Perfomance test
    //===================================================
    ///Saves CPU Runtime value of a single function
    double pt_cpu_time_sec[2] = {0, 0};

    ///Save temporary clocks at current time
    clock_t cpu_time_clk;

    ///Allocate HEAD Node for Linked list
    node_t *head = NULL;
    ///Allocate Memory for Randomized ARRAY
    int **input_pt = (int **)malloc(7 * sizeof(int *));
    randomizer_pt(input_pt);

    ///Fill linked list with values of randomized list of size 2048
    populate_list(&head, input_pt[search_index(2048)], 2048);

    //==============================================
    ///2. INSERTION SORT FOR LINKED LIST 
    //==============================================
    ///Measure Clock at current time
    cpu_time_clk = clock();
    ///Perform Insertionsort for Linked List
    insertionSort(&head);
    ///Measure Clock at current time
    cpu_time_clk = clock();
    pt_cpu_time_sec[0] = (double)cpu_time_clk/(double)CLOCKS_PER_SEC;
    //==============================================

    //==============================================
    ///3. INSERTION SORT FOR ARRAY
    //==============================================
    ///Measure Clock at current time
    cpu_time_clk = clock();
    ///Perform Insertionsort for Array
    insertionsort(input_pt, 2048);
    ///Measure Clock at current time
    cpu_time_clk = clock();
    pt_cpu_time_sec[1] = (double)cpu_time_clk/(double)CLOCKS_PER_SEC;
    //==============================================

    ///Show list for linked list
    show_randomizer_pt_list(head, search_index(2048),15);

    ///Show list of array
    show_randomizer_pt_index(input_pt, search_index(2048),15);
    
    printf("\033[1;93m");
    printf("\n\n+-----------------------------------------------------------------+");
    printf("\n| RUNTIME-LINKED-LIST[ms]: %2.3fms | RUNTIME-ARRAY[ms]: %2.3fms |", pt_cpu_time_sec[0]*1000., pt_cpu_time_sec[1]*1000.);
    printf("\n+-----------------------------------------------------------------+\n");
    printf("\033[0m");

    free_pt(input_pt); 
    free_list(head);

}
