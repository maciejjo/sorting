#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *plik = fopen("test.txt", "w");
    fprintf(plik, "Witą pąstwą");
    fclose(plik);
}


