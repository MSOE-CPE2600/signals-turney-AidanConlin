# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Program names
PROGRAMS = recv_signal send_signal signal_alarm signal_handler signal_segfault signal_sigaction

# Build all programs
all: $(PROGRAMS)

# Compile each program
recv_signal: recv_signal.c
	$(CC) $(CFLAGS) -o recv_signal recv_signal.c

send_signal: send_signal.c
	$(CC) $(CFLAGS) -o send_signal send_signal.c

signal_alarm: signal_alarm.c
	$(CC) $(CFLAGS) -o signal_alarm signal_alarm.c

signal_handler: signal_handler.c
	$(CC) $(CFLAGS) -o signal_handler signal_handler.c

signal_segfault: signal_segfault.c
	$(CC) $(CFLAGS) -o signal_segfault signal_segfault.c

signal_sigaction: signal_sigaction.c
	$(CC) $(CFLAGS) -o signal_sigaction signal_sigaction.c

# Clean up build artifacts
clean:
	rm -f $(PROGRAMS)
