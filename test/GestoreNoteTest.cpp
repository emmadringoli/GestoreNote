//
// Created by Emma Dringoli on 29/09/22.
//
#include "gtest/gtest.h"
#include "../Note.h"
#include "../Collection.h"
#include "../Menu.h"

TEST(Note, Constructor){
    Note n;
    ASSERT_EQ("Nota",n.getTitle());
    ASSERT_EQ("",n.getContent());
}

TEST(Note, Block){
    Note n;
    n.block();
    n.setTitle("Title");
    n.setContent("Content");
    ASSERT_EQ("Nota",n.getTitle());
    ASSERT_EQ("",n.getContent());
    n.unlock();
    n.setTitle("Title");
    n.setContent("Content");
    ASSERT_EQ("Title",n.getTitle());
    ASSERT_EQ("Content",n.getContent());
}

TEST(Collection, Constructor){
    Collection c;
    ASSERT_EQ(0, c.getSize());
    ASSERT_EQ("Collection", c.getName());
}

TEST(Menu,Constructor){
    Menu m;
    ASSERT_EQ(0,m.getNumOfColl());
    ASSERT_EQ(0,m.getNumOfNote());
    ASSERT_EQ(0,m.getNumFavNote());
}

