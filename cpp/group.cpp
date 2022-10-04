#include "group.h"

using namespace std;

string Group::getName() const{
    return name;
};

void Group::writeToStream(ostream& stream) const{
    stream << "Group " << getName() << ".  Elements:";
    for (auto& it: *this){
        it->writeToStream(stream);
    }
};
