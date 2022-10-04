#ifndef PHOTO_H
#define PHOTO_H

using namespace std;

#include <iostream>
#include <string>
#include <memory>
#include "multimedia.h"

class Photo : public Multimedia
{
private:
    string name = "", path = "";
    double latitude = 0, longitude = 0;

public:
    // Constructors
    Photo(){};
    Photo(string _name, string _path, double _latitude, double _longitude)
    : Multimedia(_name, _path){
        latitude = _latitude;
        longitude = _longitude;
    };

    // Destructor
    ~Photo(){};

    // Setters
    void setLatitude(double _latitude){
        latitude = _latitude;
    }

    void setLongitude(double _longitude){
        longitude = _longitude;
    }

    // Getters
    double getLatitude() const{
        return latitude;
    }

    double getLongitude() const{
        return longitude;
    }

    // Method to write the data in a generic stream
    void writeToStream(ostream& stream) const override{
        Multimedia::writeToStream(stream);
        stream << "Latitude: " << getLatitude() << ", " << "Longitude: " << getLongitude() << ".";
    }

    // Method to play the media
    void playMedia() const override{
        string cmd = "mpv " + getPath() + " &";
        system(cmd.c_str());
    }
};

typedef shared_ptr<Photo> PhotoPtr;

#endif // PHOTO_H
