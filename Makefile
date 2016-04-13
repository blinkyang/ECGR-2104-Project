resu: display.o main.o 
	g++  display.o main.o -o resu -lncurses

display.o: display.cpp
	g++ -c -std=c++11 display.cpp -lncurses
main.o: main.cpp
	g++ -c -std=c++11 main.cpp -lncurses
Profile.o: profile.cpp
	g++ -c -std=c++11 profile.cpp -lncurses
run:
	./resu
clean:
	rm -f resu
	rm -f *.o
dclean:
	rm -f *.dat
