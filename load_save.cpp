#include "load_save.h"
#include "dork.h"
#include "Profile.h"
#include <iostream>

using namespace std;

void opening()
{
	char input;

	clearDisplay(1);	

	cout << "Load or new game? (L/N): ";
	cin >> input;

	if(input == 'l' || input == 'L')
	{
		load();
	}
	else if(input == 'n' || input == 'N')
	{
		clearDisplay(1);
		newGame();
	}
	else
	{
		cout << "Error! Wrong input!" << endl;
		opening();
	}
}

void load()
{
	ifstream load_prof("profile.dat");
}

void save(string name, string level, int num_steps, int en_level, int x, int y)
{
	ofstream profile("profile.dat");

	profile << name << endl
		<< level << endl
		<< num_steps << endl
		<< en_level << endl
		<< y << ", " << x << endl;
} 

void checkpoint(string name, string level, int num_steps, int en_lev, int x, int y)
{
	save(name, level, num_steps, en_lev, x, y);
}

void newGame() 
{
	string name;

	cout << "What's your name? ";
	cin >> name;

	Profile player(name);
	player.display_info();
	player.roll();
}
