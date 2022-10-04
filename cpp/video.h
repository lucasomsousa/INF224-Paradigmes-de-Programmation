#ifndef VIDEO_H
#define VIDEO_H

using namespace std;

#include <iostream>
#include <string>
#include <memory>
#include "multimedia.h"

class Video : public Multimedia
{
private:
    string name = "", path = "";
    int duration = 0;

public:
    // Constructors
    Video(){};
    Video(string _name, string _path, int _duration)
    : Multimedia(_name, _path){
        duration = _duration;
    };

    // Destructor
    ~Video(){};

    // Setter
    void setDuration(int _duration){
        duration = _duration;
    }


    // Getters
    double getDuration() const{
        return duration;
    }

    // Method to write the data in a generic stream
    void writeToStream(ostream& stream) const override{
        Multimedia::writeToStream(stream);
        stream << "Duration: " << getDuration() << ".";
    }

    // Method to play the media
    void playMedia() const override{
        string cmd = "mpv " + getPath() + " &";
        system(cmd.c_str());
    }
};

typedef shared_ptr<Video> VideoPtr;

#endif // VIDEO_H
