#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

/*Program do zrobienia:

    Program obsługujący bazę danych (zakładamy, że mamy plik z bazą danych (wczytujemy do pamięci, potem wykonujemy operację i całość znowu zapisujemy do pliku))
    Operacje:
        dodaj studenta (np.: ./mydb add student imie nazwisko nr albumu email)
        dodaj przedmiot (np. ./mydb add course 1DE2103 "Metody numeryczne" 2020Z)
        dodaj studenta do przedmiotu (np.: ./mydb add student_to_course 123456 1DE1203)

Dopisz funkcje: zapisz_baze()...

Proszę zaprojektować interfejs. Można użyć przykładu. Proszę napisać makefile zawierający między innymi co najmniej 3 przykłady testowe.

Proszę wgrać zzipowane archiwum github!
*/

int main(int argc, char ** argv) {
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);

    if (strcmp("list_students", argv[2]) == 0) {
        wypisz_studentow(baza);
    } else if (strcmp("add_student", argv[2]) == 0) {
        dodaj_studenta(baza, argv[3], argv[4], argv[5], argv[6]);
    }else if (strcmp("add_course", argv[2]) == 0) {
        dodaj_przedmiot(baza, argv[3], argv[4], argv[5]);
    }else if (strcmp("add_student_to_course", argv[2]) == 0) {
        dodaj_studenta_do_przedmiotu(baza, argv[3], argv[4], argv[5], argv[6]);
    } else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
    }

    zapisz_baze("baza.csv", baza);
    zwolnij(baza);
    return 0;
}