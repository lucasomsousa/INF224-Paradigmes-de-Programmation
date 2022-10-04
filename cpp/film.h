#ifndef FILM_H
#define FILM_H

#include "video.h"
#include <string>

using namespace std;

class Film : public Video
{
private:
    int* chaptersLengths = nullptr;
    unsigned int numChapters = 0;
    string name = "", path = "";
    int duration = 0;

public:
    // Constructors
    Film(){};
    Film(string _name, string _path, int _duration, int* _chaptersLengths, unsigned int _numChapters)
    : Video(_name, _path, _duration) {
        numChapters = _numChapters;
        chaptersLengths = new int[numChapters];
        for (unsigned int var = 0; var < numChapters; ++var) {
            chaptersLengths[var] = _chaptersLengths[var];
        }
    };

    // Destructor
    ~Film() {
        delete [] chaptersLengths;
        chaptersLengths = nullptr;
    }

    // Setters
    void setChaptersLengths(int* _chaptersLengths, int _numChapters);

    // Getters
    int* getChaptersLengths() const;
    unsigned int getNumChapters() const;

    void writeToStream(ostream& stream) const;

};

typedef shared_ptr<Film> FilmPtr;

#endif // FILM_H
