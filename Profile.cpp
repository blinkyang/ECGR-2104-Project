#include "Profile.h"
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
    printf("--------------------------------------------------------------------------\n");
    printf("Hello ");
    printf("%s", user_name.c_str());
    printf("\tLevel: ");
    printf("%s", level.c_str());
    printf("\tEnergy Level: ");
    printf("%d", energy_level);
    printf("\tSteps: ");
    printf("%d", steps);
    cout << steps << endl;
    printf("\n--------------------------------------------------------------------------\n");
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
