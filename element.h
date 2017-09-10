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
  Tree()
  {
    std::cout << "class Tree construct\n";
  }
  void parse(Lexer lexer, std::vector<ASTree> res)
  {
    res.push_back(m_nParser.parse(lexer));
  }
  bool match(Lexer lexer)
  {
    return m_nParser.match(lexer);
  }
  ~Tree()
  {
    std::cout << "class Tree destory\n";
  }
};
/////////
class OrTree : public Element
{
protected:
  std::vector<Parser> m_nParsers;

public:
  OrTree(std::vector<Parser> &p)
  {
    m_nParsers = p;
    std::cout << "OrTree construct\n";
  }
  void parse(Lexer lexer, std::vector<ASTree> res)
  {
    Parser p = choose(lexer);
    if (p == nullptr)
    {
    }
    else
    {
      res.push_back(p.parse(lexer));
    }
  }
  bool match(Lexer lexer)
  {
    return choose(lexer) != nullptr;
  }
  Parser choose(Lexer lexer)
  {
    for (auto p : m_nParsers)
    {
      if (p.match(lexer))
        return p;
    }
    //return nullptr;
  }
  void insert(Parser p)
  {
    //insert p front the m_nParsers;
    std::vector<Parser> newP(m_nParsers.size() + 1);
    newP.push_back(p);
    for (auto pp : m_nParsers)
    {
      newP.push_back(pp);
    }
    m_nParsers = newP;
  }
  ~OrTree()
  {
    std::cout << "class OrTree destory\n";
  }
};
//////////
class Repeat : public Element
{
protected:
  Parser m_nParser;
  bool m_nOnlyOnce;

public:
  Repeat(Parser p, bool once)
  {
    m_nParser = p;
    m_nOnlyOnce = once;
    std::cout << "class Repeat construct\n";
  }
  void parser(Lexer lexer, std::vector<ASTree> res)
  {
    while (m_nParser.match(lexer))
    {
      //harh
      if (m_nOnlyOnce)
        break;
    }
  }
  bool match(Lexer lexer)
  {
    return m_nParser.match(lexer);
  }
  ~Repeat()
  {
    std::cout << "class Repeat destory\n";
  }
};
///////
class AToken : public Element //a abstract class
{
protected:
  Factory m_nFactory;

public:
  AToken(std::shared_ptr<ASTLeaf> type)
  {
    if (type == nullptr)
      type = ;
    m_nFactory = ;
    std::cout << "class AToken construct\n";
  }
  void parse(Lexer lexer, std::vector<ASTree> res)
  {
    std::shared_ptr<Token> t = lexer.read();
    if (test(t))
    {
      ASTree leaf = m_nFactory.make(t);
      res.add(leaf);
    }
    else
    {
      std::cout << "parse exception\n";
    }
  }
  bool match(Lexer lexer)
  {
    return test(lexer.peek(0));
  }
  virtual bool test(Token t) = 0;
  ~AToken()
  {
    std::cout << "class AToken destory\n";
  }
};
///////
class IdToken : public AToken
{
protected:
  std::set<std::string> m_nReserved;

public:
  IdToken(std::shared_ptr<ASTLeaf> type,
          std::set<std::string> r)
      : AToken(type), m_nReserved(r)
  {
    std::cout << "class IdToken construct\n";
  }
  bool test(Token t)
  {
    auto p = m_nReserved.find(t.getIdName());
    return t.isIdentifier() && p == m_nReserved.end();
  }
  ~IdToken()
  {
    std::cout << "class IdToken destroy\n";
  }
};
///////
class NumToken : public AToken
{
public:
  NumToken(std::shared_ptr<ASTLeaf> type) : AToken(type)
  {
    std::cout << "class NumToken construct\n";
  }
  bool test(Token t)
  {
    return t.isNumber();
  }
  ~NumToken()
  {
    std::cout << "class NumToken destory\n";
  }
};
//////
class StrToken : public AToken
{
public:
  StrToken(std::shared_ptr<ASTLeaf> type) : AToken(type)
  {
    std::cout << "class StrToken constuct\n";
  }
  bool test(Token t)
  {
    return t.isString();
  }
  ~StrToken()
  {
    std::cout << "class StrToken destory\n";
  }
};
/////
class Leaf : public Element
{
protected:
  std::vector<std::string> m_nTokens;

public:
  Leaf(std::vector<std::string> &t){
    m_nTokens=t;
    std::cout<<"class Leaf construct\n";
  }
  void parse(Lexer lexer, std::vector<ASTree> res);
  void find();
  bool match(Lexer lexer);
  ~Leaf(){
    std::cout<<"class Leaf destory\n";
  }
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