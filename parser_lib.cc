#include "parser_lib.h"
#include<memory>
class Element;
namespace parser
{

void Parser::parser() {}

bool Parser::match(std::shared_ptr<Lexer> lexer) {
    if(m_nElements.empty())
        return true;
    else{
        std::shared_ptr<Element> e=m_nElements.front();
        return e.match(lexer);
    }
}
}