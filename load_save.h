#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ncurses.h>

using namespace std;

void opening();
void newGame();
void load();
void save(string, string, int, int, int, int);
void checkpoint(string, string, int, int, int, int);

#endif // LOAD_SAVE_H
