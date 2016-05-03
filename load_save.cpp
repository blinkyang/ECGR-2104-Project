#include "load_save.h"
#include "dork.h"
#include "Profile.h"
#include <iostream>

using namespace std;

void opening()
{
	char input;

	clearDisplay(1);	

	printw("Load or new game? (L/N): ");
	input = getch();

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
	string name;
	string level;
	int en_lev;
	int num_steps;
	int x;
	int y;

	load_prof >> name >> level >> en_lev
		  >> num_steps >> y >> x;

	Profile player(name, level, en_lev, num_steps, y, x);
	player.roll();
}

void save(string name, string level, int en_lev, int num_steps, int y, int x)
{
	ofstream profile("profile.dat");

	profile << name << endl
		<< level << endl
		<< en_lev << endl
		<< num_steps << endl
		<< y << endl
		<< x << endl;
} 

void checkpoint(string name, string level, int num_steps, int en_lev, int y, int x)
{
	save(name, level, num_steps, en_lev, y, x);
}

void newGame() 
{
	char name[200];

	printw("What's your name? ");
	getstr(name);

	clearDisplay(1);

	Profile player(name);
	player.roll();
}
