#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int array_size = 20;

//===== FUNKCJE SORTUJĄCE =====
void sort_selection(int *tablica) {
	int i, min, y;
	for(i=0; i<array_size; i++) {
		min = tablica[i];
		for(y=i;y<array_size;y++) {
			if(tablica[y] < min) {
				min = tablica[y];
				tablica[y] = tablica[i];
				tablica[i] = min;
			}
			
		}
	}
	
}

void sort_bubble(int *tablica) {
	int i, y, max=array_size, help;
	for(i=0; i<array_size; i++) {
		for(y=0; y<max-1; y++) {
			if(tablica[y]>tablica[y+1]) {
				help = tablica[y+1];
				tablica[y+1] = tablica[y];
				tablica[y] = help;
			}
		}
		max--;
	}
}

//============================

//===== OPERACJE NA TABLICACH =====
int * return_array() {
	return (int *) malloc(array_size*sizeof(int));
}

int *return_array_duplicate(int *tablica) {
	int *rezultat = (int*)malloc(array_size*sizeof(int));
	for(int i = 0; i < array_size; i++) {	
		rezultat[i] = tablica[i];
	}
	return rezultat;
}

void populate_array_with_random(int *tablica, int max_val) {
	srand(time(NULL));
	for(int i = 0; i < array_size; i++) {	
		tablica[i] = rand() % max_val;
	}
}

void populate_array_with_ascending(int *tablica) {
    for(int i = 0; i < array_size; i++) {
        tablica[i] = i+1;
    }
}

void populate_array_with_descending(int *tablica) {
    int max_val = array_size;
    for(int i = 0; i < array_size; i++) {
        tablica[i] = max_val--;
    }
}

void populate_array_with_constant(int *tablica, int stala) {
    for(int i = 0; i < array_size; i++) {
        tablica[i] = stala;
    }
}

void populate_array_with_v_shape(int *tablica) {
    int half = array_size - array_size/2;
    for(int i = 0; i < array_size; i++) {
        if(i < array_size - array_size/2) tablica[i] = half--;
        else tablica[i] = half++;
    }
}

void print_array(int *tablica) {
	for(int i = 0; i < array_size; i++)
	{
		printf("%d ", tablica[i]);
	}
	printf("\n");
}

//===============================
