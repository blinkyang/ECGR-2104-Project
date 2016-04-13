#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>

using namespace std;

class Profile
{
    public:
        Profile();
        Profile(string, string, int, int);
        void display_info();
        void display_banner();
        void setName();

    private:
        string user_name;
        string level;
        int energy_level;
        int steps;
};

#endif // PROFILE_H
