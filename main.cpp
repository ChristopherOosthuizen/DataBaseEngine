#include <iostream>
#include "FakeSql/Model/BTreeAct.h"
#include <string>
int main() {
    BTree<std::string> t(4);
    t.insert("hello",  NULL);
    t.insert("h",NULL);
    t.insert("abc",NULL);
    t.insert("death",NULL);
    t.insert("to",NULL);
    t.insert("the",NULL);
    t.insert("living",NULL);
    t.insert("a",NULL);
    t.insert("b",NULL);
    t.insert("c",NULL);
    t.insert("xxx",NULL);
    t.insert("lll",NULL);
    t.insert("mmm",NULL);
    t.insert("nnn",NULL);
    t.insert("rrr",NULL);
    t.insert("6454",NULL);
    t.traverse();
    return 0;
}
