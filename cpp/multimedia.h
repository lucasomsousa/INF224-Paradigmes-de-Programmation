#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Multimedia
{
private:
    string name = "", path = "";

public:
    // Constructors (with and without arguments):
    Multimedia();
    Multimedia(string _name, string _path);

    // Destructor
    virtual ~Multimedia();

    // Setters
    void setName(string _name);
    void setPath(string _path);

    // Getters
    string getName() const;
    string getPath() const;

    // Method to write the data in a generic stream
    // Virtual, to be overrid by the children classes
    virtual void writeToStream(ostream& stream) const;

    // Method to play a media (derived by the children classes)
    virtual void playMedia() const = 0;
};

typedef shared_ptr<Multimedia> MultimediaPtr;

#endif // MULTIMEDIA_H
