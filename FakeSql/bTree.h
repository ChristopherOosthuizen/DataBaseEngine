//
// Created by Chris on 9/14/2020.
//

#ifndef FAKESQL_BTREE_H
#define FAKESQL_BTREE_H
#include<iostream>

template <class T>
class bTreeNode{
public:
 T *m_keys;
 int m_maxKeys;
 bTreeNode **m_children;
 int m_currKeyCount;
 bool leaf;
    bTreeNode(int _t,bool _leaf);
    void traverse();
    bTreeNode *search(T k);
    void splitChild(int i, bTreeNode *y);
    void insertNonFull(T key);
    bool isGreaterThanKey(int i,T key);
};




#endif //FAKESQL_BTREE_H
