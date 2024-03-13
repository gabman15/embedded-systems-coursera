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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 * Edited by:
 * @author gabman15
 * @date 03/13/24
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move a length of bytes from one location to another
 *
 * Given two byte pointers, moves a length of bytes from a source ptr to
 * a destination ptr
 * Overlap of source and destination can occur with no corruption
 *
 * @param src Pointer to move data from
 * @param dst Pointer to move data to
 * @param length Number of bytes to move
 *
 * @return a pointer to the destination dst
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy a length of bytes from one location to another
 *
 * Given two byte pointers, copies a length of bytes from a source ptr to
 * a destination ptr
 * Overlap of source and destination cannot occur, will likely corrupt
 *
 * @param src Pointer to copy data from
 * @param dst Pointer to copy data to
 * @param length Number of bytes to copy
 *
 * @return a pointer to the destination dst
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets locations in memory to a given value
 *
 * From a source memory location, sets each location to specified value for
 * the given length
 *
 * @param src Source pointer of where to start setting memory values
 * @param length Number of bytes to set
 * @param value Value to set the memory locations to
 *
 * @return a pointer to the source src
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets locations in memory to zero
 *
 * From a source memory location, sets each location to zero for
 * the given length
 *
 * @param src Source pointer of where to start clearing memory values
 * @param length Number of bytes to clear
 *
 * @return a pointer to source src
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of a length of bytes
 *
 * Given a pointer to a memory location and a length in bytes,
 * reversethe order of all of the bytes
 *
 * @param src Pointer to the start of the memory location
 * @param length The number of bytes to reverse
 *
 * @return a pointer to source src
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates a number of words in dynamic memory
 *
 * Given a length, allocates that many 32 bit words and returns the pointer
 * to where those words are located
 *
 * @param length Number of 32 bit words to allocate
 *
 * @return a pointer to the memory location that has been allocated
 */
uint32_t * reserve_words(size_t length);

/**
 * @brief Frees memory allocations
 *
 * Given a pointer to an allocated memory location, it will free the dynamic
 * memory allocation.
 *
 * @param src Pointer to the allocated memory location
 *
 * @return void.
 */
void free_words(uint32_t * src);



#endif /* __MEMORY_H__ */
