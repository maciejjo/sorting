#ifndef ARRAYS_H
#define ARRAYS_H

int *return_array();
int *return_array_duplicate(int *tablica);
void populate_array_with_random(int *tablica, int max_val);
void populate_array_with_ascending(int *tablica);
void populate_array_with_descending(int *tablica);
void populate_array_with_constant(int *tablica, int stala);
void populate_array_with_v_shape(int *tablica);

void print_array(int *tablica);

#endif


