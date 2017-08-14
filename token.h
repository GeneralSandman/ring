#ifndef TOKEN_H
#define TOKEN_H

#include <cstddef>
#include <climits>
#include <iostream>
class Token
{
protected:
  int m_nLine;

public:
  Token(int l) : m_nLine(l) {}
  int getLineNu(void) { return m_nLine; }

  virtual bool isIdentifier(void) { return false; }
  virtual bool isNumber(void) { return false; }
  virtual bool isString(void) { return false; }

  virtual int getNumber(void) { return INT_MIN; }
  virtual std::string getIdName(void){return "";}
  virtual std::string getStrText(void) { return ""; }
};

static Token *Eof=new Token(-1);
static std::string Eol="\n";


class NumToken : public Token
{
protected:
  int m_nValue;

public:
  NumToken(int line, int value)
      : m_nValue(value),
        Token(line) {}

  bool isNumber(void) { return true; }
  int getNumber(void) { return m_nValue; }
};

class IdToken : public Token
{
protected:
  std::string m_nIdName;

public:
  IdToken(int line, const std::string &idName)
      : m_nIdName(idName),
        Token(line) {}

  bool isIdentifier(void) { return true; }
  std::string getStrText(void) { return m_nIdName; }
  // std::string getIdName(void){return m_nIdName;}
};

class StrToken : public Token
{
protected:
  std::string m_nStrText;

public:
  StrToken(int line, const std::string &strText)
      : m_nStrText(strText),
        Token(line) {}

  bool isString(void) { return true; }
  std::string getStrText(void) { return m_nStrText; }
};

#endif