/**
 * File: send_signal.c
 * Brief: Program to send a signal with data using sigqueue
 * 
 * Modified by: Aidan Conlin
 * Class: CPE 2600 121
 * Compile: gcc -o send_signal send_signal.c
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = atoi(argv[1]); // Convert command-line argument to PID

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer
    int random_value = rand() % 100; // Random number between 0 and 99
    printf("Sending SIGUSR1 with data: %d to process %d\n", random_value, pid);

    // Send the signal with the random value using sigqueue
    union sigval value;
    value.sival_int = random_value;
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        exit(EXIT_FAILURE);
    }

    return 0;
}
