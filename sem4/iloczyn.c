#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Niestety nie dałem rady dokończyć programu, obejrzałem dwa ostatnie wykłady i zabrakło mi czasu. 
//Jest 23:09 i na tą chwilę stanąłem na zrobieniu z tych liczb macierzy i wymnożeniu ich, więc dodaje co mam. 
 
int main(int argc, char *argv[])
{
    int wa;     //liczba_wierszy_macierzy_a
    int ka;     //liczba_kolumn_macierzy_a
    int wx;    //liczba_wierszy_macierzy_x
    int kx;    //liczba_kolumn_macierzy_x
    FILE *fin;
    fin = fopen(argv[1], "r");
    fscanf(fin, "%d", &wa);
    fscanf(fin, "%d", &ka);

       FILE *fine;
    fine = fopen(argv[2], "r");
    fscanf(fine, "%d", &wx);
    fscanf(fine, "%d", &kx);

    printf("%d %d %d %d\n", wa, ka, wx, kx); //wypisuje wiersze i kolumny
    if(ka != wx)
    printf("Tych macierzy nie da się pomnożyć.\n");
 
    
} 
