#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "pokaz_wynik.h"
#include "dzialania.h"
/*
float **tablica;
int i;
tablica = (float*) malloc(sizeof(float*) * 25);
for (i=0;i<25;i++)
    tablica[i] = (float) malloc(sizeof(float) * 25);
*/
struct macierz wczytaj(FILE * fin){

    int i,j;
    struct macierz *m; 
    m = (struct macierz*) malloc(sizeof(struct macierz));

    fscanf(fin, "%d", &m->w);
    printf("%d",m->w);
    fscanf(fin, "%d", &m->k);
      printf("%d",m->k);
    
    m->tab = (float**) malloc(sizeof(float*) * m->w);
    for (i=0;i<m->w;i++) {
        m->tab[i] = (float*) malloc(sizeof(float) * m->k);
        for (j=0;j< m->k; j++)
            fscanf(fin, "%f", &m->tab[i][j]);
}
return *m;
}


void zwolnij(struct macierz *m)
{
    for (int i=0;i<m->w;i++) 
    free(m->tab[i]);
    free(m->tab);
    free(m);
}
