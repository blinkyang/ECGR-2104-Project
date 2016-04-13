/*********************************************************************
 * File: display.cpp
 * Description: Display functions for Intro ASCII art display
 * Author: Abhi (adevalap@uncc.edu)
 * University: UNC Charlotte
 * 
 * Copyright (C) 2016, Abhilash Devalapura Rajagopala
 * This program is part of UNC Charlotte course project
 * and is distributed for education purpose only.
 * All commercial rights are reserved by the author on
 * distibution of the game database, custom function , header, ascii art
 * and other related to this game pack.
 * must be properly acknowledge.
 * /
 * *******************************************************************/
 
#include "dork.h"
void display_init()
{
	initscr();			/* Start curses */
	raw();
	echo();
}

void display_close()
{
	endwin();			/* End curses   */
	exit(0);			/* Make clean exit */
}	

void intro_display()
{
	    std::ifstream Art ("art.txt");
	    std::ifstream Intro("intro.txt");
	    std::ifstream Intro("Banner.txt");
	    displaytext(Art);
	    displaytext_delay(Intro);
	    displaytext(Banner);
	    Art.close();
	    Intro.close();	
}
void displaytext (std::ifstream& File)
{
    std::string Lines = "";
    if (File) 
    {
		while (File.good ())
		{
			std::string TempLine;                  
			std::getline (File , TempLine);
			TempLine += "\n";                     
			Lines += TempLine;
		}	
		char myArray[Lines.size()+1];
		strcpy(myArray, Lines.c_str());
		printw(myArray);
		refresh();
	}
    else
    {
	cout<< "ERROR File does not exist.";
    }
}

void displaytext_delay(std::ifstream& File)
{
    std::string Lines = ""; 
    int j=0;
    sleep_for(seconds(3));
    if (File)  
    {
		while (File.good ())
		{
			std::string TempLines; 
			std::getline (File , TempLines);
			TempLines += "\n";
			char myArray[TempLines.size()+1];
			strcpy(myArray, TempLines.c_str());
				for (int i=0; i<TempLines.size();i++)
				{
				mvaddch(j,(40+i),myArray[i]);
				refresh();
				sleep_for(milliseconds(50));
				}
			j=j+1;
			refresh();
			sleep_until(system_clock::now() + seconds(1));
		}
		printw("###################$$$$$$$$$$$$$$$$###################\n");
		printw("                   WELCOME TO DORK\n");
		printw("###################$$$$$$$$$$$$$$$$###################\n");
    }
    else                           //Return error
    {
	cout<< "ERROR File does not exist.";
    }
}

void clearDisplay(int num){
	if(num==0)
	clear();
	else{
	clear();
	std::ifstream banner ("banner.txt"); 
	displaytext(banner);}
	refresh();
}
