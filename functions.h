#ifndef FUNCTIONS_H
#define FUNCTIONS_H


void sort_selection(int *tablica);
void sort_bubble(int *tablica);
void sort_insertion(int *tablica);


int *return_array();
int *return_array_duplicate(int *tablica);
void populate_array_with_random(int *tablica, int max_val);
void populate_array_with_ascending(int *tablica);
void populate_array_with_descending(int *tablica);
void populate_array_with_constant(int *tablica, int stala);
void populate_array_with_v_shape(int *tablica);

void print_array(int *tablica);

extern int array_size;

#endif


