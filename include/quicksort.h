/** @brief Header file for quicksort module.  
 * @file quicksort.h
 * 
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H


void swap(int *arg1, int *arg2);

int partition(int**, int, int, int);

void quicksort(int**, int, int, int);
#endif
