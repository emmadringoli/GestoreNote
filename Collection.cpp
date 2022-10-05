//
// Created by Dringoli Ghezzi on 12/09/22.
//
#include <iostream>
#include "Collection.h"
#include "IObserver.h"

using namespace std;

Collection::Collection(string name) {
    this->name=name;
}

Collection::~Collection() {
    //cout<<"Collection: "<<"'"<<this->name<<"'"<<" has been deleted\n";
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
        cout<<"Notify\n\n";
    }
}

void Collection::addNote(Note *note) {
    note_list.push_back(note);
    this->notify();
}

void Collection::removeNote(Note *note) {
    note_list.remove(note);
    this->notify();
}



string Collection::getName() {
    return this->name;
}

void Collection::setName(string new_name) {
    this->name=new_name;
}

int Collection::getSize() {
    int count=0;
    for (auto note:note_list){
        count++;
    }
    return count;
}

void Collection::show(){
    for(auto note:note_list){
        note->print();
    }
}
