//
// Created by Emma Dringoli on 13/09/22.
//

#ifndef GESTORE_NOTE_MENU_H
#define GESTORE_NOTE_MENU_H
#include <iostream>
#include <vector>
#include "Collection.h"
#include "C_Observer.h"

using namespace std;

class Menu{
public:
    C_Observer viewer;

    Menu();
    ~Menu();

    //operazioni sulle collezioni
     void addCollection(Collection* col);
     void removeCollection(Collection*);
     void showListOfCollection();
     int getNumOfColl();

     //operazioni sulla collezione "favorites"
     void removeNoteFromFav(shared_ptr<Note>);
     void addNoteToFav(shared_ptr<Note>);
     int getNumFavNote();
     void showFavorite();

     //operazioni sulle note
     void editNote(shared_ptr<Note> nt, string name, string text);
     void lockNote(shared_ptr<Note> nt);
     void unlockNote(shared_ptr<Note> nt);
     void addNoteToColl(shared_ptr<Note> nt, Collection* col);
     void removeNoteFromColl(shared_ptr<Note> nt, Collection* col);
     int getNumOfNote();
     void showCollectionNote(Collection* col);

private:
    int nNotes=0;
    vector<Collection*> collections;
    Collection fav=Collection("favorites");

};



#endif //GESTORE_NOTE_MENU_H
