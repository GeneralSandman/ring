#include "lexer.h"
#include "rule.h"
#include "reader.h"
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    string file = "source.cc";
    shared_ptr<Reader> reader = make_shared<Reader>(Reader(file));

    shared_ptr<Rule> r1, r2, r3;
    r1 = make_shared<Rule>(String());
    r2 = make_shared<Rule>(Iden());
    r3 = make_shared<Rule>(Num());


    Lexer lex = Lexer();
    lex.AddRule(r1);
    lex.AddRule(r2);
    lex.AddRule(r3);


    return 0;
}