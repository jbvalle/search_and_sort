/** @brief Header file for performance test module. 
 * @file randomizer_pt.h
 * 
 */
#ifndef RANDOMIZER_PT_H
#define RANDOMIZER_PT_H

int randomizer_pt(int **input);
void show_randomizer_pt(int **input, int max_cols);
void free_pt(int **input);

int perf_test();
void run_algos(int **begarr_pt);
void reset_values(int **output, int **input, int exp, int i);
void reverse(int **input_pt, int index, int sizeof_array);

#endif
