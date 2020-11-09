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
for(int i=0; i < A->k; i++)
    for(int j=0; j < B->w; j++)
    W->tab[i][j] = A->tab[i][j] + B->tab[i][j];
}
}
void subtract(struct macierz *A, struct macierz *B, struct macierz *W)
{
if((&A->w != &B->w)||(&A->k!=&B->k))
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


int main(int argc, char *argv[])
{
struct macierz A = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
struct macierz B = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
struct macierz W = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
FILE * fileA;
FILE * fileB;
FILE * fileW;



if(strcmp(argv[1], "sum")==0)
{
if(argv[4]==NULL) // do pliku
{
fileA = fopen(argv[2],"r");
wczytaj(fileA,&A);
fclose(fileA);
fileB = fopen(argv[3],"r");
wczytaj(fileB,&B);
fclose(fileB);
suma(&A,&B,&W);
wypisz(&W);
}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    wczytaj(fileA,&A);
    fclose(fileA);
    fileB = fopen(argv[3],"r");
    wczytaj(fileB,&B);
    fclose(fileB);
    suma(&A,&B,&W);
    fileW = fopen(argv[4],"w+");
    zapisz(fileW,&W);
    fclose(fileW); 
    }
}
else if(strcmp(argv[1], "subtract")==0)
{
if(argv[4]==NULL) // do pliku
{
fileA = fopen(argv[2],"r");
wczytaj(fileA,&A);
fclose(fileA);
fileB = fopen(argv[3],"r");
wczytaj(fileB,&B);
fclose(fileB);
subtract(&A,&B,&W);
wypisz(&W);
}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    wczytaj(fileA,&A);
    fclose(fileA);
    fileB = fopen(argv[3],"r");
    wczytaj(fileB,&B);
    fclose(fileB);
    subtract(&A,&B,&W);
    fileW = fopen(argv[4],"w+");
    zapisz(fileW,&W);
    fclose(fileW); 
    }
}
else if(strcmp(argv[1], "prod")==0)
{
if(argv[4]==NULL) // do pliku
{
fileA = fopen(argv[2],"r");
wczytaj(fileA,&A);
fclose(fileA);
fileB = fopen(argv[3],"r");
wczytaj(fileB,&B);
fclose(fileB);
prod(&A,&B,&W);
wypisz(&W);
}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    wczytaj(fileA,&A);
    fclose(fileA);
    fileB = fopen(argv[3],"r");
    wczytaj(fileB,&B);
    fclose(fileB);
    prod(&A,&B,&W);
    fileW = fopen(argv[4],"w+");
    zapisz(fileW,&W);
    fclose(fileW); 
    }
}
else if(strcmp(argv[1], "multiply")==0)
{
if(argv[4]==NULL)    
{
fileA = fopen(argv[2],"r");
wczytaj(fileA,&A);
fclose(fileA);
float skalar = atof(argv[3]);
multiply(&A,skalar,&W);
wypisz(&W);
}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    wczytaj(fileA,&A);
    fclose(fileA);
    float skalar = atof(argv[3]);
    multiply(&A,skalar,&W);
    fileW = fopen(argv[4],"w+");
    zapisz(fileW,&W);
    fclose(fileW);  
    }
}
else if(strcmp(argv[1], "norm")==0)
{
if(argv[3]==NULL)
{
fileA = fopen(argv[2],"r");
wczytaj(fileA,&A);
fclose(fileA);
float s = sqrt(norm(&A));
printf("Norma zadanej macierzy wynosi: %.3f\n",s);
}
    if(argv[3]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    wczytaj(fileA,&A);
    fclose(fileA);
    float s = sqrt(norm(&A));
    fileW = fopen(argv[3],"w+");
    fprintf(fileW,"Norma zadanej macierzy wynosi: %.3f\n",s);
    fclose(fileW);
    }
}
else
{
    printf("Nie rozumiem człowieku");
}
}