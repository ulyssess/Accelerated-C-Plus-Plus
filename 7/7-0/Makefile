CPPFLAGS= -ggdb -O0

all: counter xref

counter: counter.cpp
	g++ $(CPPFLAGS) -o $@ $<

xref: xref.cpp
	g++ $(CPPFLAGS) -o $@ $<

.PHONY : clean distclean

clean:
	rm -rf *.o *.dSYM

distclean: clean
	-rm counter xref
