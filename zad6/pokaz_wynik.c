#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "pokaz_wynik.h"
#include "dzialania.h"

void wypisz(struct macierz *m) 
{
{
printf("To jest wynik\n[");
for(int i = 0; i < m->w; i++)
    {
        for(int j = 0; j < m->k; j++)
        {
            printf("%.2f\t", m->tab[i][j]); //żeby było ładnie przejrzyście i czytelnie to dałem dwie po przecinku 
            if(j+1 == m->k)
            printf("\b\b]\n");
        } 
    if(i+1 != m->w)   
    printf("[");
    }
}

}
void zapisz(FILE * fin,struct macierz *m)
{
fprintf(fin,"%d\n%d\n",m->w,m->k);
for(int i = 0; i < m->w; i++)
        for(int j = 0; j <m->k; j++)
        {
            fprintf(fin,"%.2f\t",m->tab[i][j]);
            if(j+1 == m->k)
            fprintf(fin,"\n");
        }  
}