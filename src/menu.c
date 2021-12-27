
/** Module for the program menu and steering of performed actions.  
 * @file menu.c
 * 
 */

#include "../include/menu.h"

/** Struct mmenu (main menu) for showing user options */
menu_t mmenu[] = {
    {'1', "Mergesort"}, 
    {'2', "Quicksort"},
    {'3', "Bubblesort"}, 
    {'4', "Insertionsort"},
    {'M', "Show Menu"}, 
    {'X', "Exit Program"}};


/** Function delivers list of menu points */
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

/** Function parses user input on stdin */
void parse_input() {
	char input = 0;
	while (1) {
		input = getchar();
		while ((getchar() != '\n')&&(getchar() != EOF));  //delete input buffer or if returned EOF in case of error 
		switch (tolower(input)) {
		case '1':
			printf("Your choice: #%c\n", input);
            //result = msort(number_a, number_b);  //include functions here for sorting algorithms and outputs
            //printf("bla : %f\n", result);
			break;
		case '2': 
			printf("Your choice: #%c\n", input);
			break;
		case '3': 
			printf("Your choice: #%c\n", input);
			break;
		case '4': 
			printf("Your choice: #%c\n", input);
			break;
            /** // check return value for errors
			if (input == -1) {
				break;
			}
			break; */
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


