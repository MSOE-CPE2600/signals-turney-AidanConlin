/**
 * File: signal_handler.c
 * Brief summary of modifications:
 * - Removed the exit call from the signal handler.
 * - Added a flag to act as the exit from the main loop.
 * - Added logic in the main loop to check the flag and exit.
 *
 * Modified by: Aidan Conlin
 * Class: CPE 2600 121
 * Compile: gcc -o signal_handler signal_handler.c
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Global flag to control program termination
volatile sig_atomic_t exit_flag = 0;

/**
 * @brief Signal handler for SIGINT - prints a message and sets a flag.
 */
void handle_signal() {
    printf("\nSignal obtained from user!\n");
    exit_flag = 1;
}

int main() {
    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while (!exit_flag) {
        printf("Sleeping...\n");
        sleep(1);
    }

    printf("Exiting gracefully.\n");
    return 0;
}
