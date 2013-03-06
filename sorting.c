#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"

int main(int argc, char **argv) {
	
	int count = 20;
	int display = 1;
	int max_val = 30;

	while(1) {
		char c = getopt(argc, argv, "c:m:d");
		if(c == -1) break;
		switch(c) {
		case 'c':
			printf("Generating %s elements.\n", optarg);
			count = atoi(optarg);
			break;
		case 'm': 
			printf("Setting max value to %s.\n", optarg);
			max_val = atoi(optarg);
			break;
		case 'd':
			printf("Not displaying result.\n");
			display = 0;
			break;
		case '?':
		default:
			printf("Usage: %s [-c count] [-m max_val] [-d]\n", argv[0]);
			return 1;

		}
	}

	

	int *numbers = return_array(count);
	populate_array_with_random(numbers, count, max_val);

	int *numbers_bubble = return_array_duplicate(numbers, count);
	clock_t bubble_start = clock();
	sort_bubble(numbers_bubble, count);
	clock_t bubble_end = clock();
	
	int *numbers_select = return_array_duplicate(numbers, count);
	clock_t select_start = clock();
	sort_selection(numbers_select, count);
	clock_t select_end = clock();


	float bubble_time = (float)(bubble_end - bubble_start) / CLOCKS_PER_SEC;
	float select_time = (float)(select_end - select_start) / CLOCKS_PER_SEC;

	if(display) {
		printf("Unsorted numbers:\t");
		print_array(numbers, count);
		printf("Selection sort:\t\t");
		print_array(numbers_bubble, count);
		printf("Bubble sort:\t\t");
		print_array(numbers_select, count);
	}

	printf("Bubble run time for %d elements in range 1-%d is %.2f.\n", count, max_val, bubble_time);
	printf("Select run time for %d elements in range 1-%d is %.2f.\n", count, max_val, select_time);

	free(numbers);
	free(numbers_bubble);
	free(numbers_select);

	
}
	

