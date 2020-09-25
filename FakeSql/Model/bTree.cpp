//
// Created by Chris on 9/14/2020.
//

#include "bTree.h"
#include <stdlib.h>

using namespace std;

TreeNode::TreeNode(int keyCount, bool isLeaf) {
    m_maxKeyCount = keyCount;
    m_isLeaf = isLeaf;
    //allocate maximum memory possible childern
    m_keys = new TreeVal*[2*m_maxKeyCount];
    for(int i=0; i<2*m_maxKeyCount;i++ )
        m_keys[i] = nullptr;
    m_childPointers = new TreeNode *[2*m_maxKeyCount];

    //set the initial size to 0
    m_currKeysCount =0;
}
TreeNode::~TreeNode() {
    for(int i=0; i< m_currKeysCount+1;i++)
        free(m_keys[i]);
    free(m_keys);
}
void TreeNode::printTree(){
    //for all the keys inside
    int i;
    for(i=0; i< m_currKeysCount;i++){
        //if its not a leaf traverse through those nodes as well
        if(!m_isLeaf)
            m_childPointers[i]->printTree();
        //print the current key
        cout << " " << m_keys[i]->m_value;
    }
    //print last nodes
    if(!m_isLeaf)
        m_childPointers[i]->printTree();
}

TreeVal* TreeNode::search(int key) {
    // find the first key that's bigger than key
    int i;
    for(i=0; i<m_currKeysCount&& key > m_keys[i]->m_value;i++);
    TreeVal * val= m_keys[i];
    int isnull = val !=NULL;
    //if the key equals this key return node
    if(m_keys[i] !=NULL &&m_keys[i]->m_value == key)
        return m_keys[i];
    //if key is not found and the node is a leaf return NULL
    if(m_isLeaf)
        return NULL;
    return m_childPointers[i]->search(key);
}

void BTree::insert(int key,DataObject* object){
    //if the tree is empty
    if(m_root == NULL){
        //create a node to act as root
        m_root = new TreeNode(m_maxValCount,true);
        //set the current key
        m_root->m_keys[0] = new TreeVal(key,object);
        //set size to 1
        m_root->m_currKeysCount =1;
    }else{
        //if the root is full
        if(m_root->m_currKeysCount == 2*m_maxValCount-1){
            auto *newRoot = new TreeNode(m_maxValCount,false);
            newRoot->m_childPointers[0] = m_root;
            newRoot->splitChild(0,m_root);
            int i =0;
            if(newRoot->m_keys[0]->m_value<key)
                i++;
            newRoot->m_childPointers[i]->insertNonFull(key,object);
            m_root = newRoot;
        }else
            m_root->insertNonFull(key,object);
    }
}

void TreeNode::insertNonFull(int key,DataObject* object) {
    int i = m_currKeysCount-1;
    if(m_isLeaf){
        //move all the loops
        while( i>=0 && m_keys[i]->m_value >key){
            m_keys[i+1] = m_keys[i];
            i--;
        }
        m_keys[i+1] = new TreeVal(key,object);
        m_currKeysCount++;
    }else{
        while (i >= 0 && m_keys[i]->m_value > key)
            i--;
        if(m_childPointers[i+1]->m_currKeysCount == 2*m_maxKeyCount-1){
            splitChild(i+1,m_childPointers[i+1]);
            if(m_keys[i+1]->m_value <key)i++;
        }
        m_childPointers[i+1]->insertNonFull(key,object);
    }
}

void TreeNode::splitChild(int val, TreeNode *node) {
    //create a new node that stores the last key
    TreeNode* prevNode = new TreeNode(node->m_maxKeyCount,node->m_isLeaf);
    prevNode->m_currKeysCount = m_maxKeyCount-1;

    //copy keys from node to prevNode
    for(int i=0; i< m_maxKeyCount-1;i++)
        prevNode->m_keys[i] = node->m_keys[i+m_maxKeyCount];
    //copy keys from node to prev node
    if(!node->m_isLeaf){
        for(int j=0;j<m_maxKeyCount;j++)
            prevNode->m_childPointers[j] = node->m_childPointers[j+m_maxKeyCount];
    }

    //create a space for a ne child
    node->m_currKeysCount= m_maxKeyCount-1;
    for(int i = m_currKeysCount; i>= val+1;i--)
        m_childPointers[i+1] = m_childPointers[i];

    //link the nodes
    m_childPointers[val+1]=prevNode;


    //move key nodes
    for(int i= m_currKeysCount-1; i>= val;i--)
        m_keys[i+1] = m_keys[i];


    m_keys[val] = node->m_keys[m_maxKeyCount-1];
    m_currKeysCount++;
}

void TreeNode::findAll(int key,list<DataObject*>* col) {
    // find the first key that's bigger than key
    int i;
    for(i=0; i<m_currKeysCount&& key > m_keys[i]->m_value;i++);


    //if the key equals this key return node
    while(i<m_currKeysCount&& m_keys[i]->m_value == key) {

        col->push_back(m_keys[i]->m_object);
        if(!m_isLeaf)
            m_childPointers[i]->findAll(key,col);
        i++;
    }
    //if key is not found and the node is a leaf return NULL
    if(m_isLeaf)
        return ;
    m_childPointers[i]->findAll(key,col);
}
