#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz {
int w;
int k;
float tab[5][5];
};

void wczytaj(FILE * fin, struct macierz *m)
{

    int i,j;
    fscanf(fin, "%d", &m->w);
    fscanf(fin, "%d", &m->k);

    for (i=0; i < m->w; i++) 
    {
        for (j=0; j < m->k; j++) 
        {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}
void wypisz(struct macierz m) 
{
    int i, j;
    printf("[ ");
    for (i = 0; i < m.w; i++) {
        for (j=0; j < m.k; j++) {
            printf("%5.1f ", m.tab[i][j]);
        }
        if (i < (m.w-1))
            printf("\n  ");
    }
    printf("]\n");
}
void zapisz(char nazwa[], struct macierz m) 
{
    FILE * fout = fopen(nazwa, "w+");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.w, m.k);
    for (i = 0; i < m.w; i++) 
    {
        for (j=0; j < m.k; j++) 
        {
            fprintf(fout, "%f\n", m.tab[i][j]);
        }
    }

fclose(fout);

}
struct macierz suma(struct macierz A, struct macierz B)
{
if((A.w!=B.w)&&(A.k!=B.k))
{
printf("Tych macierzy nie da się dodać.");
}
else
{
struct macierz tab;
for(int i=0; i<A.k; i++)
    for(int j=0;i<B.w;j++)
    {
    tab.tab[i][j] = A.tab[i][j] + B.tab[i][j];
    }
return tab;
}
}
struct macierz substract(struct macierz A, struct macierz B)
{
if((A.w!=B.w)&&(A.k!=B.k))
{
printf("Tych macierzy nie da się odjąć.");
}
else
{
struct macierz tab;
for(int i=0; i<A.k; i++)
    for(int j=0;i<B.w;j++)
    {
    tab.tab[i][j] = A.tab[i][j] - B.tab[i][j];
    }
return tab;
}
}
struct macierz prod(struct macierz A, struct macierz B)
{
if(A.k!=B.w)
{
printf("Tych macierzy nie pomnożysz");
}
else
{
    struct macierz iloczyn;
    for(int i = 0; i < A.w; i++)
    {
        for(int j = 0; j < B.k; j++)
        {   
            for(int k = 0; k<A.k; k++)
            {
            float c = A.tab[i][k]*B.tab[k][j];
            iloczyn.tab[i][j] += c;
            c=0;
            }
        } 
    }
return iloczyn;
}
}
struct macierz multiply(struct macierz A, float skalar)
{
struct macierz tab;
for(int i=0; i<A.k; i++)
    for(int j=0;i<A.w;j++)
    {
    tab.tab[i][j] = A.tab[i][j] * skalar;
    }
return tab;
}
double norm(struct macierz A) {
    float s = 0;
    int i,j;

    for (i = 0; i < A.w; i++) {
        for (j=0; j < A.k; j++) {
            s += A.tab[i][j] * A.tab[i][j];
        }
    }
    return sqrt(s);
}


int main(int argc, char *argv[])
{
struct macierz A;
struct macierz B;
FILE * fileA;
FILE * fileB;
FILE * fileW;

if(strcmp(argv[1], "sum")==0)
{
if(strcmp(argv[4],"W.txt")==0) // do pliku
{
fileA = fopen(argv[2],"r");
fileW - fopen(argv[4],"w");
wczytaj(fileA, &A);
wczytaj(fileB, &B);
zapisz(argv[4],suma(A,B));
fclose(fileW);
}
else // na tablice
{
fileA = fopen(argv[2],"r");
wczytaj(fileA, &A);
wczytaj(fileB, &B);
wypisz(suma(A,B));
}
}
else if(strcmp(argv[1], "subtract")==0)
{
if(strcmp(argv[4],"W.txt")==0) // do pliku
{
fileA = fopen(argv[2],"r");
fileW - fopen(argv[4],"w");
wczytaj(fileA, &A);
wczytaj(fileB, &B);
zapisz(argv[4],substract(A,B));
fclose(fileW);
}
else // na tablice
{
fileA = fopen(argv[2],"r");    
wczytaj(fileA, &A);
wczytaj(fileB, &B);
wypisz(substract(A,B));
}
}
else if(strcmp(argv[1], "prod")==0)
{
if(strcmp(argv[4],"W.txt")==0) // do pliku
{
fileW - fopen(argv[4],"w");
wczytaj(fileA, &A);
wczytaj(fileB, &B);
zapisz(argv[4],prod(A,B));
fclose(fileW);
}
else // na tablice
{
wczytaj(fileA, &A);
wczytaj(fileB, &B);
wypisz(prod(A,B));
}
}
else if(strcmp(argv[1], "multiply")==0)
{
if(strcmp(argv[4],"W.txt")==0) // do pliku
{
fileA = fopen(argv[2],"r");
fileW - fopen(argv[4],"w");
float skalar = atof(argv[3]);
wczytaj(fileA, &A);
zapisz(argv[4],multiply(A,skalar));
fclose(fileW);
}
else // na tablice
{
fileA = fopen(argv[2],"r");
float skalar = atof(argv[3]);
wczytaj(fileA, &A);
wypisz(multiply(A,skalar));
}
}
else if(strcmp(argv[1], "norm")==0)
{
if(strcmp(argv[3],"W.txt")==0) // do pliku
{
fileA = fopen(argv[2],"r");
fileW - fopen(argv[3],"w");
wczytaj(fileA, &A);
fprintf(fileW,"Norma macierzy wynosi:%f",norm(A));
fclose(fileW);
}
else // na tablice
{
fileA = fopen(argv[2],"r");
wczytaj(fileA, &A);
printf("Norma macierzy wynosi:%f",norm(A));
}
}
else
{
    printf("Nie rozumiem człowieku");
}

return 0;
}