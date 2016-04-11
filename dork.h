/*********************************************************************
 * File: dork.h
 * Description: Header file for the game dork.h
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

#ifndef DORK_H
#define DORK_H

//Header files used
#include <iostream>
#include <cstring>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <cstdlib>
#include <random>
#include <unordered_map>

//Namespaces
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class dork
{
  //Function prototype
  
  //Display functions
  void display_init(); //Function to initialize ncurses terminal
  void display_close(); //Function to close ncurses terminal
  void intro_display();
  void displaytext (std::ifstream&); 
  void displaytext_delay(std::ifstream& );
  void clearDisplay(int);
  
  private:
    string user_name;
    string level;
    int energy_level;
    int steps;
};


#endif
