#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "pokaz_wynik.h"
#include "dzialania.h"

void suma(struct macierz *A, struct macierz *B, struct macierz *W)
{
if((A->w != B->w)||(A->k!=B->k))
{
printf("Tych macierzy nie da się dodać.\n");
exit(0);
}
else
{
W->w = A->w;
W->k = A->k;
printf("%d",W->w);
printf("%d",W->k);
for(int i=0; i < W->k; i++)
    for(int j=0; j < W->w; j++)
    W->tab[i][j] = A->tab[i][j] + B->tab[i][j];
}
}
void subtract(struct macierz *A, struct macierz *B, struct macierz *W)
{
if((A->w != B->w)||(A->k!=B->k))
{
printf("Tych macierzy nie da się odjąć.\n");
exit(0);
}
else
{
W->w = A->w;
W->k = A->k;
for(int i=0; i < A->k; i++)
    for(int j=0; j < B->w; j++)
    W->tab[i][j] = A->tab[i][j] - B->tab[i][j];
}
}
void prod(struct macierz *A, struct macierz *B, struct macierz *W)
{
if(A->k!=B->w)
{
printf("Tych macierzy nie pomnoży się niestety\n");
exit(0);
}
else
{
W->w = A->w;
W->k = B->k;
    for(int i = 0; i < A->w; i++)
    {
        for(int j = 0; j < B->k; j++)
        {   
            for(int k = 0; k < A->k; k++)
            {
            float c = A->tab[i][k]*B->tab[k][j];
            W->tab[i][j] += c;
            c = 0;
            }
        } 
    }
}
}
void multiply(struct macierz *A, float skalar, struct macierz *W)
{
W->w = A->w;
W->k = A->k;
for(int j=0;j<A->w;j++)
    for(int i=0; i<A->k; i++)
    W->tab[i][j] = A->tab[i][j] * skalar;
}
float norm(struct macierz *m) 
{
    float s = 0;
    int i,j;

    for (i = 0; i < m->w; i++) {
        for (j=0; j < m->k; j++) {
            s += m->tab[i][j] * m->tab[i][j];
        }
    }
    return s;
}