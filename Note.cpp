//
// Created by Emma Dringoli on 12/09/22.
//

#include <iostream>
#include "Note.h"


using namespace std;

Note::Note(string title, string content){
    this->title=std::move(title);
    this->content=std::move(content);
}

void Note::setTitle(const string& new_title){
    if (isBlocked()) {
        cout << "The note is blocked\n";
    } else {
        title = new_title;
    }
}

string Note::getTitle() const {return title;}

void Note::setContent(const string& new_content){
    if (!blocked) {
        content = new_content;
    } else { cout << "The note is blocked!\n"; }
}

string Note::getContent() const {return content;};

void Note::setSpecial(){
    special=true;
}

void Note::setNotSpecial() {
    special=false;
}

bool Note::isSpecial() const{
    return special;
}

void Note::block() {
    this->blocked=true;
}

void Note::unlock() {
    this->blocked=false;
}

bool Note::isBlocked(){
    return blocked;
}


void Note::print(){
    cout<<"-- "<<title<<" --\n";
    cout<<content<<"\n";
    cout<<"--The End --\n\n";
}