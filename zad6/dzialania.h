#ifndef dzialania_h
#define dzialania_h
void suma(struct macierz *A, struct macierz *B, struct macierz *W);
void subtract(struct macierz *A, struct macierz *B, struct macierz *W);
void prod(struct macierz *A, struct macierz *B, struct macierz *W);
void multiply(struct macierz *A, float skalar, struct macierz *W);
float norm(struct macierz *m);
#endif