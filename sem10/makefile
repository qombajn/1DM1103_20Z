all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ilestud: all
	./mydb baza.csv count_students

test-ileprzed: all
	./mydb baza.csv count_courses

test-memory: all
	valgrind --leak-check=full ./mydb baza.csv list students 

test-dodajucznia: all
	./mydb baza.csv add_student Adam Małysz 88888 zakopane@wykopane.pl

test-dodajprzed: all
	./mydb baza.csv add_course 1DG7777 Dakar 2020Z
	
test-dodajuczniadoprzed: all
	./mydb baza.csv add_student_to_course 1DG7777 88888 5.0 Good_job

test-sortuj-stud-malejaco: all
	./mydb baza.csv sortuj_malejąco

test-sortuj-stud-rosnaco: all
	./mydb baza.csv sortuj_rosnąco

test-sort-przed-po-kodzie: all
	./mydb baza.csv sortuj_byku_po_kodzie

test-sort-przed-po-nazwie: all
	./mydb baza.csv sortuj_byku_po_nazwie

test-filtruj_przedmiot: all
	./mydb baza.csv filtruj_przedmiot 1DA1111

test-filtruj_ucznia: all
	./mydb baza.csv filtruj_ucznia 22222

