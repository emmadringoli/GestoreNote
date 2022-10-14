//
// Created by Emma Dringoli on 12/09/22.
//

#ifndef GESTORE_NOTE_NOTE_H
#define GESTORE_NOTE_NOTE_H
#include <string>

using namespace std;

class Note{
public:
    explicit Note(string title="Nota", string content="");

    void setTitle( const string& title);
    string getTitle() const;

    void setContent(const string& content );
    string getContent() const;

    void setSpecial();
    void setNotSpecial();
    bool isSpecial() const;                       //verifica se la nota è speciale

    void block();
    void unlock();
    bool isBlocked();                       //verifica se la nota è bloccata


    void print();

private:
    string title;
    string content;
    bool blocked=false;
    bool special=false;
};




#endif //GESTORE_NOTE_NOTE_H
