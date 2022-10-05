//
// Created by Dringoli Ghezzi on 30/09/22.
//

#include "gtest/gtest.h"
#include "../Collection.h"
#include "../Menu.h"

class GestoreNoteSuite: public ::testing::Test{
protected:
    void setUp() {
        note1->setTitle("Title");
        note1->setContent("Content");
        note2->setTitle("Title");
        note2->setContent("Content");
        note3->setTitle("Title");
        note3->setContent("Content");
        col->setName("Name");
        menu->addCollection(col);
        col->addNote(note1);
    }

    Menu* menu=new Menu();
    Collection* col=new Collection();
    Note* note1=new Note();
    Note* note2=new Note();
    Note* note3=new Note();
};

TEST_F(GestoreNoteSuite,Initialization){
    ASSERT_EQ(0,menu->getNumOfColl());
    ASSERT_EQ(0,col->getSize());
}

TEST_F(GestoreNoteSuite,AddRemoveOperations){
    menu->addCollection(col);
    col->addNote(note1);
    ASSERT_EQ(1,menu->getNumOfColl());
    ASSERT_EQ(1,col->getSize());
    col->addNote(note2);
    col->addNote(note3);
    ASSERT_EQ(3,col->getSize());
    col->removeNote(note3);
    ASSERT_EQ(2,col->getSize());
    menu->removeCollection(col);
    ASSERT_EQ(0, menu->getNumOfColl());
}

TEST_F(GestoreNoteSuite, Favorites){
    menu->addCollection(col);
    col->addNote(note1);
    col->addNote(note2);
    menu->addNoteToFav(note2);
    ASSERT_EQ(2,col->getSize());
    ASSERT_EQ(1,menu->getNumFavNote());
    menu->removeNoteFromFav(note2);
    ASSERT_EQ(0,menu->getNumFavNote());
}

TEST_F(GestoreNoteSuite, ObserverPattern){
    menu->addCollection(col);
    ASSERT_EQ(menu->getNumOfColl(),menu->viewer.getNumOfColl());
    col->addNote(note1);
    ASSERT_EQ(menu->getNumOfColl(),menu->viewer.getNumOfColl());
    col->removeNote(note1);
    ASSERT_EQ(menu->getNumOfColl(),menu->viewer.getNumOfColl());
}

TEST_F(GestoreNoteSuite, EditNote){
    menu->addCollection(col);
    col->addNote(note1);
    note1->block();
    ASSERT_EQ(1,note1->isBlocked());
    note1->setContent("New content");
    ASSERT_EQ("Nota",note1->getTitle());
    ASSERT_EQ("",note1->getContent());
    note1->unlock();
    note1->setContent("New content");
    ASSERT_EQ("New content",note1->getContent());

    col->addNote(note2);
    menu->lockNote(note2);
    ASSERT_EQ(1,note2->isBlocked());
    menu->editNote(note2,"New title","New content");
    ASSERT_EQ("Nota",note2->getTitle());
    ASSERT_EQ("",note2->getContent());
    menu->unlockNote(note2);
    menu->editNote(note2,"New title","New content");
    ASSERT_EQ("New title",note2->getTitle());
    ASSERT_EQ("New content",note2->getContent());
}