/*
Proszę przerobić program z seminarium tak, aby znajdował i wyświetlał na ekranie dwa przedmioty (ma wyświetlać zarówno kod przedmiotu jak i nazwę przedmiotu!):


	
z najlepszą średnią ocen studentów
	z najgorszą średnią ocen studentów


(Czyli najłatwiejszy przedmiot i najtrudniejszy :-))

Chciałbym, aby wynik na ekranie był wyświetlony w następującej formie:

Najlepsza średnia: 1DE0000 - Nazwa najlepszego przedmiotu: 4.5
Najgorsza średnia: 1DE1111 - Nazwa najgorszego przedmiotu: 2.5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

int znajdz(char *szukany_nr, char kod_przed[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, kod_przed[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kod_przed, ile_znalazlem ) == -1) {
            strncpy(kod_przed[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}


void najtrudniejszy_przedmiot(student dane[100], int ile_rekordow) {
    char kod_przed[100][10];
    char nazwa_przed[100][255];
    int ile_przedmiotow;
    float srednia[100];
    for(int j = 0; j<100; j++)
    srednia[j]=0;
    int ile_dodawan[100];
    for(int j = 0; j<100; j++)
    ile_dodawan[j]=0;
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 6.0f;

    ile_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);
    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przedmiotow );
        strcpy(nazwa_przed[pozycja],dane[i].nazwa_przed);
        ile_dodawan[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }   
    for (i=0; i < ile_przedmiotow; i++) {
        srednia[i] = srednia[i]/ile_dodawan[i];
    }   
    
   //for (i=0;i<ile_przedmiotow; i++) 
  // printf("Przedmiot [%d]: %s średnia: %f\n", i+1, kod_przed[i], srednia[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza > srednia[i]) {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najgorsza średnia: ");
    printf("%s - %s: %.2f \n", 
         kod_przed[najlepsza_pozycja],
       nazwa_przed[najlepsza_pozycja],
        srednia[najlepsza_pozycja]
    );

}

void najlatwiejszy_przedmiot(student dane[100], int ile_rekordow) {
    char kod_przed[100][10];
    char nazwa_przed[100][255];
    int ile_przedmiotow;
    float srednia[100];
    for(int j = 0; j<100; j++)
    srednia[j]=0;
    int ile_dodawan[100];
    for(int j = 0; j<100; j++)
    ile_dodawan[j]=0;
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);
    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przedmiotow );
        strcpy(nazwa_przed[pozycja],dane[i].nazwa_przed);
        ile_dodawan[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }   
    for (i=0; i < ile_przedmiotow; i++) {
        srednia[i] = srednia[i]/ile_dodawan[i];
    }   
    
  // for (i=0;i<ile_przedmiotow; i++) 
  // printf("Przedmiot [%d] %s : %s średnia: %f\n", i+1, nazwa_przed[i], kod_przed[i], srednia[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < srednia[i]) {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepsza średnia: ");
    printf("%s - %s: %.2f \n", 
         kod_przed[najlepsza_pozycja],
       nazwa_przed[najlepsza_pozycja],
        srednia[najlepsza_pozycja]
    );

}


int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);

    najtrudniejszy_przedmiot(dane, ile);
   najlatwiejszy_przedmiot(dane, ile);
}