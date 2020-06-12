CC = gcc
CFLAGS = -Wall -Werror

all:	knapsack_solver

knapsack_solver:	knapsack_solver.c
	$(CC) $(CFLAGS) -o knapsack_solver knapsack_solver.c
