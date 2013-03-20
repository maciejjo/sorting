#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "sorting.h"
#include "parameters.h"
#include "arrays.h"
#include "main.h"
#include "struct.h"


int array_size = 20;
int display = 1;
int rand_max_val = 0;
int number_of_tests = 1;
int test_step = 0;
char *filename = "";
int write_to_file = 0;

int main(int argc, char **argv) {

    set_parameters(argc, argv);


    struct dataset_function *dataset_array[] = {
        init_dataset(populate_array_with_random, "Random"),
//        init_dataset(populate_array_with_ascending, "Ascending"),
        init_dataset(populate_array_with_ascending, "Descending"),
        init_dataset(populate_array_with_constant, "Constant"),
        init_dataset(populate_array_with_v_shape, "V-shaped")
   };

    struct sorting_function *sorting_array[] = {
//        init_sorting(sort_bubble, "Bubble sort"),
//        init_sorting(sort_selection, "Selection sort"),
//        init_sorting(sort_insertion, "Insertion sort"),
//        init_sorting(sort_shell, "Shell sort"),
//	init_sorting(sort_heap, "Heap sort"),
	init_sorting(sort_quick_recursive_random_start, "Qsort recursive random"),
	init_sorting(sort_quick_recursive_rightmost_start, "Qsort recursive right"),
//	init_sorting(sort_quick_iterative_rightmost, "Qsort iterative right"),
//	init_sorting(sort_quick_iterative_random, "Qsort iterative random")
     };

    int sorting_array_size = sizeof(sorting_array)/sizeof(sorting_array[0]);
    int dataset_array_size = sizeof(dataset_array)/sizeof(dataset_array[0]);
    
    FILE *output_file = NULL;
    int file_opened = 0;
    if(write_to_file) {
        if(strcmp(filename, "") != 0) {
            output_file = fopen(filename, "w");
            file_opened = 1;
        }
    }
    
for(int k = 0; k<number_of_tests; k++) {
	int *numbers = return_array();
    for(int j = 0; j<dataset_array_size; j++) {
        printf("|------------current dataset: %s\n", dataset_array[j]->name);
        dataset_array[j]->function(numbers);
        for(int i =0; i<sorting_array_size; i++) {
            sorting_array[i]->numbers = return_array_duplicate(numbers);
            printf("|--%s ", sorting_array[i]->name);
            measure_sort_runtime(sorting_array[i]);
            printf("Running time: %.2f\n", sorting_array[i]->runtime);
            if(write_to_file) {
                fprintf(output_file, "%s,%s,%d,%.2f\n", dataset_array[j]->name,
                sorting_array[i]->name, array_size, sorting_array[i]->runtime);
            } 
            if(display) {
                printf("|-- Elements: ");
                print_array(sorting_array[i]->numbers);
                printf("\n");
            }
            free(sorting_array[i]->numbers);
            
        }
    }
    array_size += test_step;
    free(numbers);
}
    if(file_opened) fclose(output_file);
}
	

