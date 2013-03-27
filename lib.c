#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "lib.h"


double insert_sort(int tab[],int size)
{
     register int i,j;
     int tmp;
     start = clock();
     for(i=1;i<size;i++)
        {
            tmp=tab[i];
            j=i;
            while(j>0 && tmp<tab[j-1])
            {
                tab[j]=tab[j-1];
                j--;
            }
            tab[j]=tmp;
        }
      stop = clock();
      sort_time =(double)( stop - start ) / CLOCKS_PER_SEC;
      return sort_time;
}

 double shell_sort(int tab[], int size)
 {
     register int i,j,tmp,h_cnt,h;
     int increments[20],k;
      start = clock();
     for(h=1,i=0;h<size;i++)
     {
         increments[i]=h;
         h=3*h+1;
     }
     for(i--;i>=0;i--)
      {
          h=increments[i];
          for(h_cnt=h;h_cnt<2*h;h_cnt++)
          {
              for(j=h_cnt;j<size;)
              {
                  tmp=tab[j];
                  k=j;
                  while(k-h>=0 && tmp<tab[k-h])
                  {
                      tab[k]=tab[k-h];
                      k-=h;
                  }
                  tab[k]=tmp;
                  j+=h;
              }
          }
      }
      stop = clock();
      sort_time =(double)( stop - start ) / CLOCKS_PER_SEC;
      return sort_time;
 }
double selection_sort(int tab[],int size)
{
    register int i,j,least;
     start = clock();
    for(i=0;i<size-1;i++)
        {
            for(j=i+1,least=i;j<size;j++)
                if(tab[j]<tab[least])
                    least=j;
                if(i!=least);
                swap(tab+least,tab+i);
        }
    stop = clock();
    sort_time =(double)( stop - start ) / CLOCKS_PER_SEC;
    return sort_time;
}

double heap_sort(int tab[],int size)
{
    register int i;
     start = clock();
    for(i=size/2-1;i>=0;--i)
        move_down(tab,i,size-1);
    for(i=size-1;i>1;--i)
    {
        swap(tab,tab+i);
        move_down(tab,0,i-1);
    }
    if(tab[0]>tab[i])
      swap(tab,tab+1);

    stop = clock();
    sort_time =(double)( stop - start ) / CLOCKS_PER_SEC;
    return sort_time;
}


void swap(int *tab_l,int *tab_i)
{
   int tmp=*tab_l;
   *tab_l=*tab_i;
   *tab_i=tmp;
}


void move_down(int tab[],int first,int last)
{
    int largest=2*first+1;
    while(largest<=last)
    {
        if(largest<last && tab[largest]<tab[largest+1])
            largest++;
        if(tab[first]<tab[largest])
        {
            swap(tab+first,tab+largest);
            first=largest;
            largest=2*first+1;
        }else largest=last+1;
    }
}
void quick_sort(int *tab, int first,int last)
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
     if(first<j) quick_sort(tab,first,j);
     if(j+1<last) quick_sort(tab,j+1,last);
}

void print_tab(float (*time_table)[TYP],int n,int m)
{
    for(j=0;j<n;j++)
        for(i=0;i<m;i++)
        {
            printf("%.4lf  ",*(*(time_table+j)+i));
            if(!((i+1)%5)) putchar('\n');
        }
}

void save_to_file(float (*time_table)[TYP],int n,int m,char *name)
{

    if ((fp=fopen( name, "w"))==NULL) {
     printf ("Nie mogê otworzyæ pliku %s do zapisu!\n",name);
     exit(1);
     }
     for(j=0;j<n;j++)
        for(i=0;i<m;i++)
        {
            fprintf(fp, "%7.4lf ",*(*(time_table+j)+i));
            if(!((i+1)%5)) fprintf(fp,"\n");
        }
      fclose (fp); /* zamknij plik */
}
 void generator(int tab[],int rozmiar,int type)
 {
    int i,j;
     switch(type)
     {
         case 1: // rosn¹co
         for(i=0;i<rozmiar;i++)
            tab[i]=i;
         break;
         case 2://malejaco
          for(i=0;i<rozmiar;i++)
            tab[i]=rozmiar-i;
         break;
         case 3: //stale
            for(i=0;i<rozmiar;i++)
                tab[i]=1;
         break;
         case 4://losowo
          for(i=0;i<rozmiar;i++)
            tab[i]= rand()%n;
         break;
         case 5:// V-kszta³tnie
            for(i=0;i<rozmiar/2;i++)
                tab[i]=2*(rozmiar-i);
            for(i=rozmiar/2;i<rozmiar;i++)
               tab[i]=2*i+1;
         break;
         default:printf("nie ma \n");// jakis kod
         break;
     }
     return;
 }
  void sort(double(*F)(int*,int))
  {

     int *tab;
     float time_table[POMIAR][TYP];
     for(j=1;j<=POMIAR;j++)
                 {
                   n=j*ROZMIAR;
                   tab=(int*)malloc(n*sizeof(*tab));
                   for(i=1;i<=TYP;i++)
                        {
                            generator(tab,n,i);
                            time_table[j-1][i-1]=sort_function(tab,n);
                        }
                       free(tab);
                 }

     print_tab(time_table,POMIAR,TYP);
     save_to_file(time_table,POMIAR,TYP,save);
  }
   void sort_qs(void(*F)(int*,int,int))
  {

     int *tab;
     float time_table[POMIAR][TYP];
     for(j=1;j<=POMIAR;j++)
                 {
                   n=j*ROZMIAR;
                   tab=(int*)malloc(n*sizeof(*tab));
                   for(i=1;i<=TYP;i++)
                        {
                            generator(tab,t,i);
                            start=clock();
                            sort_function_qs(tab,0,n-1);
                            stop=clock();
                            time_table[j-1][i-1]=sort_time =(double)( stop - start ) / CLOCKS_PER_SEC;
                        }
                       free(tab);
                 }

     print_tab(time_table,POMIAR,TYP);
     save_to_file(time_table,POMIAR,TYP,save);
  }
int partition (int tab[], int first, int last)
{
    int key = tab[rand()%(last-first)+first];
    //int key=tab[last];
    int i = (first - 1);
    int j;
    for (j = first; j <= last- 1; j++)
    {
        if (tab[j] <= key)
        {
            i++;
            swap (&tab[i], &tab[j]);
        }
    }
    swap (&tab[i + 1], &tab[last]);
    return (i + 1);
}


void quick_sort_i (int tab[], int first, int last)
{
    // Tworzenie stack
    int stack[ last - first + 1 ];

    // zainicjowanie początku
    int top = -1;

    // włożenie elementów krancowych na stack
    stack[ ++top ] = first;
    stack[ ++top ] = last;


    while ( top >= 0 )
    {
      // sciaganie
        last = stack[ top-- ];
        first = stack[ top-- ];

        // Set pivot element at its correct position in sorted array
        int p = partition( tab, first, last );

        if ( p-1 > first )
        {
            stack[ ++top ] = first;
            stack[ ++top ] = p - 1;
        }


        if ( p+1 < last )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = last;
        }
    }
}
