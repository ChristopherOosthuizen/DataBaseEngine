#include <iostream>
#include <list>
#include "FakeSql/Parser/Parser.h"
#include "FakeSql/StatmentParser/StatementParser.h"
#include "FakeSql/Model/Model.h"
#include "FakeSql/Model/bTree.h"
void readLine(string* str){
    char c=0;
    int isMultiLine =0;
    while(c !='\n'|| isMultiLine){
        c = (char)getchar();
        str->push_back(c);
        if(c =='{'){
            isMultiLine = 1;
        }else if(c == '}')
            isMultiLine =0;
    }
}

int main() {
    /*string* input = new string;
    while(1){
        std::cout << ">";
        readLine(input);
        if(!input->compare(":q\n"))
            break;
        Parser parser(input);
        auto* tokens = new std::list<Token*>;
        while(!parser.isDone()){
            Token* token = parser.next();
            tokens->push_back(token);
        }
        try {
            StatementParser stat(tokens);
            stat.next()->print();
        }catch(string& e ){
            std::cout<<e<<"\n";
        }
        *input ="";
    }
    delete input;*/

    BTree t(3);
    Object* obj1 = new Object(12,"Hello");
    Object* obj2 = new Object(14,"No right");
    Object* obj3 = new Object(45,"good");
    Object* obj4 = new Object(56,"great");
    Object* obj5 = new Object(56,"new");
    Object* obj6 = new Object(56,"new");
    Object* obj7 = new Object(56,"new");
    t.insert(obj1->m_id,obj1);
    t.insert(obj2->m_id,obj2);
    t.insert(obj3->m_id,obj3);
    t.insert(obj4->m_id,obj4);
    t.insert(obj5->m_id,obj5);
    t.insert(obj6->m_id,obj6);
    t.insert(obj7->m_id,obj7);
    list<Object*>* objs = t.findAll(56);
    for(Object* obj: *objs){
        cout<<obj->m_name<<"\n";
    }

}

