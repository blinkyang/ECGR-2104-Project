#include "Profile.h"
#include <iostream>
#include <string>

using namespace std;

Profile::Profile()
{
    user_name = " ";
    level = "Terrestrial";
    energy_level = 15;
    steps = 0;
}

Profile::Profile(string un, string curr_level, signed int en_lev, int num_steps)
{
    user_name = un;
    level = curr_level;
    
    if (en_lev > 30) {
        energy_level = 30;
    }
    else {
        energy_level = en_lev;
    }
    steps = num_steps;
}

void Profile::display_info()
{
    cout << endl << "--------------------------------------------------------------------------" << endl
         << "Welcome, " << user_name << "!" << "\tLevel: " << level << "\tEnergy Level: " << energy_level << "\tSteps: " << steps
         << endl << "--------------------------------------------------------------------------" << endl;
}
