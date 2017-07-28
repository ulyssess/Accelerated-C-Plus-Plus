CPPFLAGS= -ggdb -O0

all: grade

grade: main.cpp grade.o median.o Student_info.o extract.o
	g++ $(CPPFLAGS) -o grade main.cpp grade.o median.o Student_info.o extract.o

grade.o: grade.cpp grade.h
	g++ $(CPPFLAGS) -c grade.cpp

median.o: median.cpp median.h
	g++ $(CPPFLAGS) -c median.cpp

Student_info.o: Student_info.cpp Student_info.h
	g++ $(CPPFLAGS) -c Student_info.cpp

extract.o: extract.cpp extract.h
	g++ $(CPPFLAGS) -c extract.cpp


clean:
	rm -rf *.o *.dSYM

distclean: clean
	rm -rf grade
