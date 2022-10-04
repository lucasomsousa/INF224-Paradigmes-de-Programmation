//
// main.cpp
// The main use of this file is for testing during the project
// The tests made are commented in order for it to be visible
// to the teachers who'll evaluate the project

#include <iostream>
#include <memory>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "mediamanager.h"
#include "tcpserver.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

int main(int argc, char* argv[]){

    // cree le TCPServer
    shared_ptr<TCPServer> server(new TCPServer());

    // cree l'objet qui gère les données
    MediaManagerPtr manager(new MediaManager());

    /*
    // cree les objets:
    MultimediaPtr photo (manager->createPhoto("Howl_picture", "/home/lucas/Pictures/howlEu.jpeg", 78.9, 0.03));
    MultimediaPtr video (manager->createVideo("Howl_video", "/home/lucas/Pictures/howlTtk.jpeg", 40));
    int chaptersDurations [5] = {10, 36, 20, 38, 17};
    MultimediaPtr film (manager->createFilm("Howls_moving_castle", "/home/lucas/Pictures/howl.jpg", 121, chaptersDurations, 5));
    GroupPtr group (manager->createGroup("Ghibli_movies"));

    group->push_back(photo);
    group->push_back(video);
    group->push_back(film);
    */

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*manager, &MediaManager::processRequest);

    // lance la boucle infinie du serveur
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
      cerr << "Could not start Server on port " << PORT << endl;
      return 1;
    }

    return 0;
}


// Below is the "main" file used for testing throughout
// the development of this project.

//int main(int argc, const char* argv[]){
    // Question 3
    /*
    Multimedia *withArguments = new Multimedia("Beautiful image", "images/myCat.jpg");
    Multimedia *withoutArguments = new Multimedia();

    cout << "Testing getters:" << endl;
    cout << withArguments->getName() << endl;
    cout << withArguments->getPath() <<endl;

    cout << "Testing setters:" << endl;
    withoutArguments->setName("Another beautiful image");
    withoutArguments->setPath("images/anotherCat.jpg");
    cout << withoutArguments->getName() << endl;
    cout << withoutArguments->getPath() << endl;

    cout << "Testing stream write method" << endl;
    withArguments->writeToStream(cout);
    */

    // Question 4
    /*
    Photo *photo = new Photo("Howl picture", "/home/lucas/Pictures/howlEu.jpeg", 78.9, 0.03);
    Video *video = new Video("Howl video", "/home/lucas/Pictures/howlTtk.jpeg", 40);

    cout << "Testing photo variables exhibition" << endl;
    photo->writeToStream(cout);

    cout << "Testing video variables exhibition" << endl;
    video->writeToStream(cout);

    cout << "Testing media play method" << endl;
    photo->playMedia();
    video->playMedia();
    */



    // Question 5
    /*
    Multimedia** media = new Multimedia*[2];

    media[0] = new Photo("Howl picture", "/home/lucas/Pictures/howlEu.jpeg", 78.9, 0.03);
    media[1] = new Video("Howl video", "/home/lucas/Pictures/howlTtk.jpeg", 40);

    for (int var = 0; var < 2; ++var) {
        media[var]->playMedia();
,    }
    */



    // Questions 6 et 7
    /*
    int chaptersDurations [5] = {10, 36, 20, 38, 17};

    Film* film = new Film("Howl's moving castle", "/home/lucas/Pictures/howl.jpeg", 121, chaptersDurations, 5);

    film->writeToStream(cout);

    cout << "Deleting film..." << endl;
    delete film;
    cout << "Film deleted." << endl;

    film->writeToStream(cout);
    */



    // Questions 8
    /*
    Photo *photo = new Photo("Howl picture", "/home/lucas/Pictures/howlEu.jpeg", 78.9, 0.03);
    Video *video = new Video("Howl video", "/home/lucas/Pictures/howlTtk.jpeg", 40);

    int chaptersDurations [5] = {10, 36, 20, 38, 17};
    Film *film = film = new Film("Howl's moving castle", "/home/lucas/Pictures/howl.jpeg", 121, chaptersDurations, 5);

    Group *group1 = new Group("Ghibli movies");
    group1->push_back(photo);
    group1->push_back(video);
    group1->push_back(film);

    Group *group2 = new Group("Second howl group movies");
    group2->push_back(photo);
    group2->push_back(video);

    group1->writeToStream(cout);

    delete group1;

    group2->writeToStream(cout);

    delete group2;
    */



    // Question 9
    /*
    PhotoPtr photo (new Photo("Howl picture", "/home/lucas/Pictures/howlEu.jpeg", 78.9, 0.03));
    VideoPtr video (new Video("Howl video", "/home/lucas/Pictures/howlTtk.jpeg", 40));

    int chaptersDurations [5] = {10, 36, 20, 38, 17};
    FilmPtr film (new Film("Howl's moving castle", "/home/lucas/Pictures/howl.jpeg", 121, chaptersDurations, 5));

    GroupPtr group1 (new Group("Ghibli movies"));
    group1->push_back(photo);
    group1->push_back(video);
    group1->push_back(film);

    GroupPtr group2 (new Group("Second howl group movies"));
    group2->push_back(photo);
    group2->push_back(video);

    group1->writeToStream(cout);
    group2->writeToStream(cout);

    cout << "Now let's reset the group 2 pointer, which will bring the counter to zero" << endl;
    group2.reset();

    cout << "Group 1, use count = " << group1.use_count() << endl;
    cout << "Group 2, use count = " << group2.use_count() << endl;
    */



    // Question 10
    /*
    MediaManagerPtr manager(new MediaManager());

    MultimediaPtr photo (manager->createPhoto("Howl picture", "/home/lucas/Pictures/howlEu.jpeg", 78.9, 0.03));
    MultimediaPtr video (manager->createVideo("Howl video", "/home/lucas/Pictures/howlTtk.jpeg", 40));
    int chaptersDurations [5] = {10, 36, 20, 38, 17};
    MultimediaPtr film (manager->createFilm("Howl's moving castle", "/home/lucas/Pictures/howl.jpeg", 121, chaptersDurations, 5));
    GroupPtr group (manager->createGroup("Ghibli movies"));

    group->push_back(photo);
    group->push_back(video);
    group->push_back(film);

    cout << "Testing showMedia method" << endl;
    manager->showMedia("Howl picture", cout);
    cout << endl;

    cout << "Testing again with a wrong name" << endl;
    manager->showMedia("Howl photo", cout);
    cout << endl;

    cout << "Testing showGroup method" << endl;
    manager->showGroup("Ghibli movies", cout);
    cout << endl;

    cout << "Testing playMedia method" << endl;
    manager->playMedia("Howl picture");
    cout << endl;

    cout << "Testing deleteMedia method" << endl;
    manager->deleteMedia("Howl picture");
    cout << endl;

    cout << "Now we'll try to access the picture we've just deleted" << endl;
    manager->showMedia("Howl picture", cout);
    cout << endl;
    */

    //return 0;
//}
