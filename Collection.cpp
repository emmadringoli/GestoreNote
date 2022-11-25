//
// Created by Emma Dringoli on 12/09/22.
//
#include <iostream>
#include <utility>
#include "Collection.h"
#include "IObserver.h"

using namespace std;

Collection::Collection(string name) {
    this->name = std::move(name);
}

Collection::~Collection() {
    for (auto n :notes) {
        n.reset();
    }
    for (auto o :observers) {
        o->detach(this);
    }

}

void Collection::addObserver(IObserver *obs) {
    observers.push_back(obs);
}

void Collection::removeObserver(IObserver *obs) {
    observers.remove(obs);
}

void Collection::notify() {
    for (auto obs:observers) {
        obs->update(this);
    }
}

void Collection::addNote(shared_ptr<Note> note) {
    notes.push_front(note);
    this->notify();
}

bool Collection::removeNote(shared_ptr<Note> note) {
    if (note->isBlocked()) {
        return false;
    }
    if (searchNote(note)) {
        notes.remove(note);
        this->notify();
        return true;
    } else {
        cout << "The note can't be removed because is not present!\n";
        return false;
    }

}

string Collection::getName() const {
    return this->name;
}

void Collection::setName(const string &new_name) {
    this->name = new_name;
}

int Collection::getSize() const {
    int count = 0;
    for (auto note:notes) {
        count++;
    }
    return count;
}

void Collection::show() {
    for (auto note:notes) {
        note->print();
    }
}

int Collection::getFavSize() const {
    int count = 0;
    for (auto note:notes) {
        if (note->isSpecial()) {
            count++;
        }
    }
    cout << "The collection has: " << count << " favorite notes\n";
    return count;
}

bool Collection::searchNote(shared_ptr<Note> nt) {
    for (auto note:notes) {
        if (note->getTitle() == nt->getTitle()) {
            cout << "The note is present in the collection\n";
            return true;
        }
    }
    cout << "The note is not present in the collection\n";
    return false;
}
