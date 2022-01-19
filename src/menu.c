
/** @brief Module for the program menu and steering of performed actions.  
 * @file menu.c
 */

#include <stdio.h>
#include <stdlib.h> // needed for function exit, dynamic memory mgmt
#include <ctype.h> // needed for function tolower
#include "../include/menu.h"
#include "../include/testing.h"
#include "../include/randomizer_pt.h"

/** @brief Initializing struct mmenu (main menu) for showing user options */
menu_t mmenu[] = {
    {'1', "Basic implementation (1.1)"},
	{'2', "Performance comparison (1.2)"},
	{'3', "Mergesort"}, 
    {'4', "Quicksort"},
    {'5', "Bubblesort"}, 
    {'6', "Insertionsort"},
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
		case '3':
			printf("Your choice: #%c\n", input);
			break;
		case '4': 
			printf("Your choice: #%c\n", input);
			break;
		case '5': 
			printf("Your choice: #%c\n", input);
			break;
		case '6': 
			printf("Your choice: #%c\n", input);
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


