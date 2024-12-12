/**
 * File: signal_alarm.c
 * Brief summary of program: 
 * - Sets an alarm for a pre-defined amount of time. 
 * - Sends a signal and stops the program when time runs out.
 *
 * Modified by: Aidan Conlin
 * Class: CPE 2600 121
 * Compile: gcc -o signal_alarm signal_alarm.c
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGALRM
 */
void handle_alarm() {
    printf("Received signal! Time is up!\n");
    exit(1);
}

int main() {
    // Register the signal handler for SIGALRM
    signal(SIGALRM, handle_alarm);

    // Schedule an alarm to go off after a specified amount of seconds
    int timer = 5;
    printf("Scheduling an alarm for %d seconds...\n", timer);
    alarm(timer);

    // Pause the program to wait for the signal
    while (1) {
        printf("Waiting for signal...\n");
        sleep(1);
    }

    return 0;
}
