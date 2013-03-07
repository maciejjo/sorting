#include <stdlib.h>
#include "sorting.h"
#include "main.h"


void sort_bubble(int *tablica) {
	int i, y, max=array_size, help;
	for(i=0; i<array_size; i++) {
		for(y=0; y<max-1; y++) {
			if(tablica[y]>tablica[y+1]) {
				help = tablica[y+1];
				tablica[y+1] = tablica[y];
				tablica[y] = help;
			}}
		max--;
	}
}

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

void sort_insertion(int *tablica) {
    int sorted = 1, helper = 0;
    for(int i = 0; i < array_size-1; i++) {
        if(tablica[sorted] < tablica[sorted-1]){
            for(int y = 0; y < sorted; y++) {
                if(tablica[sorted] < tablica[y]) {
                    helper = tablica[sorted];
                    tablica[sorted] = tablica[y];
                    tablica[y] = helper;
                }
            }
        }
        sorted++;
    }
}

