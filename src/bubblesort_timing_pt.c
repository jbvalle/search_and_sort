/** @brief This application performs a Runtime measurement assessment on bubblesort.
 *@file bubblesort_timing_pt.c 
 *
 * It uses a randomized array of size 2000 and sorts it 20 times repeatedly using the same set of numbers. Each time measuring the CPU time for each cycle. At the end displaying min, max, and avrg values.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 *@brief This function performs a specialized sorting algortihm for an array of size 2000 using bubblesort
 *@param[in] input Randomized array of size 2000
 */
void bubblesort_pt(int *input)
{

  if(input==NULL)return;

  for (int i = 0; i < 2000; i++) {

    int allignment_flag = 0;

    for (int j = 0; j < 2000-1; j++) {

      if (input[j] > input[j + 1]){

        int initial_value_buffer = input[j];
        input[j] = input[j + 1];
        input[j + 1] = initial_value_buffer;
        allignment_flag = 1;
      }
    }
    //Once all numbers have been ordered break the loop
    if (allignment_flag == 0) break;
  }

}

/**
 *@brief This function performs 20 cycles of bubblesort sorting on the same set of numbers, each time measuring the cpu time and outputting the measured values
 *@param[in] randomized Array to sort
 */
void bubblesort_timing_pt(int *randomized){

    clock_t time;

    float comp[20];
    float max = 0;
    float min = INFINITY;
    float avrg = 0;
    int temp[2000];

    printf("\n\n+-------+---------------+");
    printf("\n| Cycle | RUNTIME  [ms] |");
    printf("\n+-------+---------------+");


    for(int y = 0; y<20;y++)
    {
        for(int i = 0; i < 2000; i++)temp[i] = randomized[i];
    	time = clock();
    	bubblesort_pt(temp);
    	time = clock()-time;
    	comp[y] = (float)time/CLOCKS_PER_SEC;

        printf("\n|   %3d.|      %7.3f  |", y+1, 1000.*(float)time/CLOCKS_PER_SEC);

    }

    printf("\n+-------+---------------+\n\n");

    for(int count = 0; count < 20; count++)
    {

    	if(comp[count]>max)
    	{
    		max = comp[count];
    	}
    	if(comp[count]<min)
    	{
    		min = comp[count];
    	}

    }

    for(int s = 0; s<20;s++)avrg = comp[s] + avrg;

    printf("\n+----------+------------+------------+");
    printf("\n|  MAX[ms] |    MIN[ms] |   AVRG[ms] |");
    printf("\n+----------+------------+------------+");
    printf("\n|  %07.3f |    %07.3f |    %07.3f |", (double)max*1000., (double)min*1000., ((double)avrg/20)*1000.);
    printf("\n+----------+------------+------------+\n\n");

    /*
    for (int i = 0; i < 2000; i++)
    {
        printf("%d \n", temp[i]);
    }
    printf("\n");*/

}
