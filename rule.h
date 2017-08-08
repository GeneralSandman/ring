#ifndef RULE_H
#define RULE_H
#include <iostream>
#include <string>
using namespace std;
class Rule
{
protected:
  string m_nName;
  string m_nRegex;

public:
  Rule(){};
  string getName() { return m_nName; }
  string getRegex() { return m_nRegex; }
  virtual bool Test() = 0;
  virtual ~Rule(){};
};

class Iden : public Rule
{
private:
public:
  Iden()
  {
    m_nName = "identifier";
    m_nRegex = "";
  }
  bool Test();
  ~Iden(){};
};

class String : public Rule
{
private:
public:
  String()
  {
    m_nName = "string";
    m_nRegex = "";
  }
  bool Test();
  ~String();
};

class Num : public Rule
{
private:
public:
  Num()
  {
    m_nName = "number";
    m_nRegex = "";
  }
  bool Test();
  ~Num();
};

#endif