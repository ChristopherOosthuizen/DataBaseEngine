//
// Created by Chris on 9/24/2020.
//

#include <fstream>
#include "Instance.h"

string Instance::handle(Statement *statement) {
    if(Expression* expression = dynamic_cast<Expression*>(statement)) {
        switch (expression->m_command->m_token->m_type) {
            case TokenType::CREATE:
                return handleCreate(expression);
            case TokenType::SEARCH:
                return handleSearch(expression);
            default:
                return "FAILED UNKOWN COMMAND";
        }
    }else if(Loader* loader = dynamic_cast<Loader*>(statement)){
        switch(loader->m_command->m_type) {
            case TokenType::LOAD:
                return handleLoad(loader);
            default:
                return handleSave(loader);
        }
    }
    else{
        return "UNKOWN STATEMENT";
    }
}
string Instance::handleLoad(Loader *load) {
    string* input = new string;
    readFromFile(load->m_address->m_symbol,input);
    Parser parser(input);
    auto* tokens = new std::list<Token*>;
    while(!parser.isDone()){
        Token* token = parser.next();
        tokens->push_back(token);
    }
    StatementParser stat(tokens);
    string result = "LOAD STARTED\n";
    while((!stat.isFinished())){
        try {
            result += this->handle(stat.next())+'\n';
        }catch(string& str){
            result += str+'\n';
            break;
        }
    }
    return result;
}
string Instance::handleCreate(Expression *expression) {
    if(expression->m_type->m_token->m_type == TokenType::MODEL){
        Model* point = (m_models)[expression->m_query->m_token->m_symbol];
        if(point != nullptr)
            return "table with that name already exists";
        (m_models)[expression->m_query->m_token->m_symbol] = new Model(expression);
        return "MADE data";
    }else{
        Model* model = (m_models)[expression->m_query->m_token->m_symbol];
        if(model == nullptr)
            throw string("UNKNOWN MODEL");
        model->insert(expression->m_query);
        return "inserted data";
    }
    return "SUCCESS";
}
string Instance::handleSearch(Expression *expression) {
    if(expression->m_type->m_token->m_type == TokenType::MODEL){
        return "UNKOWN";
    }else{
        Model* model = (m_models)[expression->m_query->m_token->m_symbol];
        if(model == nullptr)
            throw string("UNKNOWN MODEL");
        list<DataObject*>* objs = model->search(expression->m_query);
        string result = "DATA TABLES\n\n";
        for(DataObject* ob:*objs){
            for(auto del: ob->m_definitions){
                result += (del.first) +":"+(del.second->m_symbol)+"\n";
            }
            result+="\n";
        }
        return result;
    }
}

void Instance::readFromFile(string adress,string* result) {
    fstream myfile ;
    myfile.open(adress,ios::in);
    if (myfile.is_open())
    {
        string res;
        while ( getline(myfile,res) )
        {
            *result+=res+'\n';
        }
        myfile.close();
    }
}

string Instance::handleSave(Loader *load) {
    string result;
    for(auto del: m_models){
        result+=del.second->toString()+'\n';
        for(auto dells: *del.second->m_objects){
            result += "CREATE OBJECT "+del.second->m_name+dells->toString()+'\n';
        }
    }
    ofstream file;
    file.open(load->m_address->m_symbol);
    file<<result;
    file.close();
    return "SAVED DATABASE";
}
