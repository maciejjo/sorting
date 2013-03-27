#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "sorting.h"
#include "main.h"

void swap (int *first, int *second) {
	register int tmp = *first;
	*first = *second;
	*second = tmp;
}

void sort_bubble(int *tablica) {
	register int i, y, max=array_size;
	for(i=0; i<array_size; i++) {
		for(y=0; y<max-1; y++) {
			if(tablica[y]>tablica[y+1]) {
				swap(&tablica[y+1], &tablica[y]);
			}}
		max--;
	}
}

void sort_selection(int *tablica) {
	register int i,j,k;
	for(i=0; i<array_size; i++) {
		for(j=i,k=i;j<array_size;j++) {
			if(tablica[j] < tablica[k]) {
				k = j;
			}
		}	
		swap(&tablica[i], &tablica[k]);
	}
			
}

void sort_insertion(int *tablica)  
   {  
    register int i,j,x,n=array_size;  
           for(i=1;i<=n-1;i++)  
                {  
                       j=i;  
                       x=tablica[i];  
                       while(tablica[j-1]>x && j>0)  
                                 {  
                                   tablica[j]=tablica[j-1];  
                                    j=j-1;  
                                 }  
                        tablica[j]=x;  
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

#define LEFT(i) ((i) * 2 + 1)
#define RIGHT(i) ((i) * 2 + 2)

void heapify(int arr[], int item, int size) {
  int min = item;
  if (LEFT(item) < size && arr[LEFT(item)] < arr[min]) min = LEFT(item);
  if (RIGHT(item) < size && arr[RIGHT(item)] < arr[min]) min = RIGHT(item);
  if (item != min) {
    swap(arr + item, arr + min);
    heapify(arr, min, size);
  }
}

void sort_heap(int *tablica) {
  for (int i = array_size / 2; i >= 0; i--)
    heapify(tablica, i, array_size);

  for (int i = array_size - 1; i >= 0; i--) {
    swap(tablica, tablica + i);
    heapify(tablica, 0, i - 1);
  }
}

void sort_quick_rightmost_recursive_wrapper(int *tablica){
	sort_quick_rightmost_recursive(tablica, 0, array_size-1);
}

void sort_quick_rightmost_recursive(int *tab, int first,int last)
{
    int i=first;
    int j=last;
    //int key=tab[rand()%(last-first)+first];
    int key=tab[last-1];
    while(i<=j)
     {
         while(tab[i]<key)
            i++;
         while(key<tab[j])
         while(key<tab[j])
            j--;
         if(i<j)
         {
            swap(&tab[i],&tab[j]);
             i++;
             j--;
         }

         else i++;
     }
     if(first<j) sort_quick_rightmost_recursive(tab,first,j);
     if(j+1<last) sort_quick_rightmost_recursive(tab,j+1,last);
}

void sort_quick_random_recursive_wrapper(int *tablica){
	sort_quick_random_recursive(tablica, 0, array_size-1);
}

void sort_quick_random_recursive(int *tab, int first,int last)
{
    int i=first;
    int j=last;
    int key=tab[rand()%(last-first)+first];
    //int key=tab[last-1];
    while(i<=j)
     {
         while(tab[i]<key)
            i++;
         while(key<tab[j])
         while(key<tab[j])
            j--;
         if(i<j)
         {
            swap(&tab[i],&tab[j]);
             i++;
             j--;
         }

         else i++;
     }
     if(first<j) sort_quick_random_recursive(tab,first,j);
     if(j+1<last) sort_quick_random_recursive(tab,j+1,last);
}

void sort_quick_random_iterative_wrapper(int *tablica) {
	sort_quick_random_iterative(tablica, 0, array_size-1);
}

int random_partition (int arr[], int l, int h)
{
    int x = arr[rand()%(h-l)+l];//klucz
    int i = (l - 1);
    int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void sort_quick_random_iterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position in sorted array
        int p = random_partition( arr, l, h );

        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}                                                                                        


void sort_quick_rightmost_iterative_wrapper(int *tablica) {
	sort_quick_rightmost_iterative(tablica, 0, array_size-1);
}

int rightmost_partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void sort_quick_rightmost_iterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];
    // initialize top of stack
    int top = -1;
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
        // Set pivot element at its correct position in sorted array
        int p = random_partition( arr, l, h );
        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}
