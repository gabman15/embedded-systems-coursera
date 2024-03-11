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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

<<<<<<< HEAD
=======
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
>>>>>>> dev_c1m1

#endif /* __STATS_H__ */
