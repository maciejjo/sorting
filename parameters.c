#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"
#include "main.h"

void set_parameters(int argc, char **argv) {
	while(1) {
		char c = getopt(argc, argv, "c:m:d");
		if(c == -1) break;
		switch(c) {
		case 'c':
			printf("Generating %s elements.\n", optarg);
			array_size = atoi(optarg);
			break;
		case 'm': 
			printf("Setting max value to %s.\n", optarg);
			rand_max_val = atoi(optarg);
			break;
		case 'd':
			printf("Not displaying result.\n");
			display = 0;
			break;
		case '?':
		default:
			printf("Usage: %s [-c array_size] [-m max_val] [-d]\n", argv[0]);

		}
	}
}

