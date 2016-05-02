resu: display.o main.o Profile.o load_save.o event_handler.o
	g++  display.o main.o Profile.o load_save.o event_handler.o -o resu -lncurses

display.o: display.cpp
	g++ -c -std=c++11 display.cpp -lncurses
main.o: main.cpp
	g++ -c -std=c++11 main.cpp -lncurses
Profile.o: Profile.cpp
	g++ -c -std=c++11 Profile.cpp -lncurses
load_save.o: load_save.cpp
	g++ -c -std=c++11 load_save.cpp -lncurses
event_handler.o: event_handler.cpp
	g++ -c -std=c++11 event_handler.cpp -lncurses
run:
	./resu
clean:
	rm -f resu
	rm -f *.o
dclean:
	rm -f *.dat
