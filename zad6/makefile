

DEPS=main.o pokaz_wynik.o wczytaj.o dzialania.o


main: $(DEPS)
	cc $(DEPS) -o main -lm -Wall --pedantic
%.o:%.c
	cc -c $^ -o $@
clean:
	rm -f main
	rm -f *.o