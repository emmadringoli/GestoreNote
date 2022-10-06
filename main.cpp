#include <iostream>
#include "Note.h"
#include "Collection.h"
#include "Menu.h"


using namespace std;

int main(){
    Menu menu;
    Collection film;
    Note avatar("Avatar","Year: 2009\nGenre: sci-fi");
    Note forrest("Forrest Gump","Year: 1994\nGenre: drama,comedy");
    film.addNote(&avatar);
    film.addNote(&forrest);
    cout<<"\nCollection 'film':\n";
    film.show();
    cout<<"The collection 'film' has "<<film.getSize()<<" elements\n\n";


    Collection songs;
    Note penny("Penny Lane","Year: 1967\nArtist: The Beatles");
    Note love("Love Of My Life","Year: 1975\nArtist: Queen");
    songs.addNote(&penny);
    songs.addNote(&love);
    menu.addNoteToFav(&penny);
    menu.addNoteToFav(&forrest);
    menu.showFavorite();

    menu.lockNote(&avatar);
    menu.editNote(&avatar,"new_title","new_content");   //la nota non verrà modificata
    cout<<"\n";
    avatar.print();
    menu.unlockNote(&avatar);
    menu.editNote(&avatar,"new_title","new content");   //la nota verrà modificata
    cout<<"\n";
    avatar.print();

    menu.removeNoteFromFav(&penny);
    menu.showFavorite();


    return 0;
};
