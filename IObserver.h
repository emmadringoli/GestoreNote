//
// Created by Dringoli Ghezzi on 13/09/22.
//

#ifndef GESTORE_NOTE_IOBSERVER_H
#define GESTORE_NOTE_IOBSERVER_H
#include "Collection.h"

class ISubject;
class Collection;

class IObserver{
public:
    virtual void update(Collection*)=0;
    virtual void attach(Collection*)=0;
    virtual void detach(Collection*)=0;
};
#endif //GESTORE_NOTE_IOBSERVER_H
