
/** @brief Module for the program menu and steering of performed actions.  
 * @file menu.c
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h> // needed for function exit, dynamic memory mgmt
#include <ctype.h> // needed for function tolower
#include <time.h>
#include <math.h>
#include "../include/menu.h"
#include "../include/testing.h"
#include "../include/randomizer_pt.h"
#include "../include/node_t.h"
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/randomizer_8_16_64.h"
#include "../include/bubblesort.h"
#include "../include/insertionsort.h"
#include "../include/sortcheck.h"
#include "../include/mergesort.h"
#include "../include/search_index.h"
#include "../include/quicksort.h"
#include "../include/bubblesort_timing_pt.h"
#include "../include/insertion_sort_arr_ll.h"

/** @brief Define \c stdout Color */
#define COLOR "\033[1;31m"
#define RESET "\033[0m"
/** @brief Initializing struct mmenu (main menu) for showing user options */
menu_t mmenu[] = {
    {'1', "Basic implementation (1.1)"},
	{'2', "Performance comparison (1.2)"},
	{'3', "Bubblesort Array 2000 Performance comparison (1.3)"},
	{'4', "Insertion Sort Array - List Performance comparison (1.4)"},
	{'5', "Mergesort"}, 
    {'6', "Quicksort"},
    {'7', "Bubblesort"}, 
    {'8', "Insertionsort"},
    {'M', "Show Menu"}, 
    {'X', "Exit Program"}};


/** @brief Function delivers list of menu points */
void show_menu() {
    int nr_menu_points = sizeof(mmenu)/sizeof(menu_t);
    printf("Please choose from the following options\n");
    //printf("Please choose the sorting algorithm you want to use:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i<nr_menu_points; i++) {
        printf("\t(%c) %s\n", mmenu[i].symbol, mmenu[i].text);
    }
    printf("----------------------------------------\n");
}

/** @brief Function parses user input (single characters) on @c stdin */
void parse_input() {

	char input = 0;
	while (1) {
		printf("\n>");
		input = getchar();
		while ((getchar() != '\n')&&(getchar() != EOF));  //delete input buffer or if returned EOF in case of error 
		switch (tolower(input)) {
		case '1':
			printf("Your choice: #%c %s\n", input, mmenu[0].text);
			testing();
			break;
		case '2': 
			printf("Your choice: #%c %s\n", input, mmenu[1].text);
			perf_test();
			break;
		case '3':{
            printf("\n\n+---------------------------------------------+");
			printf("\n| BUBBLESORT PERFORMANCE TEST ARRAY SIZE 2000 |");
            printf("\n+---------------------------------------------+\n\n");
            //Performs bubblesort algorithm on a generated randomized array of size 2000
            //Subsequently sorting the same set of numbers 20 times and comparing cpu time
            
            int randomized[2000];

            srand(time(NULL));

            for(int x = 0; x<2000; x++)
            {
                randomized[x] = (double)65536*((double)rand()/(double)RAND_MAX) - 32768.;
            }

            bubblesort_timing_pt(randomized);
        }	break;
		case '4': 
          printf("\n\n+---------------------------------------------+");
			printf("\n| INSERTIONSORT PERFORMANCE TEST ARRAY - LIST |");
            printf("\n+---------------------------------------------+\n\n");
            insertionsort_arr_ll();
			break;
		case '5':{

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

            free_8_16_64(input);
        }break;
		case '6': {

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

            free_8_16_64(input);
        }break;
		case '7': {

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

   
            //==============
            //Bubblesort
            //==============
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

            free_8_16_64(input);
        }	break;
		case '8': {

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
            printf("\n\n");printf(COLOR);printf("+-------------------------+\n");
            printf(COLOR);printf("| Sorted by Insertionsort |\n");
            printf(COLOR);printf("+-------------------------+\n");printf(RESET);
            insertionsort(input, 8);
            insertionsort(input, 16);
            insertionsort(input, 64);
            //Show array elements
            show_8_16_64(input, 10); //To display remove Backslashes
        
            free_8_16_64(input);
        }	break;
		case 'm':
            show_menu();
            continue;
		case 'x':
			printf("Closing program...\n\n");
            exit(EXIT_SUCCESS);
		default:
			printf("Please use ""'M'"" (for menu) to show viable options.\n");
			break;
		}
	} //end while
}


