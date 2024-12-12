/**
 * File: signal_segfault.c
 * Brief summary of modifications:
 * - Added a signal handler for SIGSEGV to print a custom message.
 * - The handler does not exit and returns to the program, causing repeated faults.
 *
 * Modified by: Aidan Conlin
 * Class: CPE 2600 121
 * Compile: gcc -o signal_segfault signal_segfault.c
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGSEGV, exits after encountering segmentation fault.
 */
void handle_segfault() {
    printf("Caught Segmentation Fault.\n");
}

int main() {
    // Register the signal handler for SIGSEGV
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer, causing a segmentation fault
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
