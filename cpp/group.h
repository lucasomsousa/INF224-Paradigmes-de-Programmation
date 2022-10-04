#ifndef GROUP_H
#define GROUP_H

#include "multimedia.h"
#include <string>
#include <list>
#include <memory>

using namespace std;

class Group : public list<MultimediaPtr>
{
private:
    string name = "";
    unsigned int numElements = 0;

public:
    // Constructors
    Group(){};
    Group(string _name){
        name = _name;
    };

    // Destructors
    ~Group(){};

    // Getter
    string getName() const;

    // Method to exhibit elements of the group
    void writeToStream(ostream& stream) const;
};

typedef shared_ptr<Group> GroupPtr;

#endif // GROUP_H
