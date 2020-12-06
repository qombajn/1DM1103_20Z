all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

dodaj-ferdka: all
	./mydb baza.csv add_student Ferdynand Kiepski 0700 ferdek@kiepski.pl

dodaj-kiszenie_ogórków: all
	./mydb baza.csv add_course 123456789 kiszenie_ogórków 2020Z

dodaj-ocene_ferdkowi: all
	./mydb baza.csv add_student_to_course 123456789 0700 6.0 Bardzo_dobrze_panie_ferdku

test-memory: all
	valgrind  ./mydb baza.csv count_students --leak-check=full
