resu: display.o main.o Profile.o
	g++  display.o main.o Profile.o -o resu -lncurses

display.o: display.cpp
	g++ -c -std=c++11 display.cpp -lncurses
main.o: main.cpp
	g++ -c -std=c++11 main.cpp -lncurses
profile.o: Profile.cpp
	g++ -c -std=c++11 Profile.cpp -lncurses
run:
	./resu
clean:
	rm -f resu
	rm -f *.o
dclean:
	rm -f *.dat
