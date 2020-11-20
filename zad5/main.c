/*Podziel na trzy moduły:
1. main.c
2. studenci.c
3. dziekanat.c

Program ma mieć argument linii komend, za pomocą któego mozemy wybrać co 
chcemy policzyć (czy najlepszy student, czy najtrudniejszy przedmiot).

Utworz makefile
    * budowanie programu %.o:%.c
    * clean

Jako wynik załącz do ISODa archiwum repozytoirum ZIP.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
#include "dziekanat.h"





int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
if(strcmp(argv[2], "najtrudniejszy_przedmiot")==0)
najtrudniejszy_przedmiot(dane, ile);
else if(strcmp(argv[2], "najlatwiejszy_przedmiot")==0)
    najlatwiejszy_przedmiot(dane, ile);
else if(strcmp(argv[2], "najlepszy_student")==0)
najlepszy_student(dane,ile);
else
    printf("Follow the white rabbit.\n");
}