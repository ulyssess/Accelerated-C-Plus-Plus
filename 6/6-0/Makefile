CPPFLAGS= -ggdb -O0

all: split_palindrome vcat find_urls

split_palindrome: split_palindrome.cpp
	g++ $(CPPFLAGS) -o split_palindrome split_palindrome.cpp

vcat: vcat.cpp
	g++ $(CPPFLAGS) -o vcat vcat.cpp

find_urls: main.cpp
	g++ $(CPPFLAGS) -o find_urls main.cpp


clean:
	rm -rf *.o *.dSYM

distclean: clean
	rm -rf split_palindrome vcat find_urls
