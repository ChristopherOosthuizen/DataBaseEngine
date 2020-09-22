//
// Created by Chris on 9/20/2020.
//

#ifndef FAKESQL_ERRORS_H
#define FAKESQL_ERRORS_H
#include <exception>

class Errors {

};
class LexError : public _exception{
    virtual const char* what() const throw(){
        return "parser error";
    }
};

#endif //FAKESQL_ERRORS_H
