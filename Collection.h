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

class Collection : ISubject {
public:
    explicit Collection(string name = "Collection");

    ~Collection();

    //metodi ISubject
    void addObserver(IObserver *) override;

    void removeObserver(IObserver *) override;

    void notify() override;

    void addNote(shared_ptr<Note> note);

    bool removeNote(shared_ptr<Note> note);

    string getName() const;

    void setName(const string &new_name);

    int getSize() const;

    void show();

private:
    string name;
    list<shared_ptr<Note>> notes;
    list<IObserver *> observers;
};


#endif //GESTORE_NOTE_COLLECTION_H
