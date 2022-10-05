//
// Created by Dringoli Ghezzi on 13/09/22.
//
#include <iostream>
#include "C_Observer.h"

void C_Observer::update(Collection* col) {
    bool exist=false;
    map<string,int>::iterator itr;
    for(itr = info.begin(); itr != info.end(); ++itr){
        cout<<"Update\n\n";
        cout<<itr->first<<"\n";
        if(itr->first==col->getName()){

            itr->second=col->getSize();
            exist=true;
            cout<<"Collection:  UPDATED\n";
        }
    }
    if(!exist){
        info.insert(pair<string,int>(col->getName(),col->getSize()));
        cout<<"Collection: ADDED\n";
    }
}

void C_Observer::attach(Collection* col) {
    col->addObserver(this);
}

void C_Observer::detach(Collection * col) {
    col->removeObserver(this);
}

int C_Observer::getNumOfColl() {
    return info.size();
}




