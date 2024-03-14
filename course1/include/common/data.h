/**
 * @file data.h
 * @brief Basic data manipulation
 *
 * This header file provides an abstraction for
 * integer and ascii string data conversions
 *
 * @author gabman15
 * @date 03/14/24
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>
#include "memory.h"

#define BASE_16 (16)
#define BASE_10 (10)
#define BASE_8 (8)
#define BASE_2 (2)

/**
 * @brief Integer to Ascii
 *
 * Converts data from a standard integer type into an ascii string
 *
 * @param data Signed 32-bit integer to be converted into a string
 * @param ptr Pointer that the converted character string will be copied to
 * @param base Integer value of the base you wish to convert to
 *
 * @return length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Ascii to Integer
 *
 * Converts data from an ascii string to an integer type
 *
 * @param ptr Pointer to the character string to be converted
 * @param digits Number of digits in your character set
 * @param base Integer value of the base you wish to convert to
 *
 * @return the converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
