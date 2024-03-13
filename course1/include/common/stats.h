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
 * @file stats.h
 * @brief Analyzes an array and reports analytics on the data
 *
 * Takes an array of unsigned char data items and finds
 * the maximum, minimum, mean, and median of the data set.
 *
 * @author gabman15
 * @date 03/11/24
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief print_statistics
 *
 * A function that prints the statistics of an array including
 * minimum, maximum, mean, and median.
 *
 * @param arr The array to print statistics about
 * @param len The array's length
 *
 * @effects Prints min, max, mean, and median of the array
 *
 * @returns nothing
 */

void print_statistics(unsigned char *arr, unsigned int len);

/**
 * @brief print_array
 *
 * A function that prints the contents of an array
 *
 * @param arr The array to print statistics about
 * @param len The array's length
 *
 * @effects Prints the contents of the array
 *
 * @returns nothing
 */
void print_array(unsigned char *arr, unsigned int len);

/**
 * @brief find_median
 *
 * A function that finds the median of an array
 *
 * @param arr The array to find the median of
 * @param len The array's length
 *
 * @returns an 8-bit char that is the median of the array
 */
unsigned char find_median(unsigned char *arr, unsigned int len);

/**
 * @brief find_mean
 *
 * A function that finds the mean of an array
 *
 * @param arr The array to find the mean of
 * @param len The array's length
 *
 * @returns an 8-bit char that is the mean of the array
 */
unsigned char find_mean(unsigned char *arr, unsigned int len);

/**
 * @brief find_maximum
 *
 * A function that finds the maximum of an array
 *
 * @param arr The array to find the maximum of
 * @param len The array's length
 *
 * @returns an 8-bit char that is the maximum of the array
 */
unsigned char find_maximum(unsigned char *arr, unsigned int len);

/**
 * @brief find_minimum
 *
 * A function that finds the minimum of an array
 *
 * @param arr The array to find the minimum of
 * @param len The array's length
 *
 * @returns an 8-bit char that is the minimum of the array
 */
unsigned char find_minimum(unsigned char *arr, unsigned int len);

/**
 * @brief sort_array
 *
 * A function that sorts the given array from largest to smallest
 *
 * @param arr The array to sort
 * @param len The array's length
 *
 * @effects the array passed in is sorted by reference
 *
 * @returns nothing
 */
void sort_array(unsigned char *arr, unsigned int len);

#endif /* __STATS_H__ */
