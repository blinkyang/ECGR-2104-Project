/**********************************************************************
 * File: Profile.cpp
 * Description: Creates a class for the player
 * Author: Toubee Lo, Andy Dang, Kongyeng Yang
 * University: UNC Charlotte
***********************************************************************/

#include "Profile.h"
#include "load_save.h"
#include "event_handler.h"
#include "dork.h"
#include <iostream>

using namespace std;

Profile::Profile()
{
    	user_name = " ";
    	level = "Terrestrial";
    	energy_level = 15;
    	steps = 0;
}

Profile::Profile(string un)
{
	user_name = un;
    	level = "Terrestrial";
    	energy_level = 15;
    	steps = 0;
}

Profile::Profile(string un, string curr_level, int en_lev, int num_steps, int y, int x)
{
    	user_name = un;
    	level = curr_level;
    	energy_level = en_lev;
    	steps = num_steps;
	y_location = y;
	x_location = x;
	
}

void Profile::display_info()
{   
	printw("--------------------------------------------------------------------------\n");
    	printw("Hello ");
    	printw("%s", user_name.c_str());
    	printw("\tLevel: ");
    	printw("%s", level.c_str());
    	printw("\tEnergy Level: ");
    	printw("%d", energy_level);
    	printw("\tSteps: ");
    	printw("%d", steps);
    	printw("\n--------------------------------------------------------------------------\n");

	refresh();
}

void Profile::roll()
{
	while(energy_level > 0)
	{
		srand(time(0));

		event_data(user_name, level, energy_level, steps, y_location, x_location, food, roll_counter);
		display_info();

		if(food > 0 && roll_counter >= 0)
		{
			printw("Do you want to eat your stored food? (Y/N): ");
			input = getch();
			printw("\n\n");

			if(input == 'y' || input == 'Y')
			{
				energy_level += food;
				food = 0;
			}
			else if(input == 'n' || input == 'N')
			{
				roll_counter--;
			}
		}
	
		if(x_location == 201 && y_location == 150)
		{
			printw("\n\nTHE END");
			break;
		}

		printw("Press R to roll: ");
		input = getch();

		if(input == 'R' || input == 'r')
		{
			dice = rand() % 6+1;
			energy_level--;
			steps += dice;
			temp_steps += dice;
			
			if(level == "Terrestrial" || level == "Aerial")
			{
				x_location = steps;
			}
			else
			{
				y_location = steps;
			}

			if(temp_steps >= 25)
			{
				checkpoint(user_name, level, energy_level, steps, y_location, x_location);
				temp_steps = 0;
			}
		
		}
		else
		{
			clearDisplay(1);
			printw("Invalid input. Try again.\n\n");
			roll();
		}

		if(x_location > 201 || y_location > 150)
		{
			clearDisplay(1);
			display_info();
			printw("\n\nYou're lost...");
			printw("\nWould you like to retry? (Y/N): ");
			input = getch();
			
			if(input == 'y' || input == 'Y')
			{	
				clearDisplay(1);
				opening();
			}
			else if(input == 'n' || input == 'N')
			{
				break;
			}
		}

		if(energy_level <= 0)
		{
			clearDisplay(1);
			display_info();
			printw("\n\nYou starved to death...");
			printw("\nWould you like to retry? (Y/N): ");
			input = getch();
			
			if(input == 'y' || input == 'Y')
			{	
				clearDisplay(1);
				opening();
			}
			else if(input == 'n' || input == 'N')
			{
				break;
			}
		}

		clearDisplay(1);
	}
}
