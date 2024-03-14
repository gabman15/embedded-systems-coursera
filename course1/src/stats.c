/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Analyzes an array and reports analytics on the data
 *
 * Takes an array of unsigned char data items and finds
 * the maximum, minimum, mean, and median of the data set.
 *
 * @author gabman15
 * @date 03/11/24
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*int main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
#ifdef VERBOSE
    PRINTF("Unsorted Array:\n");
    print_array(test,SIZE);
    PRINTF("\nSorting Array...\n\n");
    sort_array(test,SIZE);
    PRINTF("Sorted Array:\n");
    print_array(test,SIZE);
    PRINTF("\n");
    print_statistics(test, SIZE);
#endif
    return 0;
}*/

void print_statistics(unsigned char *arr, unsigned int len) {
#ifdef VERBOSE
    unsigned char median = find_median(arr, len);
    unsigned char mean = find_mean(arr, len);
    unsigned char max = find_maximum(arr, len);
    unsigned char min = find_minimum(arr, len);

    PRINTF("Statistics:\nMedian: %d\nMean: %d\nMaximum: %d\nMinimum: %d\n",
           median, mean, max, min);
#endif
}

void print_array(unsigned char *arr, unsigned int len) {
#ifdef VERBOSE
    PRINTF("Printing Array:\n");
    int i;
    for (i = 0; i < len; i++) {
        if (i == len-1)
            PRINTF("%3d",arr[i]);
        else {
            PRINTF("%3d, ",arr[i]);
            if ((i+1) % 8 == 0)
                PRINTF("\n");
        }
    }
    PRINTF("\n\n");
#endif
}

unsigned char find_median(unsigned char *arr, unsigned int len) {
    if (len == 1)
        return arr[0];
    if (len % 2 == 0) { //even
        int middle = len / 2;
        // return mean of the two middle numbers
        return ((arr[middle - 1] + arr[middle]) / 2);
    } else //odd
        return arr[len / 2];
}

unsigned char find_mean(unsigned char *arr, unsigned int len) {
    unsigned int sum = 0;
    int i;
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }
    
    return (unsigned char) (sum / len);
}

unsigned char find_maximum(unsigned char *arr, unsigned int len) {
    unsigned char max = arr[0];
    int i;
    for (i = 1; i < len; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

unsigned char find_minimum(unsigned char *arr, unsigned int len) {
    unsigned char min = arr[0];
    int i;
    for (i = 1; i < len; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void swap (unsigned char *first, unsigned char *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void sort_array(unsigned char *arr, unsigned int len) {
    int i, j, max_index;

    for (i = 0; i < len - 1; i++) {
        max_index = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] > arr[max_index])
                max_index = j;
        }
        if (max_index != i)
            swap(&arr[max_index], &arr[i]);
    }
}
