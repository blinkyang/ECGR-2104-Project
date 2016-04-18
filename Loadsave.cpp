#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Save {
    private:
        char name[20];
        string lvl;
        unsigned int enrgy;
        int steps;
    public:
        Save();
        Save(char& n, string level, unsigned int energy, int steps);
        
};

Save::Save() {
    name = 'Unknown';
    lvl = "Terrestrial";
    enrgy = 15;
    steps = 0;
}

Save::Save(char& n, string level, unsigned int energy, int s) {
    name = n;
    lvl = level;
    enrgy = energy;
    steps = s;
}


int main () {

    Save Bob;
    Bob(Bob, "Terrestrial", 10, 7 );
    
    ofstream ofs("save.dat", ios::binary);
    
    ofs.write((char *)&Bob, sizeof(one));
    
    ifstream ifs("save.dat", ios::binary);

return 0;
}
