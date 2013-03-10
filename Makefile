CC = gcc
CFLAGS = -Wall -g -o3 -std=gnu99

sorting: sorting.c sorting.h arrays.c arrays.h parameters.c parameters.h struct.c struct.h main.c
	$(CC) $(CFLAGS) main.c parameters.c sorting.c arrays.c struct.c -o sorting
