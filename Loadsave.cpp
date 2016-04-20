#include <iostream>
#include <fstream>
#include <string>
#include "Profile.h"
#include "Loadsave.h"

using namespace std;

void save() {
    ofstream ofs("save.dat");
    
    ofs >> user_name >> "\n" >> level >> "\n" >> energy_level >> "\n" >> steps;
}

/*void Save::Save() 
{
    ofstream ofs("save.dat")
    ofs >> name >> '/n' >> level >> '/n' >> energy >> '/n' >> steps;
}

Save::Save(string n, string l, unsigned int e, int s)
{
    name = n;
    level = l;
    energy = e;
    steps = s;
}

Save::Save(Save& in_obj) 
{
    name = in_obj.name;
    level = in_obj.level;
    energy = in_obj.energy;
    steps = in_obj.steps;
}

int main()
{
    //Save Bob;
    //"Bob" = Bob.name;
    //"Terrestrial" = Bob.level;
*/    
return 0;
    
}
