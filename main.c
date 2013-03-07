#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "sorting.h"
#include "parameters.h"
#include "arrays.h"
#include "main.h"
#include "struct.h"


int array_size = 20;
int display = 1;
int rand_max_val = 30;

int main(int argc, char **argv) {


    set_parameters(argc, argv);
    	
    struct sorting_function *bubble = init(sort_bubble);

	int *numbers = return_array(array_size);
	populate_array_with_random(numbers, rand_max_val);
	
    int *numbers_bubble = return_array_duplicate(numbers);
	clock_t bubble_start = clock();
	//sort_bubble(numbers_bubble);
    bubble->function(numbers_bubble);
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

	printf("Bubble run time for %d elements in range 1-%d is %.2f.\n", array_size, rand_max_val, bubble_time);
	printf("Select run time for %d elements in range 1-%d is %.2f.\n", array_size, rand_max_val, select_time);
	printf("Insert run time for %d elements in range 1-%d is %.2f.\n", array_size, rand_max_val, insert_time);

	free(numbers);
	free(numbers_bubble);
	free(numbers_select);

	
}
	

