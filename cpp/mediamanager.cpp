#include "mediamanager.h"

using namespace std;

MultimediaPtr MediaManager::createPhoto(string _name, string _path, double _latitude, double _longitude){
    if(searchMedia(_name)){
        cerr << "Name is already in use. Try again with a different one." << endl;
    } else {
        multimediaDict[_name] = PhotoPtr (new Photo(_name, _path, _latitude, _longitude));
    }
    return multimediaDict[_name];
};

MultimediaPtr MediaManager::createVideo(string _name, string _path, int _duration){
    if(searchMedia(_name)){
        cerr << "Name is already in use. Try again with a different one." << endl;
    } else {
        multimediaDict[_name] = VideoPtr (new Video(_name, _path, _duration));
    }
    return multimediaDict[_name];
};

MultimediaPtr MediaManager::createFilm(string _name, string _path, int _duration, int* _chaptersLengths, unsigned int _numChapters){
    if(searchMedia(_name)){
        cerr << "Name is already in use. Try again with a different one." << endl;
    } else {
        multimediaDict[_name] = FilmPtr (new Film(_name, _path, _duration, _chaptersLengths, _numChapters));
    }
    return multimediaDict[_name];
};

GroupPtr MediaManager::createGroup(string _name){
    if(searchGroup(_name)){
        cerr << "Name is already in use. Try again with a different one." << endl;
    } else {
        groupDict[_name] = GroupPtr (new Group(_name));
    }
    return groupDict[_name];
};

MultimediaPtr MediaManager::searchMedia(string _name){
    if(multimediaDict.find(_name) == multimediaDict.end()){
        return nullptr;
    } else {
        return multimediaDict[_name];
    }
};

GroupPtr MediaManager::searchGroup(string _name){
    if(groupDict.find(_name) == groupDict.end()){
        return nullptr;
    } else {
        return groupDict[_name];
    }
};

void MediaManager::showMedia(string _name, ostream& stream){
    if(searchMedia(_name)){
        multimediaDict[_name]->writeToStream(stream);
    } else {
        stream << "There's no such object in the database. Check your spelling and try again.";
    }
};

void MediaManager::showGroup(string _name, ostream& stream){
    if(searchGroup(_name)){
        groupDict[_name]->writeToStream(stream);
    } else {
        stream << "There's no such group in the database. Check your spelling and try again.";
    }
};

void MediaManager::playMedia(string _name, ostream& stream){
    if(searchMedia(_name)){
        multimediaDict[_name]->playMedia();
    } else {
        stream << "There's no such media in the database. Check your spelling and try again.";
    }
};

void MediaManager::deleteMedia(string _name, ostream& stream){
    if(searchMedia(_name)){
        multimediaDict.erase(_name);
    } else {
        stream << "There's no such media in the database. Check your spelling and try again.";
    }
};

void MediaManager::deleteGroup(string _name, ostream& stream){
    if(searchGroup(_name)){
        groupDict.erase(_name);
    } else {
        stream << "There's no such group in the database. Check your spelling and try again.";
    }
};

bool MediaManager::processRequest(TCPConnection& cnx, const string& request, string& response){
  cerr << "\nRequest: '" << request << "'" << endl;

    // 1) pour decouper la requête:
    // on peut par exemple utiliser stringstream et getline()
    stringstream ss;
    ss << request;

    string cmd, arg;
    ss >> cmd >> arg;

    ss.str(string());
    ss.clear();

    // 2) faire le traitement:
    // - si le traitement modifie les donnees inclure: TCPLock lock(cnx, true);
    // - sinon juste: TCPLock lock(cnx);
    TCPLock lock(cnx);

    // 3) retourner la reponse au client:
    // - pour l'instant ca retourne juste OK suivi de la requête
    // - pour retourner quelque chose de plus utile on peut appeler la methode print()
    //   des objets ou des groupes en lui passant en argument un stringstream
    // - attention, la requête NE DOIT PAS contenir les caractères \n ou \r car
    //   ils servent à délimiter les messages entre le serveur et le client
    int status = 1;
    if(!cmd.compare("showMedia")){
        showMedia(arg, ss);
    } else if(!cmd.compare("showGroup")){
        showGroup(arg, ss);
    } else if(!cmd.compare("play")){
        playMedia(arg, ss);
    } else if(!cmd.compare("deleteMedia")){
        deleteMedia(arg, ss);
    } else if(!cmd.compare("deleteGroup")){
        deleteGroup(arg, ss);
    } else if(!cmd.compare("quit")){
        return false;
    } else{
        status = 0;
    }

    response = ss.str();

    if(!status){
        response = "This command isn't valid. Check your spell and try again. You can quit using the comand 'quit'.";
    }
    cerr << "response: " << response << endl;

    // renvoyer false si on veut clore la connexion avec le client
    return true;
}
