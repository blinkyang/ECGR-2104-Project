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
    	//clearDisplay(1);
    
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
	while(/*(x_location < 201 && y_location < 150) ||*/ energy_level > 0)
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

		printw("Press R to roll: ");
		input = getch();

		if(input == 'R' || input == 'r')
		{
			dice = rand() % 6+1;
			energy_level--;
			steps += dice;
			temp_steps += dice;
			
			if(level == "Terrestrial")
			{
				x_location = steps;
			}
			else if(level == "Arboreal")
			{
				y_location = steps;
			}
			else if(level == "Aerial")
			{
				x_location = steps;
			}

			if(temp_steps >= 25)
			{
				checkpoint(user_name, level, energy_level, steps, y_location, x_location);
				temp_steps = 0;
			}
		
		}
		else
		{
			printw("Invalid input. Try again.");
		
			roll();
		}

		clearDisplay(1);
	}
}
