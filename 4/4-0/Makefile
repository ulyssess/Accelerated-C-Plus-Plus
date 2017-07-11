grade: main.cpp grade.o median.o Student_info.o
	g++ -o grade main.cpp grade.o median.o Student_info.o

grade.o: grade.cpp grade.h
	g++ -c grade.cpp

median.o: median.cpp median.h
	g++ -c median.cpp

Student_info.o: Student_info.cpp Student_info.h
	g++ -c Student_info.cpp

clean:
	rm -f *.o

disclean:
	rm -f grade
