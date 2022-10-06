//
// Created by Emma Dringoli on 12/09/22.
//
#include <iostream>
#include <utility>
#include "Collection.h"
#include "IObserver.h"

using namespace std;

Collection::Collection(string name) {
    this->name=std::move(name);
}

void Collection::addObserver(IObserver* obs){
    observers.push_back(obs);
}

void Collection::removeObserver(IObserver* obs){
    observers.remove(obs);
}

void Collection::notify(){
    for(auto obs:observers ){
        obs->update(this);
    }
}

void Collection::addNote(Note *note) {
    notes.push_back(note);
    this->notify();
}

void Collection::removeNote(Note *note) {
    notes.remove(note);
    this->notify();
}

string Collection::getName() {
    return this->name;
}

void Collection::setName(string new_name) {
    this->name=std::move(new_name);
}

int Collection::getSize() {
    int count=0;
    for (auto note:notes){
        count++;
    }
    return count;
}

void Collection::show(){
    for(auto note:notes){
        note->print();
    }
}
