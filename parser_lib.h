#ifndef PARSER_LIB_H
#define PARSER_LIB_H

#include "element.h"
#include "factory.h"
#include <memory>
#include <queue>

class Element;
class Factory;

namespace parser
{
class Parser
{
  private:
    std::deque<std::shared_ptr<Element>> m_nElements;
    std::shared_ptr<Factory> m_pFactory;

  public:
    Parser()
    {
        std::cout << "class Parser construct\n";
    };
    Parser(const Parser &p)
    {
        m_nElements = p.m_nElements;
        m_pFactory = p.m_pFactory;
    }
    ~Parser()
    {
        std::cout << "class Parser destory\n";
    }
    void parse(Lexer); //should return ASTree
    bool match(Lexer); //parmas are Lexer;

    Parser rule(void);
    Parser rule(int);

    Parser reset(void);
    Parser reset(int);

    Parser number(void);
    Parser number(int);

    Parser identifier(void);
    Parser identifier(int);

    Parser string(void);
    Parser string(int);

    Parser token();

    Parser sep();

    Parser ast();

    Parser oor();

    Parser maybe();

    Parser option();

    Parser repeat();

    Parser expression(void);
    Parser expression(int);

    Parser insertChoice();
};
}

#endif //PARSER_LIB_H