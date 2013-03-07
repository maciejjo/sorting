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

struct dataset_function {
    void (* function) (int *);
    char *name;
};


struct sorting_function* init_sorting(void (*init_function) (int *), char *name_string);
void measure_sort_runtime(struct sorting_function* function_to_measure);

struct dataset_function* init_dataset(void (*init_function) (int *), char *name_string);

#endif
