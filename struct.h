#ifndef STRUCT_H
#define STRUCT_H
#include <time.h>

struct sorting_function {
    void (* function) (int *);
    int *numbers;
    char *name;
    clock_t start, stop;
    float runtime;
};

struct sorting_function* init(void (*init_function) (int *), char *name_string);
void measure_sort_runtime(struct sorting_function* function_to_measure);

#endif
