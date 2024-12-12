/**
 * File: recv_signal.c
 * Biref: Program to receive a signal with data using sigaction
 * 
 * Modified by: Aidan Conlin
 * Class: CPE 2600 121
 * Compile: gcc -o recv_signal recv_signal.c
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGUSR1 with data.
 * Print the received integer value (from sival_int).
 *
 * @param signum The signal number.
 * @param info Pointer to siginfo_t containing information about the signal.
 * @param context Pointer to ucontext_t (unused here).
 */
void handle_sigusr1(siginfo_t *info) {
    // Print the integer data sent with the signal
    printf("Received SIGUSR1 with data: %d\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;

    // Clear the sigaction structure
    sigemptyset(&sa.sa_mask);

    // Set the signal handler and specify the use of SA_SIGINFO
    sa.sa_sigaction = handle_sigusr1;
    sa.sa_flags = SA_SIGINFO; // Use SA_SIGINFO to enable passing siginfo_t to the handler

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Process PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    // Infinite loop to wait for signals
    while (1) {
        pause(); // Suspend execution until a signal is received
    }

    return 0;
}
