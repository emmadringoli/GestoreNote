//
// Created by Dringoli Ghezzi on 13/09/22.
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
    ~Menu(){};



    //operazioni sulle collezioni
     void addCollection(Collection* col);
     void removeCollection(Collection*);
     void showListOfCollection();
     int getNumOfColl();
     //operazioni sulla collezione "preferiti"
     void removeNoteFromFav(Note*);
     void addNoteToFav(Note*);
     int getNumFavNote();
     void showFavorite();
     //operazioni sulle note
     void editNote(Note* nt, string name, string text);
     void lockNote(Note* nt);
     void unlockNote(Note* nt);
     void addNoteToColl(Note* nt, Collection* col);
     void removeNoteFromColl(Note* nt, Collection* col);
     int getNumOfNote();
     void showCollectionNote(Collection* col);
private:
    int nNotes=0;                           //numero totale di note
    vector<Collection*> collections;
    Collection fav=Collection("favorites");

};



#endif //GESTORE_NOTE_MENU_H
