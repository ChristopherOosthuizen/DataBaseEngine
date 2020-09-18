//
// Created by Chris on 9/18/2020.
//

#ifndef FAKESQL_BTREEACT_H
#define FAKESQL_BTREEACT_H
#include "bTree.h"
#include "bTree.cpp"
template <typename T>
class BTree{
    bTreeNode<int> *root;
    int m_count;
public:
    explicit BTree(int _t){root = NULL; m_count = _t;};
    void traverse(){
        if(root != NULL)
            root->traverse();
    };
    bTreeNode<int>* search(int k){return (root == NULL)?NULL : root->search(k);};
    void insert(int key){
        if(root ==NULL){
            root = new bTreeNode<int>(m_count,true);
            root->m_keys[0] =key;
            root->m_currKeyCount = 1;

        }else{
            if(root->m_currKeyCount ==2*m_count-1){
                auto s = new bTreeNode<int>(m_count,false);
                s->m_children[0] = root;
                s->splitChild(0,root);
                int i=0;
                if(!s->isGreaterThanKey(0,key))
                    i++;
                s->m_children[i]->insertNonFull(key);

                root = s;
            }else
                root->insertNonFull(key);
        }
    }


};


#endif //FAKESQL_BTREEACT_H
