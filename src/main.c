/** .  
 * @file main.c
 * for doxy
 * 
 * 
 */

#include "../include/main.h"
#include "../include/menu.h"

int main(void) {
    printf("\nProgram starting...\n");
    show_menu();

/** Just an Example for debugging */
#if DEBUG 
	printf("Debugging Test...\n");
#endif

	parse_input();
    
    exit(EXIT_SUCCESS);
}