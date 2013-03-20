#ifndef SORTING_H
#define SORTING_H
#include <time.h>

void sort_selection(int *tablica);
void sort_bubble(int *tablica);
void sort_insertion(int *tablica);
void sort_shell(int *tablica);
void sort_heap(int *tablica);
void sort_quick_recursive_random_start(int *tablica);
int random_partition(int* arr, int start, int end);
void sort_quick_recursive_random(int* arr, int start, int end);
void sort_quick_recursive_rightmost_start(int *tablica);
int rightmost_partition(int* arr, int start, int end);
void sort_quick_recursive_rightmost(int* arr, int start, int end);
void sort_quick_iterative_rightmost(int *tablica);
extern int rand_max_val;

#endif

