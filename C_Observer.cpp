//
// Created by Emma Dringoli on 13/09/22.
//
#include <iostream>
#include "C_Observer.h"

void C_Observer::update(Collection *col) {
    bool exist = false;
    map<string, int>::iterator itr;
    for (itr = info.begin(); itr != info.end(); ++itr) {
        if (itr->first == col->getName()) {
            itr->second = col->getSize();
            exist = true;
            //cout<<"Update: The collection ' "<<col->getName()<<" ' has "<<col->getSize()<<" now!\n";
        }
    }
    if (!exist) {
        info.insert(pair<string, int>(col->getName(), col->getSize()));
    }
}


void C_Observer::attach(Collection *col) {
    col->addObserver(this);
    update(col);
}

void C_Observer::detach(Collection *col) {
    map<string, int>::iterator itr;
    for (itr = info.begin(); itr != info.end(); ++itr) {
        if (itr->first == col->getName()) {
            info.erase(itr);
        }
    }
    col->removeObserver(this);

}

int C_Observer::getNumOfColl() const {
    return info.size();
}




