#ifndef STRUCT_H
#define STRUCT_H
#include <time.h>

struct sorting_function {
    clock_t start, stop;
    void (* function) (int *);
};

struct sorting_function* init(void (*init_function) (int *));

#endif
