#include <iostream>
#include "FakeSql/BTreeAct.h"

int main() {
    BTree<int> t(3);
    for(int i=0; i< 100;i++){
        t.insert(i);
    }
    t.traverse();
    return 0;
}
