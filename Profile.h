#ifndef PROFILE_H
#define PROFILE_H

class Profile
{
    public:
        Profile();
        Profile(string, string, int, int);
        void display_info();

    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar& user_name;
            ar& level;
            ar& energy_level;
            ar& steps;
        }
        string user_name;
        string level;
        signed int energy_level;
        int steps;
};

#endif // PROFILE_H
