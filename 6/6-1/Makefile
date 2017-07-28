CPPFLAGS= -ggdb -O0

PROG="a.out"

${PROG}: main.cpp
	g++ $(CPPFLAGS) -o ${PROG} main.cpp

clean:
	rm -rf *.o *.dSYM

distclean: clean
	rm -rf ${PROG}
