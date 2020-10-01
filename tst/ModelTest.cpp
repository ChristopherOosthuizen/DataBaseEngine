//
// Created by Chris on 9/24/2020.
//

#include <Model/bTree.h>
#include "gtest/gtest.h"

TEST(BTREE,basic){
    BTree tree(rand()%100);
    for(int i=0; i<100;i++)
        tree.insert(i,NULL);
    for(int i=0; i<100;i++)
        ASSERT_TRUE(tree.search(i) !=NULL);
}
TEST(BTREE, findAll){
    BTree tree(rand()%100);
    for(int i=0; i<100;i++)
        tree.insert(i,NULL);
    for(int i=0; i<30;i++)
        tree.insert(12,NULL);
    ASSERT_EQ(tree.findAll(12)->size(),31);
}

TEST(Model, Search){

}