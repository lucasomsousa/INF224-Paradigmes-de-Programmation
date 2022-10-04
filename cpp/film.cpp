#include "film.h"
#include <iostream>

using namespace std;

int* Film::getChaptersLengths() const{
    return chaptersLengths;
};

unsigned int Film::getNumChapters() const{
    return numChapters;
};

void Film::setChaptersLengths(int* _chaptersLengths, int _numChapters){
    delete chaptersLengths;

    numChapters = _numChapters;
    chaptersLengths = new int[numChapters];

    for (unsigned int var = 0; var < numChapters; ++var) {
        chaptersLengths[var] = _chaptersLengths[var];
    }
};

void Film::writeToStream(ostream& stream) const{
    Video::writeToStream(stream);
    for (unsigned int var = 0; var < numChapters; ++var){
        stream << "Chapter " << var << ": " << "duration = " << chaptersLengths[var] << ".";
    }
};
