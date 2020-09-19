//
// Created by Chris on 9/14/2020.
//

#include "bTree.h"
#include <stdlib.h>
template <class T>
bTreeNode<T>::bTreeNode(int p_maxKeys, bool _leaf, void* object){
    m_object = (object);
    m_maxKeys = p_maxKeys;
    leaf = _leaf;
    m_keys = new T[2*m_maxKeys-1];
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
    while(i <m_currKeyCount && m_keys[i] < key)
        i++;
    if(m_keys[i] ==key)
        return this;
    if(leaf)
        return NULL;
    return m_children[i]->search(key);
}

template <class T>
void bTreeNode<T>::insertNonFull(T key) {
    int i = m_currKeyCount-1;
    if(leaf){
        while(i>=0 && m_keys[i] > key){
            m_keys[i+1] = m_keys[i];
            i--;
        }
        m_keys[i+1] =key;
        m_currKeyCount +=1;
    }else{
        while(i >= 0 && m_keys[i] > key)
            i--;
        if(m_children[i+1]->m_currKeyCount == 2*m_maxKeys-1){
            splitChild(i+1, m_children[i+1]);
            if(m_keys[i+1] < key)
                i++;
        }
        m_children[i+1]->insertNonFull(key);
    }
}

template <class T>
void bTreeNode<T>::splitChild(int i, bTreeNode *y) {
    auto *z = new bTreeNode(y->m_maxKeys, y->leaf,y->m_object);
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