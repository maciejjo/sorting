CC = gcc
CFLAGS = -Wall -g -std=gnu99

sorting: functions.c functions.h sorting.c
	$(CC) $(CFLAGS) sorting.c functions.c -o sorting
