#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "sorting.h"
#include "main.h"
#define MID(lo, hi) (lo + ((hi - lo) >> 1))
#define SWAP(a, b) tmp = tablica[a], tablica[a] = tablica[b], tablica[b] = tmp

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

void sort_quick_recursive_random_start(int *tablica) {
	sort_quick_recursive_random(tablica, 0, array_size - 1);
}

/*void sort_quick_recursive ( int a[ ], int lower, int upper )
{
	int i ;
	if ( upper > lower )
	{
		i = split ( a, lower, upper ) ;
		sort_quick_recursive ( a, lower, i - 1 ) ;
		sort_quick_recursive ( a, i + 1, upper ) ;
	}
}

int split ( int a[ ], int lower, int upper )
{
	int i, p, q, t ;

	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;

	while ( q >= p )
	{
		while ( a[p] < i )
			p++ ;

		while ( a[q] > i )
			q-- ;

		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}

	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}

void sort_quick_recursive(int a[], int lo, int hi) 
{
  int h, l, p, t;

  if (lo < hi) {
    l = lo;
    h = hi;
    srand(time(NULL));          
    p = a[rand() % (hi-lo)+lo];
//    p = a[hi];

    do {
      while ((l < h) && (a[l] <= p)) 
          l = l+1;
      while ((h > l) && (a[h] >= p))
          h = h-1;
      if (l < h) {
          t = a[l];
          a[l] = a[h];
          a[h] = t;
      }
    } while (l < h);

    a[hi] = a[l];
    a[l] = p;

    sort_quick_recursive( a, lo, l-1 );
    sort_quick_recursive( a, l+1, hi );
  }
}*/

int random_partition(int* arr, int start, int end)
{
    srand(time(NULL));
    int t;

    int pivotIdx = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx];
    
    t = arr[pivotIdx];
    arr[pivotIdx] = arr[end];
    arr[end] = t;
    pivotIdx = end;
    int i = start -1;
 
    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
	    t = arr[i];
	    arr[i] = arr[j];
	    arr[j] = t;
        }
    }
 
    t = arr[i+1];
    arr[i+1] = arr[pivotIdx];
    arr[pivotIdx] = t;
    return i+1;
}
 
void sort_quick_recursive_random(int* arr, int start, int end)
{
    if(start < end) {
        int mid = random_partition(arr, start, end);
        sort_quick_recursive_random(arr, start, mid-1);
        sort_quick_recursive_random(arr, mid+1, end);
    }
}


void sort_quick_recursive_rightmost_start(int *tablica) {
	sort_quick_recursive_rightmost(tablica, -1, array_size - 1);
}

int rightmost_partition(int* arr, int start, int end)
{
    srand(time(NULL));
    int t;

    int pivotIdx = end;
    int pivot = arr[pivotIdx];
    
    t = arr[pivotIdx];
    arr[pivotIdx] = arr[end];
    arr[end] = t;
    pivotIdx = end;
    int i = start -1;
 
    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
	    t = arr[i];
	    arr[i] = arr[j];
	    arr[j] = t;
        }
    }
 
    t = arr[i+1];
    arr[i+1] = arr[pivotIdx];
    arr[pivotIdx] = t;
    return i+1;
}


void sort_quick_recursive_rightmost(int* arr, int start, int end)
{
    if(start < end) {
        int mid = rightmost_partition(arr, start, end);
        sort_quick_recursive_rightmost(arr, start, mid-1);
        sort_quick_recursive_rightmost(arr, mid+1, end);
    }
}


typedef struct qstack {
    size_t lo, hi;
} qstack_t;

void sort_quick_iterative_rightmost(int *tablica)
{
    size_t n = (size_t) array_size;
    qstack_t stack[32], *sp;
    register size_t i, k;
    register int pivot;
    size_t lo, hi;
    int tmp;
    
    /* initialize our stack */
    sp = stack;
    sp->hi = n - 1;
    sp->lo = 0;
    sp++;
    
    do {
        /* pop our lo and hi indexes off the stack */
        sp--;
        lo = sp->lo;
        hi = sp->hi;
        
        if ((hi - lo) < 1)
            continue;
        
        /* cache our pivot value */
        pivot = tablica[array_size-1];
        
        i = lo;
        k = hi;
        
        do {
            /* find the first element with a value >= pivot value */
            while (i < k && tablica[i] < pivot)
                i++;
            
            /* find the last element with a value <= pivot value */
            while (k > i && tablica[k] > pivot)
                k--;
            
            if (i <= k) {
                SWAP (i, k);
                i++;
                k--;
            } else {
                break;
            }
        } while (1);
        
        if (lo < k) {
            /* push the first partition onto our stack */
            sp->lo = lo;
            sp->hi = k;
            sp++;
        }
        
        if (i < hi) {
            /* push the second partition onto our stack */
            sp->lo = i;
            sp->hi = hi;
            sp++;
        }
    } while (sp > stack);
}
