//
// Created by Chris on 9/14/2020.
//

#ifndef FAKESQL_BTREE_H
#define FAKESQL_BTREE_H
#include<iostream>
#include "Model.h"
#include <list>
using namespace std;
class TreeNode {
    int *m_keys;
    int m_maxKeyCount;
    TreeNode **m_childPointers;
    int m_currKeysCount;
    bool m_isLeaf;
public:
    TreeNode(int keyCount, bool isLeaf);
    void insertNonFull(int key);
    void splitChild(int val, TreeNode *node);
    void printTree();
    TreeNode *search(int key);
    friend class BTree;
    Object* m_object;
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

    void print() {
        if (m_root != NULL)
            m_root->printTree();
    }

    TreeNode *search(int k) {
        return (m_root == NULL) ? NULL : m_root->search(k);
    }

    void insert(int key);
};




#endif //FAKESQL_BTREE_H
