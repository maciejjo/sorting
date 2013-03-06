CC = gcc
CFLAGS = -Wall -g -std=gnu99

sorting: sorting.c sorting.h arrays.c arrays.h parameters.c parameters.h main.c
	$(CC) $(CFLAGS) main.c parameters.c sorting.c arrays.c -o sorting
