#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Przedmiot* wczytaj_przedmioty(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Przedmiot *last_przedmiocik = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);


    for (i=0; i<n; i++) {
        Przedmiot *przedmiocik = (Przedmiot*) malloc(sizeof(Przedmiot));
        przedmiocik->nast = NULL;

        if (last_przedmiocik == NULL)
            glowa = przedmiocik;
        else
            last_przedmiocik->nast = przedmiocik;
        last_przedmiocik = przedmiocik;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przedmiocik->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiocik->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        przedmiocik->nazwa_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiocik->nazwa_przedmiotu, s);

        s = strtok(NULL, "\n");
        przedmiocik->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przedmiocik->semestr, s);

    }

    return glowa;
}

Ocena* wczytaj_ocenki(FILE *fin) { 
    char bufor[255];
    int n, i;
    char *s;
    Ocena *last_ocenka = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);


    for (i=0; i<n; i++) {
        Ocena *ocenka = (Ocena*) malloc(sizeof(Ocena));
        ocenka->nast = NULL;

        if (last_ocenka == NULL)
            glowa = ocenka;
        else
            last_ocenka->nast = ocenka;
        last_ocenka = ocenka;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        ocenka->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenka->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        ocenka->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenka->nr_albumu, s);

        s = strtok(NULL, ";");
        ocenka->ocena = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenka->ocena, s);

        s = strtok(NULL, "\n");
       ocenka->komentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocenka->komentarz, s);

    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_ocenki(fin);

    fclose(fin);
    return baza;
}



int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot *przedmiociki = baza->lista_przedmiotow;
    while (przedmiociki != NULL) {
        n++;
        przedmiociki = przedmiociki->nast;
    }
    return n;
}

int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena *ocenki = baza->lista_ocen;
    while (ocenki != NULL) {
        n++;
       ocenki = ocenki->nast;
    }
    return n;
}

void wypisz_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_studentow(SBaza *baza,FILE*fin) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        fprintf(fin,"%s;%s;%s;%s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}
void listuj_przedmioty(SBaza *baza,FILE*fin) {
    Przedmiot * przedmiocik = baza->lista_przedmiotow;
    while (przedmiocik != NULL) {
        fprintf(fin,"%s;%s;%s\n", przedmiocik->kod_przedmiotu, przedmiocik->nazwa_przedmiotu, przedmiocik->semestr);
        przedmiocik = przedmiocik->nast;
    }
}
void listuj_oceny(SBaza *baza,FILE*fin) {
    Ocena * ocenka = baza->lista_ocen;
    while (ocenka != NULL) {
        fprintf(fin,"%s;%s;%s;%s\n", ocenka->kod_przedmiotu, ocenka->nr_albumu, ocenka->ocena, ocenka->komentarz);
        ocenka = ocenka->nast;
    }
}

void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_przedmiot(Przedmiot *p) {
    free(p->kod_przedmiotu);
    free(p->nazwa_przedmiotu);
    free(p->semestr);
    free(p);
}

void zwolnij_liste_przedmiotow(Przedmiot *p){
    Przedmiot *n;
    while (p != NULL) {
        n = p->nast;
        zwolnij_przedmiot(p);
        p = n;
    }
}

void zwolnij_ocena(Ocena *o) {
    free(o->kod_przedmiotu);
    free(o->nr_albumu);
    free(o->ocena);
    free(o->komentarz);
    free(o);
}

void zwolnij_liste_ocen(Ocena *o){
    Ocena *n;
    while (o != NULL) {
        n = o->nast;
        zwolnij_ocena(o);
        o = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}

void dodaj_studenta(SBaza * baza, char *imie, char *nazwisko, char *nr_albumu, char *email){
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *teraz = NULL;
  	nowy->nast = NULL;
  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);
    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);
    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);
    teraz=baza->lista_studentow;
    
    if(ile_studentow(baza) == 0)
    {
      baza->lista_studentow = nowy;
    }
    else
    {
      for(int i=1; i<ile_studentow(baza); i++)
      {
        teraz = teraz->nast;
      }
      teraz->nast = nowy;
    }   
}


void dodaj_przedmiot(SBaza * baza, char *kod_przedmiotu, char *nazwa_przedmiotu, char *semestr){

 	Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));
  	Przedmiot *teraz = NULL;
  	nowy->nast = NULL;
  	nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);
    nowy->nazwa_przedmiotu = (char*) malloc(sizeof(char) * (strlen(nazwa_przedmiotu) + 1));
    strcpy(nowy->nazwa_przedmiotu, nazwa_przedmiotu);
    nowy->semestr = (char*) malloc(sizeof(char) * (strlen(semestr) + 1));
    strcpy(nowy->semestr, semestr);
    teraz = baza->lista_przedmiotow;
    
    if(ile_przedmiotow(baza) == 0)
    {
      baza->lista_przedmiotow = nowy;
    }
    else
    {
      for(int i=1; i<ile_przedmiotow(baza); i++)
      {
        teraz = teraz->nast;
      }
      teraz->nast = nowy;
    }

}

void dodaj_studenta_do_przedmiotu(SBaza * baza, char *nr_albumu, char *kod_przedmiotu, char *oceneczka, char *komentarzyk){
Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));
  	Ocena *teraz = NULL;
  	nowy->nast = NULL;
  	nowy->kod_przedmiotu = (char*) malloc(sizeof(char) * (strlen(kod_przedmiotu) + 1));
    strcpy(nowy->kod_przedmiotu, kod_przedmiotu);
    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);
    nowy->ocena = (char*) malloc(sizeof(char) * (strlen(oceneczka) + 1));
    strcpy(nowy->ocena, oceneczka);
    nowy->komentarz = (char*) malloc(sizeof(char) * (strlen(komentarzyk) + 1));
    strcpy(nowy->komentarz, komentarzyk);
    teraz = baza->lista_ocen;
    
    if(ile_ocen(baza) == 0)
    {
      baza->lista_ocen = nowy;
    }
    else
    {
      for(int i=1; i<ile_ocen(baza); i++)
      {
        teraz = teraz->nast;
      }
      teraz->nast = nowy;
    }
}

void zapisz_baze(char *nazwa_pliku, SBaza * baza) {
FILE *fin = fopen(nazwa_pliku, "w+");
fprintf(fin,"%d\n",ile_studentow(baza));
listuj_studentow(baza,fin);
fprintf(fin,"%d\n",ile_przedmiotow(baza));
listuj_przedmioty(baza,fin);
fprintf(fin,"%d\n",ile_ocen(baza));
listuj_oceny(baza,fin);
fclose(fin);
}