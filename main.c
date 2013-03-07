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

	int *numbers = return_array(array_size);
	populate_array_with_random(numbers, rand_max_val);

    struct sorting_function *sorting_array[] = {
        init(sort_bubble, "Bubble sort"),
        init(sort_selection, "Selection sort"),
        init(sort_insertion, "Insertion sort")
        };

    int sorting_array_size = sizeof(sorting_array)/sizeof(sorting_array[0]);

    for(int i =0; i<sorting_array_size; i++) {
        sorting_array[i]->numbers = return_array_duplicate(numbers);
        printf("\n---->%s\n", sorting_array[i]->name);
        measure_sort_runtime(sorting_array[i]);
        if(display) {
            printf("Elements: ");
		    print_array(sorting_array[i]->numbers);
            printf("\n");
        }
        printf("Running time: %.2f\n", sorting_array[i]->runtime);
        
    }
    
    for(int i =0; i<sorting_array_size; i++) {
        free(sorting_array[i]);
    }

    free(numbers);
	
}
	

