/**
 * @file main.c
 * @brief Main entry point to the Course assignments
 *
 * @author gabman15
 * @date 03/13/24
 *
 */
#include "platform.h"
#include "memory.h"
#include "course1.h"

int main() {
    
#ifdef COURSE1
    course1();
#endif
    
    return 0;
}

