#ifndef ELEMENT_H
#define ELEMENT_H
#include "lexer.h"
#include "parser_lib.h"
#include "factory.h"
#include "tree.h"
#include <vector>
#include <set>
namespace parser
{
class Element
{
  public:
    virtual void parse(Lexer lexer, std::vector<ASTree> res) = 0;
    virtual bool match(Lexer lexer) = 0;
};
////////
class Tree : public Element
{
  protected:
    Parser m_nParser;

  public:
    Tree();
    void parse(Lexer lexer, std::vector<ASTree> res);
    bool match(Lexer lexer);
    ~Tree();
};
/////////
class OrTree : public Element
{
  protected:
    std::vector<Parser> m_nParsers;

  public:
    OrTree(std::vector<Parser> &p);
    void parse(Lexer lexer, std::vector<ASTree> res);
    bool match(Lexer lexer);
    Parser choose(Lexer lexer);
    void insert(Parser p);
    ~OrTree();
};
//////////
class Repeat : public Element
{
  protected:
    Parser m_nParser;
    bool m_nOnlyOnce;

  public:
    Repeat(Parser p, bool once);
    void parser(Lexer lexer, std::vector<ASTree> res);
    bool match(Lexer lexer);
    ~Repeat();
};
///////
class AToken : public Element
{
  protected:
    Factory m_nFactory;

  public:
    AToken();
    void parse(Lexer lexer, std::vector<ASTree> res);
    bool match(Lexer lexer);
    virtual bool test(Token t) = 0;
    ~AToken();
};
///////
class IdToken : public AToken
{
  protected:
    std::set<std::string> m_nReserved;

  public:
    IdToken();
    bool test(Token t);
    ~IdToken();
};
///////
class NumToken : public AToken
{
  public:
    NumToken();
    bool test(Token t);
    ~NumToken();
};
//////
class StrToken : public AToken
{
  public:
    StrToken();
    bool test(Token t);
    ~StrToken();
};
/////
class Leaf : public Element
{
  protected:
    std::vector<std::string> m_nTokens;

  public:
    Leaf();
    void parse(Lexer lexer, std::vector<ASTree> res);
    void find();
    bool match(Lexer lexer);
    ~Leaf();
};
//////
class Skip : public Element
{
  public:
    Skip();
    void find(std::vector<ASTree> res, Token t);
    ~Skip();
};
/////
class Expr : public Element
{
  protected:
    Factory m_nFactory;
    // operators
    Parser m_nParser;

  public:
    Expr();
    void parse(Lexer lexer, std::vector<ASTree> res);
    //doShift()

    bool match(Lexer lexer);
    ~Expr();
};
////
}
#endif //ELEMENT_H