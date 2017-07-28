CPPFLAGS= -ggdb -O0

PROG=test_find_urls

${PROG}: main.o find_urls.o
	g++ $(CPPFLAGS) -o ${PROG} main.o find_urls.o

main.o: main.cpp
	g++ -c ${CPPFLAGS} main.cpp

find_urls.o: find_urls.cpp find_urls.h
	g++ -c ${CPPFLAGS} find_urls.cpp

clean:
	rm -rf *.o *.dSYM

distclean: clean
	rm -rf ${PROG}
