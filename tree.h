#ifndef TREE_H
#define TREE_H
#include <memory>
#include <vector>
#include <iterator>
#include "token.h"
class ASTree;
typedef std::shared_ptr<ASTree> ASTree_ptr;
typedef std::vector<ASTree_ptr> ASTree_Vector_ptr;
typedef ASTree_Vector_ptr::iterator ASTree_Vector_ptr_iter;
class ASTree
{
  protected:
    ASTree_Vector_ptr m_nChildern;

  public:
    virtual ASTree_ptr child(int) = 0;
    virtual int numChildren() = 0;
    virtual ASTree_Vector_ptr_iter children() = 0;
    std::string location();
    ASTree_Vector_ptr_iter iterator() { return children(); }
};

/////

class ASTLeaf : public ASTree
{
  protected:
    std::shared_ptr<Token> m_pToken;

  public:
    ASTLeaf(std::shared_ptr<Token> t) : m_pToken(t)
    {
    }
    ASTree_ptr child(int i) { return nullptr; }
    int numChildren() { return 0; }
    ASTree_Vector_ptr_iter children() { return nullptr; }
    std::string toString() { return m_pToken->getNumber(); }
    std::string location() { return "at line:" + std::to_string(m_pToken->getLineNu()); }
    std::shared_ptr<Token> token() { return m_pToken; }
};

/////

class ASTList : public ASTree
{
};

////

class NumberLiteral : public ASTLeaf
{
};

class Name : public ASTLeaf
{
};

class BinaryExpr : public ASTList
{
};

//////

#endif //TREE_H