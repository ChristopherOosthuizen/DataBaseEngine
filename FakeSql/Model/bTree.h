//
// Created by Chris on 9/14/2020.
//

#ifndef FAKESQL_BTREE_H
#define FAKESQL_BTREE_H
#include<iostream>
#include "DataObject.h"
#include <list>
using namespace std;
class TreeVal{

public:
    int m_value;
    TreeVal(int value, DataObject* object){
        m_value = value;
        m_object = object;
    }
    int getVal(){
        return m_value;
    }
    DataObject* m_object;
};

class TreeNode {
    TreeVal **m_keys;
    int m_maxKeyCount;
    TreeNode **m_childPointers;
    int m_currKeysCount;
    bool m_isLeaf;
public:
    TreeNode(int keyCount, bool isLeaf);
    ~TreeNode();
    void insertNonFull(int key,DataObject* object);
    void splitChild(int val, TreeNode *node);
    void printTree();
    TreeVal *search(int key);
    void findAll(int key,list<DataObject*>* objects);
    friend class BTree;
    DataObject* m_object;
    friend class BTree;
};
class BTree {
    TreeNode *m_root;
    int m_maxValCount;


public:
    BTree(int maxValCount) {
        m_root = NULL;
        m_maxValCount = maxValCount;
    }
    list<DataObject*>* findAll(int key){
        auto* col = new list<DataObject*>;
        if(m_root !=NULL)
            m_root->findAll(key,col);
        return col;
    }

    void print() {
        if (m_root != NULL)
            m_root->printTree();
    }

    TreeVal *search(int k) {
        return (m_root == NULL) ? NULL : m_root->search(k);
    }

    void insert(int key,DataObject* object);
};





#endif //FAKESQL_BTREE_H
