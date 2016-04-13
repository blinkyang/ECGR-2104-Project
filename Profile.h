#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <curses.h>

using namespace std;

class Profile
{
    public:
        Profile();
        Profile(string, string, int, int);
        void display_info();
        void display_banner();

    private:
        string user_name;
        string level;
        int energy_level;
        int steps;
};

#endif // PROFILE_H
