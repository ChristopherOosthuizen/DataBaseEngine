#include <iostream>
#include "FakeSql/bTree.h"
int main() {
    BTree t(3);
    for(int i=0; i< 100;i++){
        t.insert(i);
    }
    t.traverse();
    return 0;
}
