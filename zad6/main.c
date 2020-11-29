#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytaj.h"
#include "dzialania.h"
#include "pokaz_wynik.h"

int main(int argc, char *argv[])
{
struct macierz A;
struct macierz B;
struct macierz W;

FILE * fileA;
FILE * fileB;
FILE * fileW;



if(strcmp(argv[1], "sum")==0)
{
if(argv[4]==NULL) // do pliku
{
fileA = fopen(argv[2],"r");
A = wczytaj(fileA);
fclose(fileA);
fileB = fopen(argv[3],"r");
B = wczytaj(fileB);
fclose(fileB);
suma(&A,&B,&W);
wypisz(&W);

}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    A = wczytaj(fileA);
    fclose(fileA);
    fileB = fopen(argv[3],"r");
    B = wczytaj(fileB);
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
A = wczytaj(fileA);
fclose(fileA);
fileB = fopen(argv[3],"r");
B = wczytaj(fileB);
fclose(fileB);
subtract(&A,&B,&W);
wypisz(&W);
}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    A = wczytaj(fileA);
    fclose(fileA);
    fileB = fopen(argv[3],"r");
    B = wczytaj(fileB);
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
A = wczytaj(fileA);
fclose(fileA);
fileB = fopen(argv[3],"r");
B = wczytaj(fileB);
fclose(fileB);
prod(&A,&B,&W);
wypisz(&W);
}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    A = wczytaj(fileA);
    fclose(fileA);
    fileB = fopen(argv[3],"r");
    B = wczytaj(fileB);
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
A = wczytaj(fileA);
fclose(fileA);
float skalar = atof(argv[3]);
multiply(&A,skalar,&W);
wypisz(&W);
}

    if(argv[4]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    A = wczytaj(fileA);
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
A = wczytaj(fileA);
fclose(fileA);
float s = sqrt(norm(&A));
printf("Norma zadanej macierzy wynosi: %.3f\n",s);
}
    if(argv[3]!=NULL) // do pliku
    {
    fileA = fopen(argv[2],"r");
    A = wczytaj(fileA);
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

zwolnij(&A);
zwolnij(&B);
zwolnij(&W);
return 0;
}