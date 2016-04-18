#IFNDEF 'Loadsave.h'
#DEFINE 'Loadsave.h'

  class Save {
    private:
      char name[20];
      string level;
      unsigned int energy;
      int steps;
    public:
      Save();
      Save(string n, string l, unsigned int e, int s);
      Save(Save& in_obj);
  }

#ENDIF
