#ifndef SORTING_H
#define SORTING_H
#include <time.h>

void swap (int *first, int *second);
void sort_selection(int *tablica);
void sort_bubble(int *tablica);
void sort_insertion(int *tablica);
void sort_shell(int *tablica);
void heapify(int arr[], int item, int size);
void sort_heap(int *tablica);
void sort_quick_rightmost_recursive_wrapper(int *tablica);
void sort_quick_rightmost_recursive(int *tab, int first,int last);
void sort_quick_random_recursive_wrapper(int *tablica);
void sort_quick_random_recursive(int *tab, int first,int last);

void sort_quick_random_iterative_wrapper(int *tablica);
int random_partition (int arr[], int l, int h);
void sort_quick_random_iterative(int arr[], int l, int h);

void sort_quick_rightmost_iterative_wrapper(int *tablica);
int rightmost_partition (int arr[], int l, int h);
void sort_quick_rightmost_iterative(int arr[], int l, int h);
#endif

