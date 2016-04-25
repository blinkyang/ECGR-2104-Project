#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <ncurses.h>

using namespace std;

class Profile
{
    public:
        Profile();
	Profile(string);
        Profile(string, string, int, int, int, int);
        void display_info();
	void roll();

    private:
        string user_name;
        string level;
	char input;
        int energy_level;
        int steps;
	int dice;
	int y_location = 0;
	int x_location = 0;
	int temp_steps = 0;
};

#endif // PROFILE_H
