#include <stdlib.h>
#include "struct.h"


struct sorting_function* init(void (*init_function) (int *)) {
    struct sorting_function *some_sort = (struct sorting_function *)malloc(sizeof(struct sorting_function));
    some_sort->function = init_function;
    return some_sort;
}


