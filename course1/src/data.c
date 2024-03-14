/**
 * @file data.c
 * @brief Basic data manipulation
 *
 * This file implements integer and ascii string data conversions
 *
 * @author gabman15
 * @date 03/14/24
 */

#include "data.h"

#define BITS_PER_BYTE (8)
#define ASCII_DIGIT_OFFSET (48)
#define ASCII_ALPHA_OFFSET (65)

#define NEGATIVE_ASCII (45)
#define NULL_ASCII (0)

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    // Don't handle if ptr is not allocated, 
    if (!ptr) 
        return 0;

    // Don't handle if the base is invalid or too big
    if (base < BASE_2 || base > BASE_16)
        return 0;
    
    uint8_t negative = 0;
    size_t length = 0;
    if (data < 0) { // If data is negative
        negative = 1;
        data = -data;
    }
    
    while (data > 0) {
        uint8_t digit = data % base; // Get first digit by finding remainder of base
        data /= base;
        if (digit > 9) { // If digit is bigger than 9, use letters
            digit -= 10;
            digit += ASCII_ALPHA_OFFSET;
        }
        else
            digit += ASCII_DIGIT_OFFSET; // Get ascii representation of digit
        // Add digit to string with least significant digit first
        *(ptr + length) = digit;
        length++;
    }
    
    my_reverse(ptr, length); // Reverse order of digits

    if (negative) { //If the number was negative
        my_memmove(ptr, ptr + 1, length);
        *ptr = (uint8_t) NEGATIVE_ASCII;
        length++;

    }

    //Add null terminator
    *(ptr + length) = (uint8_t) NULL_ASCII;
    length++;

    return length;
}
    
int32_t my_atoi (uint8_t * ptr, uint8_t digits, uint32_t base) {
    // Don't handle if ptr is not allocated, 
    if (!ptr) 
        return 0;

    // Don't handle if the base is invalid or too big
    if (base < BASE_2 || base > BASE_16)
        return 0;

    // No digits to process
    if (digits < 1)
        return 0;

    uint8_t index = 0; // Index in string
    
    if (digits == 1) // If only one digit just return that one digit
        return (int32_t) (*(ptr+index) - ASCII_DIGIT_OFFSET);
    
    uint8_t negative = 0;

    if (*(ptr+index) == (uint8_t) NEGATIVE_ASCII) { //If first char is negative sign
        negative = 1;
        index++;
    }

    int32_t data = 0;

    while (index < digits - 1) { // Go through string not counting null terminator
        uint8_t digit = *(ptr+index);

        if (digit >= ASCII_ALPHA_OFFSET) { // If digit was letter correctly convert back
            digit -= ASCII_ALPHA_OFFSET;
            digit += 10;
        } else
            digit -= ASCII_DIGIT_OFFSET; // Convert ascii digit back to an integer

        data *= base; 
        data += digit;

        index++;
    }

    if (negative)
        data = -data;

    return data;
}
