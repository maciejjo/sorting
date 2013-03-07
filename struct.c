#include <stdlib.h>
#include "struct.h"


struct sorting_function* init(void (*init_function) (int *), char *name_string) {
    struct sorting_function *some_sort = (struct sorting_function *)malloc(sizeof(struct sorting_function));
    some_sort->function = init_function;
    some_sort->name = name_string;
    return some_sort;
}

void measure_sort_runtime(struct sorting_function* function_to_measure) {
    function_to_measure->start = clock();
    function_to_measure->function(function_to_measure->numbers);
    function_to_measure->stop = clock();
    function_to_measure->runtime = (float)(function_to_measure->stop -
    function_to_measure-> start) / CLOCKS_PER_SEC;
}
