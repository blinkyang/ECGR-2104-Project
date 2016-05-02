#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <ncurses.h>

using namespace std;

void event_data(string, string, int, int, int, int);
void convert(vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<int>&, vector<int>&, vector<int>&, vector<int>&, vector<int>&);
void print_event(string, string, int, int, int, int, vector<string>&, vector<string>&, vector<string>&, vector<int>&, vector<int>&, vector<int>&, vector<int>&, vector<int>&);


#endif // EVENT_HANDLER_H
