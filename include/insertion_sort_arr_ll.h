/**
 *@brief Prototype for insertionsort perforance test
 *
 */
#ifndef INSERTION_SORT_ARR_LL_H
#define INSERTION_SORT_ARR_LL_H

#include "../include/node_t.h"

void append_node(node_t **head, int num);

void populate_list(node_t **head, int *arr, int size);

void sorted_insert(node_t **sorted, node_t *new);

void insertionSort(node_t **head);

void free_list(node_t *head);

void insertionsort_arr_ll();
#endif
