#include <iostream>

using namespace std;

struct Profile
{
    string name = "";
    string state = "";
    Profile* prevNodePtr = NULL;	// Pointer to the prev node
    Profile* nextNodePtr = NULL;	// Pointer to the next node

    Profile()
    {
        this->name = "";
        this->state = "";
        this->prevNodePtr = NULL;
        this->nextNodePtr = NULL;
    }

    Profile(string name, string state)
    {
        this->name = name;
        this->state = state;
        this->prevNodePtr = NULL;
        this->nextNodePtr = NULL;
    }

    Profile* getNextPtr()
    {
        return nextNodePtr;
    }

    friend ostream& operator <<(ostream& out, const Profile& profile)
    {
        out << profile.name << " " << profile.state;

        return out;
    }

    friend istream& operator >>(istream& in, Profile& profile)
    {
        string name;
        string state;

        in >> name;
        profile.name = name;

        in >> state;
        profile.state = state;

        return in;
    }
};