#ifndef PROFILE_H
#define PROFILE_H

namespace boost {
namespace serialization{
class access;
}    
}

class Profile
{
    public:
        Profile();
        Profile(string, string, int, int);
        void display_info();

    private:
        string user_name;
        string level;
        signed int energy_level;
        int steps;
        
        friend class boost::serialization::access;
        
        template<typename Archive>
        
        void serialize(Archive& ar, const unsigned version) {
            ar & user_name & level & energy_level;
        }
        }
};

#endif // PROFILE_H
