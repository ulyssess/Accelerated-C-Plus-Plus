CPPFLAGS= -ggdb -O0
grade: main.cpp grade.o median.o Student_info.o
	g++ $(CPPFLAGS) -o grade main.cpp grade.o median.o Student_info.o

grade.o: grade.cpp grade.h
	g++ $(CPPFLAGS) -c grade.cpp

median.o: median.cpp median.h
	g++ $(CPPFLAGS) -c median.cpp

Student_info.o: Student_info.cpp Student_info.h
	g++ $(CPPFLAGS) -c Student_info.cpp

clean:
	rm -f *.o

disclean: clean
	rm -rf grade
