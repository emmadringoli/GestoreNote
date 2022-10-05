//
// Created by Emma Dringoli on 12/09/22.
//

#ifndef GESTORE_NOTE_NOTE_H
#define GESTORE_NOTE_NOTE_H
#include <string>

using namespace std;

class Note{
public:
    Note(string title="Nota", string content="");
    ~Note();

    // Getter e Setter

    void setTitle(string title);            //Per aggiungere/modificare il titolo
    string getTitle();                      //Per ottenere il titolo

    void setContent(string content );       //Per aggiungere/modificare il contenuto
    string getContent();                    //Per ottenere il contenuto

    void setSpecial();                      //Per rendere la nota speciale
    void setNotSpecial();
    bool isSpecial();                       //Per verificare se la nota è speciale

    void block();                           //Per bloccare la nota
    void unlock();
    bool isBlocked();                       //Per verificare se la nota è bloccata


    void print();                           //Per stampare la nota

private:
    string title;
    string content;
    bool blocked=false;
    bool special=false;
};




#endif //GESTORE_NOTE_NOTE_H
