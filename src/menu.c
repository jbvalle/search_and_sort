
/** @brief Module for the program menu and steering of performed actions
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
    printf("----------------------------------------\n");
    for (int i = 0; i<nr_menu_points; i++) {
        printf("\t(%c) %s\n", mmenu[i].symbol, mmenu[i].text);
    }
    printf("----------------------------------------\n");
}

/** @brief Function parses user input (single characters) on @c stdin and features the switch to steer program output */
void parse_input() {
	char input = 0;
	while (1) {
		printf("\n>");
		input = getchar();
		while ((getchar() != '\n')&&(getchar() != EOF));  //delete input buffer or if returned EOF in case of error 
		switch (tolower(input)) {
		case '1':
			printf("Your choice: #%c %s\n", input, mmenu[0].text);
			bs();
            is();
            ms();
            qs();
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
            //Perform Insertion Sort Performance Test Array List
            insertionsort_arr_ll();
			break;
		case '5':
            printf("Your choice: #%c %s\n", input, mmenu[4].text);
            ms();
            break;
		case '6': 
            printf("Your choice: #%c %s\n", input, mmenu[5].text);
            qs();
            break;
		case '7': 
            printf("Your choice: #%c %s\n", input, mmenu[6].text);
            bs();
            break;
		case '8': 
            printf("Your choice: #%c %s\n", input, mmenu[7].text);
            is();
            break;
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


