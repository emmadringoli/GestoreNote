//
// Created by Emma Dringoli on 30/09/22.
//

#include "gtest/gtest.h"
#include "../Collection.h"
#include "../Menu.h"

class GestoreNoteSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        note1->setTitle("Title");
        note1->setContent("Content");
        note2->setTitle("Title");
        note2->setContent("Content");
        note3->setTitle("Title");
        note3->setContent("Content");
        col->setName("Name");
    }

    Menu *menu = new Menu();
    Collection *col = new Collection();
    shared_ptr<Note> note1 = make_shared<Note>();
    shared_ptr<Note> note2 = make_shared<Note>();
    shared_ptr<Note> note3 = make_shared<Note>();
};

TEST_F(GestoreNoteSuite, Initialization) {
    ASSERT_EQ(1, menu->getNumOfColl());
    ASSERT_EQ(0, menu->getNumOfNote());
    ASSERT_EQ(0, menu->getNumFavNote());
    ASSERT_EQ(0, col->getSize());
}

TEST_F(GestoreNoteSuite, AddRemoveOperations) {
    menu->addCollection(col);
    col->addNote(note1);
    ASSERT_EQ(2, menu->getNumOfColl());
    ASSERT_EQ(1, col->getSize());
    col->addNote(note2);
    col->addNote(note3);
    ASSERT_EQ(3, col->getSize());
    col->removeNote(note3);
    ASSERT_EQ(2, col->getSize());
    menu->removeCollection(col);
    ASSERT_EQ(1, menu->getNumOfColl());
}

TEST_F(GestoreNoteSuite, Favorites) {
    menu->addCollection(col);
    col->addNote(note1);
    col->addNote(note2);
    menu->addNoteToFav(note2);
    ASSERT_EQ(2, col->getSize());
    ASSERT_EQ(1, menu->getNumFavNote());
    menu->removeNoteFromFav(note2);
    ASSERT_EQ(0, menu->getNumFavNote());
}

TEST_F(GestoreNoteSuite, ObserverPattern) {
    menu->addCollection(col);
    ASSERT_EQ(menu->getNumOfColl(), menu->viewer.getNumOfColl());
    col->addNote(note1);
    ASSERT_EQ(menu->getNumOfColl(), menu->viewer.getNumOfColl());
    col->removeNote(note1);
    ASSERT_EQ(menu->getNumOfColl(), menu->viewer.getNumOfColl());
}

TEST_F(GestoreNoteSuite, EditNote) {
    menu->addCollection(col);
    col->addNote(note1);
    note1->block();
    ASSERT_EQ(true, note1->isBlocked());
    note1->setContent("New content");
    ASSERT_EQ("Title", note1->getTitle());
    ASSERT_EQ("Content", note1->getContent());
    note1->unlock();
    note1->setContent("New content");
    ASSERT_EQ("New content", note1->getContent());

    col->addNote(note2);
    menu->lockNote(note2);
    ASSERT_EQ(1, note2->isBlocked());
    menu->editNote(note2, "New title", "New content");
    ASSERT_EQ("Title", note2->getTitle());
    ASSERT_EQ("Content", note2->getContent());
    menu->unlockNote(note2);
    menu->editNote(note2, "New title", "New content");
    ASSERT_EQ("New title", note2->getTitle());
    ASSERT_EQ("New content", note2->getContent());
}