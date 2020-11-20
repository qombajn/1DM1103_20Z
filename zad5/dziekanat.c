#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
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
    
  // for (i=0;i<ile_przedmiotow; i++) 
   //printf("Przedmiot [%d]: %s średnia: %f\n", i+1, kod_przed[i], srednia[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza > srednia[i]) {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najłatwiejszy przedmiot: \n");
    printf("%s - %s a średnia z tego przedmiotu wynosi: %.2f \n", 
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
    
  //for (i=0;i<ile_przedmiotow; i++) 
  //printf("Przedmiot [%d] %s : %s średnia: %f\n", i+1, nazwa_przed[i], kod_przed[i], srednia[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < srednia[i]) {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najłatwiejszy przedmiot: \n");
    printf("%s - %s a średnia z tego przedmiotu wynosi: %.2f \n", 
         kod_przed[najlepsza_pozycja],
       nazwa_przed[najlepsza_pozycja],
        srednia[najlepsza_pozycja]
    );

}

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;
    for(int j = 0; j<100; j++){
        sumy_ects[j] = 0;
        sumy_wazonych_ocen[j] = 0;
    }

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

  // for (i=0;i<ile_studentow; i++) 
      // printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], 
      // sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

}