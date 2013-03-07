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

    struct dataset_function *dataset_array[] = {
        init_dataset(populate_array_with_random, "Random"),
        init_dataset(populate_array_with_ascending, "Ascending"),
        init_dataset(populate_array_with_ascending, "Descending"),
        init_dataset(populate_array_with_constant, "Constant"),
        init_dataset(populate_array_with_v_shape, "V-shaped")
    };

    struct sorting_function *sorting_array[] = {
        init_sorting(sort_bubble, "Bubble sort"),
        init_sorting(sort_selection, "Selection sort"),
        init_sorting(sort_insertion, "Insertion sort"),
        init_sorting(sort_shell, "Shell sort")
     };

    int sorting_array_size = sizeof(sorting_array)/sizeof(sorting_array[0]);
    int dataset_array_size = sizeof(dataset_array)/sizeof(dataset_array[0]);

for(int y = 0; y<dataset_array_size; y++) {
    printf("======>current dataset: %s\n", dataset_array[y]->name);
    dataset_array[y]->function(numbers);

    for(int i =0; i<sorting_array_size; i++) {
        sorting_array[i]->numbers = return_array_duplicate(numbers);
        printf("\n\t====>%s\n", sorting_array[i]->name);
        measure_sort_runtime(sorting_array[i]);
        if(display) {
            printf("\tElements: ");
		    print_array(sorting_array[i]->numbers);
            printf("\n");
        }
        printf("\tRunning time: %.2f\n", sorting_array[i]->runtime);
        
    }
}
    
    for(int i =0; i<sorting_array_size; i++) {
        free(sorting_array[i]);
    }

    free(numbers);
	
}
	

