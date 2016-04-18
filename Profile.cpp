#include "dork.h"
#include "Profile.h"
#include <fstream>
#include <iostream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
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
    cout << endl;
   // printw("--------------------------------------------------------------------------");
    cout << endl;
    cout << "Welcome, " << user_name << "!" << "\tLevel: " << level << "\tEnergy Level: " << energy_level << "\tSteps: " << steps;
    cout << endl;
  //  printw("--------------------------------------------------------------------------");
    cout << endl;
}

int main () {
    
    ofstream ofs("save.dat");
    
    {
        boost::archive::text_oarchive oa(ofs);
        oa << 
    }
    
return 0;
}

