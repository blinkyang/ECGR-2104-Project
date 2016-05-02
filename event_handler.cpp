#include "event_handler.h"
#include "load_save.h"

using namespace std;

void event_data(string name, string lev, int en_lev, int num_steps, int yC, int xC)
{
	ifstream infile("events.txt");
	string temp;
	vector<string> content;
	vector<string> y_coord;
	vector<string> x_coord;
	vector<string> event;
	vector<string> response;
	vector<string> energy;
	vector<string> y_location;
	vector<string> x_location;
	vector<string> question;
	vector<int> y_C;
	vector<int> x_C;
	vector<int> y_L;
	vector<int> x_L;
	
	while(getline(infile, temp, '^'))
	{
		content.push_back(temp);
	}

	for(int i = 6; i < 1200; i+=6)
	{
		istringstream buffer(content[i]);
		getline(buffer, temp, ',');
		y_coord.push_back(temp);
		getline(buffer, temp);
		x_coord.push_back(temp);
	}

	for(int i = 6; i < 1200; i+=6)
	{
		event.push_back(content[i+1]);
	}

	for(int i = 6; i < 1200; i+=6)
	{
		response.push_back(content[i+2]);
	}

	for(int i = 6; i < 1200; i+=6)
	{
		energy.push_back(content[i+3]);
	}

	for(int i = 6; i < 1200; i+=6)
	{
		istringstream buffer(content[i+4]);
		getline(buffer, temp, ',');
		y_location.push_back(temp);
		getline(buffer, temp);
		x_location.push_back(temp);
	}

	for(int i = 6; i < 1200; i+=6)
	{
		question.push_back(content[i+5]);
	}

	convert(y_coord, x_coord, y_location, x_location, y_C, x_C, y_L, x_L);
	print_event(name, lev, en_lev, num_steps, yC, xC, event, response, question, y_C, x_C, y_L, x_L);
}

void convert(vector<string>& yC, vector<string>& xC, vector<string>& yL, vector<string>& xL, vector<int>& temp_yC, vector<int>& temp_xC, vector<int>& temp_yL, vector<int>& temp_xL)
{
	int temp;
	string str;
	
	for(int i = 0; i < yC.size(); i++)
	{
		str = yC[i];
		temp = stol(str.substr(0));
		temp_yC.push_back(temp);
	}

	for(int i = 0; i < xC.size(); i++)
	{
		str = xC[i];
		temp = stol(str.substr(0));
		temp_xC.push_back(temp);
	}

	for(int i = 0; i < yL.size(); i++)
	{
		str = yL[i];
		temp = stol(str.substr(0));
		temp_yL.push_back(temp);
	}

	for(int i = 0; i < xL.size(); i++)
	{
		str = xL[i];
		temp = stol(str.substr(0));
		temp_xL.push_back(temp);
	}
}

void print_event(string n, string l, int en, int s, int yCoord, int xCoord, vector<string>& desc, vector<string>& resp, vector<string>& ques, vector<int>& temp_yC, vector<int>& temp_xC, vector<int>& temp_yL, vector<int>& temp_xL)
{
	for(int i = 0; i < 199; i++)
	{
		if(yCoord == temp_yC[i] && xCoord == temp_xC[i])
		{
			printw("%s", desc[i].c_str());
			printw("\n\n");
			checkpoint(n, l, en, s, yCoord, xCoord);
		}
	}
}
