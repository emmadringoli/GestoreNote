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
    fav.notify();
}

Menu::~Menu() {
    for (auto itr :collections) {
        delete itr;
    }
}

void Menu::addCollection(Collection *col) {
    collections.push_back(col);
    col->addObserver(&viewer);
    col->notify();
}

void Menu::removeCollection(Collection *col) {
    for (int i = 0; i < collections.size(); i++) {
        if (collections[i]->getName() == col->getName()) {
            collections.erase(collections.begin() + i);
        }
    }
    col->notify();
}

void Menu::showListOfCollection() {
    cout << "List of Collections:\n";
    for (int i = 0; i < collections.size(); i++) {
        collections[i]->show();
    }
    cout << "END List of Collections\n\n";
}

int Menu::getNumOfColl() const {
    return collections.size();
}

void Menu::removeNoteFromFav(shared_ptr<Note> nt) {
    fav.removeNote(nt);
    nt->setNotSpecial();
}

void Menu::addNoteToFav(shared_ptr<Note> nt) {
    fav.addNote(nt);
    nt->setSpecial();
}

int Menu::getNumFavNote() const {
    return fav.getSize();
}

void Menu::showFavorite() {
    cout << "Favorite Notes:\n\n";
    fav.show();
    cout << "END Favorite Notes\n";
}

void Menu::editNote(shared_ptr<Note> nt, const string& name, const string& text) {
    if (!nt->isBlocked()) {
        nt->setTitle(std::move(name));
        nt->setContent(std::move(text));
    } else { cout << "\nThe note is blocked!\n"; }
}

void Menu::lockNote(shared_ptr<Note> nt) {
    nt->block();
}

void Menu::unlockNote(shared_ptr<Note> nt) {
    nt->unlock();
}

void Menu::addNoteToColl(shared_ptr<Note> nt, Collection *col) {
    col->addNote(nt);
}

void Menu::removeNoteFromColl(shared_ptr<Note> nt, Collection *col) {
    col->removeNote(nt);
}

int Menu::getNumOfNote() const {
    int count = 0;
    for (int i = 0; i < collections.size(); i++) {
        count += collections[i]->getSize();
    }
    return count;
}

void Menu::showCollectionNote(Collection *col) {
    cout << "Collection '" << col->getName() << "' :\n\n";
    col->show();
    cout << "END Collection\n\n";
}