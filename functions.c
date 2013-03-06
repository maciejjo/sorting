#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//===== FUNKCJE SORTUJĄCE =====
void sort_selection(int *tablica, int rozmiar) {
	int i, min, y;
	for(i=0; i<rozmiar; i++) {
		min = tablica[i];
		for(y=i;y<rozmiar;y++) {
			if(tablica[y] < min) {
				min = tablica[y];
				tablica[y] = tablica[i];
				tablica[i] = min;
			}
			
		}
	}
	
}

void sort_bubble(int *tablica, int rozmiar) {
	int i, y, max=rozmiar, help;
	for(i=0; i<rozmiar; i++) {
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
int * return_array(int rozmiar) {
	return (int *) malloc(rozmiar*sizeof(int));
}

int *return_array_duplicate(int *tablica, int rozmiar) {
	int *rezultat = (int*)malloc(rozmiar*sizeof(int));
	for(int i = 0; i < rozmiar; i++) {	
		rezultat[i] = tablica[i];
	}
	return rezultat;
}

void populate_array_with_random(int *tablica, int rozmiar, int max_val) {
	srand(time(NULL));
	for(int i = 0; i < rozmiar; i++) {	
		tablica[i] = rand() % max_val;
	}
}



void print_array(int *tablica, int rozmiar) {
	for(int i = 0; i < rozmiar; i++)
	{
		printf("%d ", tablica[i]);
	}
	printf("\n");
}

//===============================
