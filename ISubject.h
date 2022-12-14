//
// Created by Emma Dringoli on 13/09/22.
//

#ifndef GESTORE_NOTE_ISUBJECT_H
#define GESTORE_NOTE_ISUBJECT_H

#include <vector>
#include "Collection.h"

using namespace std;

class IObserver;

class Collection;

class ISubject {
public:
    virtual ~ISubject() {};

    virtual void addObserver(IObserver *) = 0;

    virtual void removeObserver(IObserver *) = 0;

    virtual void notify() = 0;

private:
    vector<IObserver *> observers;
};


#endif //GESTORE_NOTE_ISUBJECT_H
