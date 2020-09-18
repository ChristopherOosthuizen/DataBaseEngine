//
// Created by Chris on 9/14/2020.
//

#include "bTree.h"
#include <stdlib.h>
template <class T>
bTreeNode<T>::bTreeNode(int p_maxKeys, bool _leaf){
    m_maxKeys = p_maxKeys;
    leaf = _leaf;
    m_keys = new int[2*m_maxKeys-1];
    m_children = new bTreeNode *[2*m_maxKeys];
    m_currKeyCount =0;
}
template <class T>
void bTreeNode<T>::traverse() {
    int i;
    for(i =0; i<m_currKeyCount;i++){
        if(!leaf)
            m_children[i]->traverse();
        std::cout << " "<< m_keys[i];
    }
    if(!leaf)
        m_children[i]->traverse();
}
template <class T>
bTreeNode<T> *bTreeNode<T>::search(T key) {
    int i=0;
    while(i <m_currKeyCount && !isGreaterThanKey(i,key))
        i++;
    if(m_keys[i] ==key)
        return this;
    if(leaf)
        return NULL;
    return m_children[i]->search(key);
}
void BTree::insert(int key){
    if(root ==NULL){
        root = new bTreeNode<int>(t,true);
        root->m_keys[0] =key;
        root->m_currKeyCount = 1;

    }else{
        if(root->m_currKeyCount ==2*t-1){
            auto s = new bTreeNode<int>(t,false);
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

void BTree::traverse() {
    if(root != NULL)
    root->traverse();
}

template <class T>
void bTreeNode<T>::insertNonFull(T key) {
    int i = m_currKeyCount-1;
    if(leaf){
        while(i>=0 && isGreaterThanKey(i,key)){
            m_keys[i+1] = m_keys[i];
            i--;
        }
        m_keys[i+1] =key;
        m_currKeyCount +=1;
    }else{
        while(i >= 0 && isGreaterThanKey(i,key))
            i--;
        if(m_children[i+1]->m_currKeyCount == 2*m_maxKeys-1){
            splitChild(i+1, m_children[i+1]);
            if(!isGreaterThanKey(i+1,key))
                i++;
        }
        m_children[i+1]->insertNonFull(key);
    }
}
template <class T>
bool bTreeNode<T>::isGreaterThanKey(int i, T key) {

    return m_keys[i] > key;
}
template <class T>
void bTreeNode<T>::splitChild(int i, bTreeNode *y) {
    auto *z = new bTreeNode(y->m_maxKeys, y->leaf);
    z->m_currKeyCount = m_maxKeys-1;
    for(int j=0; j< m_maxKeys-1;j++){
        z->m_keys[j] = y->m_keys[j+m_maxKeys];
    }

    if(!y->leaf){
        for(int j =0; j<m_maxKeys;j++){
            z->m_children[j] = y->m_children[j+m_maxKeys];
        }
    }
    y->m_currKeyCount = m_maxKeys-1;

    for(int j =m_currKeyCount;j >= i+1;j--){
        m_children[j+1] = m_children[j];
    }

    m_children[i+1] = z;

    for(int j = m_currKeyCount-1; j >=i;j--)
        m_keys[j+1] = y->m_keys[j];

    m_keys[i] = y->m_keys[m_maxKeys-1];
    m_currKeyCount++;
}