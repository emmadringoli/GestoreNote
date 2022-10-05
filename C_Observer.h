//
// Created by Dringoli Ghezzi on 13/09/22.
//

#ifndef GESTORE_NOTE_C_OBSERVER_H
#define GESTORE_NOTE_C_OBSERVER_H
#include <iostream>
#include <string>
#include <list>
#include <map>
#include "Collection.h"

using namespace std;





class C_Observer: public IObserver{

public:

    void update(Collection*) override;
    void attach(Collection*) override;
    void detach(Collection*) override;
    int getNumOfColl();

private:
    map<string,int> info;
};





#endif //GESTORE_NOTE_C_OBSERVER_H
