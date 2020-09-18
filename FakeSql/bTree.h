//
// Created by Chris on 9/14/2020.
//

#ifndef FAKESQL_BTREE_H
#define FAKESQL_BTREE_H
#include<iostream>

template <class T>
class bTreeNode{
 T *m_keys;
 int m_maxKeys;
 bTreeNode **m_children;
 int m_currKeyCount;
 bool leaf;
public:
    bTreeNode(int _t,bool _leaf);
    void traverse();
    bTreeNode *search(int k);
    void splitChild(int i, bTreeNode *y);
    void insertNonFull(int key);
    bool isGreaterThanKey(int i,int key);
    friend class BTree;
};

class BTree{
    bTreeNode<int> *root;
    int t;
public:
    BTree(int _t){root = NULL; t = _t;};
    void traverse();
    bTreeNode<int>* search(int k){return (root == NULL)?NULL : root->search(k);};
    void insert(int key);


};




#endif //FAKESQL_BTREE_H
