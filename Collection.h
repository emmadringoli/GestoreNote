//
// Created by Emma Dringoli on 12/09/22.
//

#ifndef GESTORE_NOTE_COLLECTION_H
#define GESTORE_NOTE_COLLECTION_H
#include <iostream>
#include <list>
#include<string>
#include "Note.h"
#include "IObserver.h"
#include "ISubject.h"



using namespace std;

class Collection: ISubject{
public:
    Collection(string name="Collection");

    //metodi ISubject
    void addObserver(IObserver*) override;
    void removeObserver(IObserver*) override;
    void notify() override;

    void addNote(Note* note);
    void removeNote(Note* note);

    string getName();
    void setName(string new_name);

    int getSize();

    void show();

private:
    string name;
    list<Note*> notes;
    list<IObserver*> observers;
};



#endif //GESTORE_NOTE_COLLECTION_H
