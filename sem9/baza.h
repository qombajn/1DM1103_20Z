#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
char * kod_przedmiotu;
char * nazwa_przedmiotu;
char * semestr;

struct _Przedmiot *nast;
} Przedmiot;

 typedef struct _Ocena {
char * kod_przedmiotu;
char * nr_albumu;
char * ocena;
char * komentarz;
   struct _Ocena *nast;
} Ocena;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
void zapisz_baze(char *nazwa_pliku, SBaza * baza);
void dodaj_studenta(SBaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email);
void dodaj_przedmiot(SBaza * baza, char *kod_przedmiotu, char *nazwa_przedmiotu, char *semestr);
void dodaj_studenta_do_przedmiotu(SBaza * baza, char *nr_albumu, char *kod_przedmiotu, char *oceneczka, char *komentarzyk);
void wypisz_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
int ile_przedmiotow(SBaza *baza);
int ile_ocen(SBaza *baza);
#endif