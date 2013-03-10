#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "parameters.h"
#include "main.h"

void set_parameters(int argc, char **argv) {
	while(1) {
		char c = getopt(argc, argv, "c:m:do:t:s:");
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
        case 'o':
            printf("Writing output to file %s\n", optarg);
            write_to_file = 1;
            filename = optarg;
            break;
        case 't':
            printf("Performing %s tests.\n", optarg);
            number_of_tests = atoi(optarg);
            break;
        case 's':
            printf("Setting step to %s.\n", optarg);
            test_step = atoi(optarg);
		case '?':
		default:
			printf("Usage: %s [-c array_size] [-m max_val] [-o filename] [-d] \n", argv[0]);

		}
	}
}

