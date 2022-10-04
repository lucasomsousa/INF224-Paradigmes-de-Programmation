#include "multimedia.h"

using namespace std;

Multimedia::Multimedia(){}

Multimedia::Multimedia(string _name, string _path){
    name = _name;
    path = _path;
}

Multimedia::~Multimedia(){}

void Multimedia::setName(string _name){
    name = _name;
}

void Multimedia::setPath(string _path){
    path = _path;
}

string Multimedia::getName() const{
    return name;
}

string Multimedia::getPath() const{
    return path;
}

void Multimedia::writeToStream(ostream& stream) const{
    stream << name << ", " << path << ". ";
}
