#include <iostream>
#include "FakeSql/bTree.h"
int main() {
    BTree t(3);
    for(int i=0; i< 100;i++){
        t.insert(i);
    }
    std::cout << "Traversal of the constucted tree is ";
    t.traverse();
    return 0;
}
