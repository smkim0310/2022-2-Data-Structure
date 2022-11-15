//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민
qsort: quick.o comparator.o printlist.o
	g++ -std=c++11 quick.o comparator.o printlist.o -o qsort
quick.o: quick.cpp
	g++ -c -std=c++11 quick.cpp -I../../include
comparator.o: comparator.cpp
	g++ -c -std=c++11 comparator.cpp
printlist.o: printlist.cpp
	g++ -c -std=c++11 printlist.cpp
clean:
	rm -f *.o qsort.exe qsort
