resu: display.o main.o Profile.o Loadsave.o
	g++  display.o main.o Profile.o Loadsave.o -o resu -lncurses

display.o: display.cpp
	g++ -c -std=c++11 display.cpp -lncurses
main.o: main.cpp
	g++ -c -std=c++11 main.cpp -lncurses
Profile.o: Profile.cpp
	g++ -c -std=c++11 Profile.cpp -lncurses
Loadsave.o: Loadsave.cpp
	g++ -c -std=c++11 Loadsave.cpp -lncurees
run:
	./resu
clean:
	rm -f resu
	rm -f *.o
dclean:
	rm -f *.dat
