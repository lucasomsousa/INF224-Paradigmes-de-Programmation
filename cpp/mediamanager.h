#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;
typedef map<string, MultimediaPtr> MultimediaDict;
typedef map<string, GroupPtr> GroupDict;

class MediaManager
{
private:
    MultimediaDict multimediaDict;
    GroupDict groupDict;

public:
    //ructors
    MediaManager(){};

    // Destructor
    ~MediaManager(){};

    // Media creation methods
    MultimediaPtr createPhoto(string _name, string _path, double _latitude, double _longitude);
    MultimediaPtr createVideo(string _name, string _path, int _duration);
    MultimediaPtr createFilm(string _name, string _path, int _duration, int* _chaptersLengths, unsigned int _numChapters);
    GroupPtr createGroup(string _name);

    // Media and group finding methods
    MultimediaPtr searchMedia(string _name);
    GroupPtr searchGroup(string _name);

    // Media and group exhibition methods
    void showMedia(string _name, ostream& stream);
    void showGroup(string _name, ostream& stream);

    // Media playing method
    void playMedia(string _name, ostream& stream);

    // It's not said in the TP description that we should create a method to
    // delete medias, but it is said that we're going to need the map::erase()
    // method, so I'm assuming that a delete media method is indeed necessary.
    void deleteMedia(string _name, ostream& stream);
    void deleteGroup(string _name, ostream& stream);

    // Method for Client/Server request processing
    bool processRequest(TCPConnection& cnx, const string& request, string& response);
};

typedef shared_ptr<MediaManager> MediaManagerPtr;

#endif // MEDIAMANAGER_H
