/**
 * File: signal_sigaction.c
 * Brief summary of program:
 * - Uses sigaction to register a signal handler for SIGUSR1.
 * - The handler retrieves and prints the process ID of the sender.
 *
 * Modified by: Aidan Conlin
 * Class: CPE 2600 121
 * Compile: gcc -o signal_sigaction signal_sigaction.c
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGUSR1 using sigaction.
 * Print the signal number and the sender's process ID
 *
 * @param info Pointer to siginfo_t, containing information about the signal.
 */
void handle_sigusr1(siginfo_t *info) {
    printf("Received SIGUSR1 from process ID: %d\n", info->si_pid);
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
