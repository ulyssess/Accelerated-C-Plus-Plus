CFLAGS = -std=c++11

permuted_index: main.o word.o cat.o
	g++ -o permuted_index main.o word.o cat.o

main.o: main.cpp
	g++ -c ${CFLAGS} main.cpp

word.o: word.cpp word.h
	g++ -c ${CFLAGS} word.cpp

cat.o: cat.cpp cat.h
	g++ -c ${CFLAGS} cat.cpp

clean:
	rm -rf *.o

distclean: clean
	rm -f permuted_index
