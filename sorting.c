#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"


int main(int argc, char **argv) {
	
	array_size = 20;
	int display = 1;
	int max_val = 30;

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
			max_val = atoi(optarg);
			break;
		case 'd':
			printf("Not displaying result.\n");
			display = 0;
			break;
		case '?':
		default:
			printf("Usage: %s [-c array_size] [-m max_val] [-d]\n", argv[0]);
			return 1;

		}
	}

	
    
	int *numbers = return_array(array_size);
	populate_array_with_random(numbers, max_val);
	
    int *numbers_bubble = return_array_duplicate(numbers);
	clock_t bubble_start = clock();
	sort_bubble(numbers_bubble);
	clock_t bubble_end = clock();
	
	int *numbers_select = return_array_duplicate(numbers);
	clock_t select_start = clock();
	sort_selection(numbers_select);
	clock_t select_end = clock();

	int *numbers_insert = return_array_duplicate(numbers);
	clock_t insert_start = clock();
	sort_insertion(numbers_insert);
	clock_t insert_end = clock();

	float bubble_time = (float)(bubble_end - bubble_start) / CLOCKS_PER_SEC;
	float select_time = (float)(select_end - select_start) / CLOCKS_PER_SEC;
	float insert_time = (float)(insert_end - insert_start) / CLOCKS_PER_SEC;

	if(display) {
		printf("Unsorted numbers:\t");
		print_array(numbers);
		printf("Bubble sort:\t\t");
		print_array(numbers_bubble);
		printf("Selection sort:\t\t");
		print_array(numbers_select);
		printf("Insertion sort:\t\t");
		print_array(numbers_insert);
	}

	printf("Bubble run time for %d elements in range 1-%d is %.2f.\n", array_size, max_val, bubble_time);
	printf("Select run time for %d elements in range 1-%d is %.2f.\n", array_size, max_val, select_time);
	printf("Insert run time for %d elements in range 1-%d is %.2f.\n", array_size, max_val, insert_time);

	free(numbers);
	free(numbers_bubble);
	free(numbers_select);

	
}
	

