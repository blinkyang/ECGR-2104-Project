#include "Profile.h"
#inclde "dork.h"
#include <iostream>

using namespace std;

Profile::Profile()
{
    user_name = " ";
    level = "Terrestrial";
    energy_level = 15;
    steps = 0;
}

Profile::Profile(string un, string curr_level, int en_lev, int num_steps)
{
    user_name = un;
    level = curr_level;
    energy_level = en_lev;
    steps = num_steps;
}

void Profile::display_info()
{
    clearDisplay(1);
    
    printw("--------------------------------------------------------------------------\n");
    printw("Hello ");
    printw("%s", user_name.c_str());
    printw("\tLevel: ");
    printw("%s", level.c_str());
    printw("\tEnergy Level: ");
    printw("%d", energy_level);
    printw("\tSteps: ");
    printw("%d", steps);
    cout << steps << endl;
    printw("\n--------------------------------------------------------------------------\n");
}

void Profile::setName() 
{

	cout << "What's your name?" << endl;
	cin >> user_name;
}

void Profile::display_banner()
{
    ifstream infile("banner.txt");
    vector<string> content;
    string line;

    while(infile)
    {
        getline(infile, line);
        content.push_back(line);
    }

    for(auto x:content)
    {
        cout << x << endl;
    }
}
