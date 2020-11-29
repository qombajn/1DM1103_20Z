#ifndef wczytaj_h
#define wczytaj_h
struct macierz {
int w;
int k;
float **tab;
};

struct macierz wczytaj(FILE* fin);
void zwolnij(struct macierz *m);
struct macierz alokuj(struct macierz *m);
#endif