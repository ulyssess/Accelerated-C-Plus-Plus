CFLAGS = -std=c++11

permuted_index: main.o word.o vcat.o
	g++ -o permuted_index main.o word.o vcat.o

main.o: main.cpp
	g++ -c ${CFLAGS} main.cpp

word.o: word.cpp word.h
	g++ -c ${CFLAGS} word.cpp

vcat.o: vcat.cpp vcat.h
	g++ -c ${CFLAGS} vcat.cpp

clean:
	rm -rf *.o

distclean: clean
	rm -f permuted_index
