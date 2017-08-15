#include <queue>
#include <iostream>
#include <memory>
#include "../lexer.h"
#include "../token.h"
using namespace std;

int main()
{

    string a1 = "\\s*((//.*)|([0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")";
    string a2 = "|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\||\\p{Punct})?";
    string pattern = a1+a2;
    string file = "source.rg";

    Lexer lexer = Lexer(pattern, file);

    shared_ptr<Token> t;
    while((t=lexer.read())->isNotEof()){
        t->printType();
    }
}