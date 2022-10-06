//
// Created by Emma Dringoli on 13/09/22.
//
#include <iostream>
#include <string>
#include <utility>
#include "Menu.h"
#include "Collection.h"

using namespace std;

Menu::Menu() {
    fav.addObserver(&viewer);
    addCollection(&fav);
}

void Menu::addCollection(Collection* col){
    collections.push_back(col);
    col->addObserver(&viewer);
    col->notify();
}

void Menu::removeCollection(Collection* col){
    for(int i=0; i<collections.size(); i++){
        if(collections[i]->getName()==col->getName()){ //OR if(collection[i]==col)   CHECK!!!
            collections.erase(collections.begin()+i);
        }
    }
    col->notify();
}

void Menu::showListOfCollection(){
    cout<<"List of Collections:\n";
    for(int i=0; i<collections.size(); i++){
        collections[i]->show();
    }
    cout<<"END List of Collections\n\n";
}

int Menu::getNumOfColl(){
    return collections.size();
}

void Menu::addNoteToFav(Note* nt){
    fav.addNote(nt);
    nt->setSpecial();
}

void Menu::removeNoteFromFav(Note* nt){
    fav.removeNote(nt);
    nt->setNotSpecial();
}

int Menu::getNumFavNote(){
    return fav.getSize();
}

void Menu::showFavorite(){
    cout<<"Favorite Notes:\n\n";
    fav.show();
    cout<<"END Favorite Notes\n";
}

void Menu::editNote(Note* nt, string name, string text){
    if(!nt->isBlocked()){
        nt->setTitle(std::move(name));
        nt->setContent(std::move(text));
    }else{cout<<"\nThe note is blocked!\n";}
}

void Menu::lockNote(Note* nt){
    nt->block();
}

void Menu::unlockNote(Note* nt){
    nt->unlock();
}

void Menu::addNoteToColl(Note* nt, Collection* col){
    col->addNote(nt);
}

void Menu::removeNoteFromColl(Note* nt, Collection* col){
    col->removeNote(nt);
}

int Menu::getNumOfNote(){
    int count=0;
    for(int i=0; i<collections.size(); i++){
        count+=collections[i]->getSize();
    }
    return count;
}

void Menu::showCollectionNote(Collection* col){
    cout<<"Collection '"<<col->getName()<<"' :\n\n";
    col->show();
    cout<<"END Collection\n\n";
}