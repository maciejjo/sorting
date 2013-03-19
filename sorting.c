#include <stdlib.h>
#include <math.h>
#include "sorting.h"
#include "main.h"


void sort_bubble(int *tablica) {
	register int i, y, max=array_size, tmp;
	for(i=0; i<array_size; i++) {
		for(y=0; y<max-1; y++) {
			if(tablica[y]>tablica[y+1]) {
				tmp = tablica[y+1];
				tablica[y+1] = tablica[y];
				tablica[y] = tmp;
			}}
		max--;
	}
}

void sort_selection(int *tablica) {
	register int i,j,k,tmp;
	for(i=0; i<array_size; i++) {
		for(j=i,k=i;j<array_size;j++) {
			if(tablica[j] < tablica[k]) {
				k = j;
			}
		}	
		tmp  = tablica[i];
		tablica[i] = tablica[k];
		tablica[k] = tmp;
	}
			
}
	
void sort_insertion(int *tablica) {
    register int tmp;
    for(int i = 0; i < array_size-1; i++) {
        if(tablica[i+1] < tablica[i]){
            for(int y = 0; y < i+1; y++) {
                if(tablica[i+1] < tablica[y]) {
                    tmp = tablica[i+1];
                    tablica[i+1] = tablica[y];
                    tablica[y] = tmp;
                }
            }
        }
    }
}

void sort_shell(int *tablica) {
    int gap = array_size / 2;
    while (gap > 0) {
        for (int i = 0; i < array_size - gap; i++) { //modified insertion sort
            int j = i + gap;
            int tmp = tablica[j];
            while (j >= gap && tmp < tablica[j - gap]) {
                tablica[j] = tablica[j - gap];
                j -= gap;
            }
            tablica[j] = tmp;
        }
        if (gap == 2) { //change the gap size
            gap = 1;
        } else {
            gap /= 2.2;
        }
    }
}

  void sort_heap(int *tablica)
  {
      unsigned int n = array_size, i = n/2, parent, child;
      int t;
  
      while(1) { /* Loops until tablica is sorted */
          if (i > 0) { /* First stage - Sorting the heap */
              i--;           /* Save its index to i */
              t = tablica[i];    /* Save parent value to t */
          } else {     /* Second stage - Extracting elements in-place */
              n--;           /* Make the new heap smaller */
              if (n == 0) return; /* When the heap is empty, we are done */
              t = tablica[n];    /* Save last value (it will be overwritten) */
              tablica[n] = tablica[0]; /* Save largest value at the end of tablica */
          }
  
          parent = i; /* We will start pushing down t from parent */
          child = i*2 + 1; /* parent's left child */
  
          /* Sift operation - pushing the value of t down the heap */
          while (child < n) {
              if (child + 1 < n  &&  tablica[child + 1] > tablica[child]) {
                  child++; /* Choose the largest child */
              }
              if (tablica[child] > t) { /* If any child is bigger than the parent */
                  tablica[parent] = tablica[child]; /* Move the largest child up */
                  parent = child; /* Move parent pointer to this child */
                  //child = parent*2-1; /* Find the next child */
                  child = parent*2+1; /* the previous line is wrong*/
              } else {
                  break; /* t's place is found */
              }
          }
          tablica[parent] = t; /* We save t in the heap */
      }
  }
void sort_quick(int *tablica) {

  #define  MAX_LEVELS  1000

  int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R ;

  beg[0]=0; end[0]=array_size;
  while (i>=0) {
    L=beg[i]; R=end[i]-1;
    if (L<R) {
      piv=tablica[L]; 
      while (L<R) {
        while (tablica[R]>=piv && L<R) R--; if (L<R) tablica[L++]=tablica[R];
        while (tablica[L]<=piv && L<R) L++; if (L<R) tablica[R--]=tablica[L]; }
      tablica[L]=piv; beg[i+1]=L+1; end[i+1]=end[i]; end[i++]=L; }
    else {
      i--; }
 } 
}
