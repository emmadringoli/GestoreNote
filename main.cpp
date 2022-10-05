#include <iostream>
#include <string>
#include <list>
#include "Note.h"
#include "Collection.h"
#include "Menu.h"


using namespace std;

int main(){
    Menu menu;
  /*  C_Observer firstObserver;
    Collection film;
    film.addObserver(&firstObserver);
    Note avatar("Avatar","Anno:2009\nGenere:fantascienza");
    Note forrest("Forrest Gump","Anno:1994\nGenere:drammatico/commedia");
    film.addNote(&avatar);
    film.addNote(&forrest);
    film.show();
    cout<<film.getSize()<<"\n\n";
    film.notify();

    Collection canzoni;
    Note penny("Penny Lane","Anno:1967\nArtista:The Beatles");
    Note love("Love Of My Life","Anno:1975\nArtista:Queen");
    canzoni.addNote(&penny);
    canzoni.addNote(&love);
    menu.addNoteToFav(&penny);
    menu.addNoteToFav(&forrest);
    film.removeNote(&forrest);
    menu.showFavorite();
    film.notify();   */

    Collection collezione1;
    menu.addCollection(&collezione1);
    cout<<"Menu:  "<<menu.getNumOfColl()<<"\n";
    cout<<"Viewer:  "<<menu.viewer.getNumOfColl()<<"\n";








    return 0;
};
