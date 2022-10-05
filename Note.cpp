//
// Created by Emma Dringoli on 12/09/22.
//

#include <iostream>
#include "Note.h"


using namespace std;

Note::Note(string title, string content){
    this->title=title;
    this->content=content;
}
Note::~Note(){}

void Note::setTitle(string new_title){
    if(blocked==false){
    title=new_title;
    }else{
        cout<<"The note is blocked\n";
    }
}
string Note::getTitle() {return title;};
void Note::setContent(string new_content){
    if (blocked == false) {
        content = new_content;
    } else { cout << "The note is blocked!\n"; }
}
string Note::getContent(){return content;};

void Note::setSpecial(){
    special=true;
}

void Note::setNotSpecial() {
    special=false;
}

bool Note::isSpecial(){
    if(special==true){
        cout<<"IS SPECIAL BABY!\n";
    }else{ cout<<"Sorry, not special\n";}
}

void Note::block() {
    blocked=true;
    cout<<"Now the note is blocked!\n";
}

void Note::unlock() {
    this->blocked=0;
}

bool Note::isBlocked(){
    if(blocked==false){
        //cout<<"The note is NOT blocked!\n";
        return false;
    }else {
        //cout<<"The note is blocked!\n";
        return true;
    }

}

void Note::print(){
    cout<<"--"<<title<<"--\n";
    cout<<content<<"\n";
    cout<<"--The End--\n\n";
}