#ifndef RULE_H
#define RULE_H
#include <iostream>
#include <string>
using namespace std;
class Rule
{
  protected:
    string m_nRegex;

  public:
    virtual bool m_fTest() = 0;
};

class Iden : public Rule
{
  private:
  public:
    Iden()
    {
        m_nRegex = "";
    }
};

class String : public Rule
{
  private:
  public:
    String()
    {
        m_nRegex = "";
    }
};

class Num : public Rule
{
  private:
  public:
    Num()
    {
        m_nRegex = "";
    }
};

#endif