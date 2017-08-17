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
  Token(int l) : m_nLine(l)
  {
    // std::cout << "construct Token\n";
  }
  int getLineNu(void) { return m_nLine; }

  virtual bool isIdentifier(void) { return false; }
  virtual bool isNumber(void) { return false; }
  virtual bool isString(void) { return false; }

  virtual int getNumber(void) { return INT_MIN; }
  virtual std::string getIdName(void) { return ""; }
  virtual std::string getStrText(void) { return ""; }

  virtual std::string getText(void) {}

  void printType(void);
  bool isNotEof(void);
  virtual ~Token()
  {
    // std::cout << "destory Token\n";
  }
};

class EofToken : public Token
{
public:
  EofToken() : Token(-1)
  {
    // std::cout << "construct EolToken\n";
  }
  ~EofToken()
  {
    // std::cout << "distory EolToken\n";
  }
};

class NumToken : public Token
{
protected:
  int m_nValue;

public:
  NumToken(int line, int value)
      : m_nValue(value),
        Token(line)
  {
    // std::cout << "construct NumToken\n";
  }

  bool isNumber(void) { return true; }
  int getNumber(void) { return m_nValue; }

  std::string getText(void) { return std::to_string(m_nValue); }
  ~NumToken()
  {
    // std::cout << "destory NumToken\n";
  }
};

class IdToken : public Token
{
protected:
  std::string m_nIdName;

public:
  IdToken(int line, const std::string &idName)
      : m_nIdName(idName),
        Token(line)
  {
    // std::cout << "construct IdToken\n";
  }

  bool isIdentifier(void) { return true; }
  std::string getIdName(void) { return m_nIdName; }

  std::string getText(void) { return m_nIdName; }
  ~IdToken()
  {
    // std::cout << "destory IdToken\n";
  }
};

class StrToken : public Token
{
protected:
  std::string m_nStrText;

public:
  StrToken(int line, const std::string &strText)
      : m_nStrText(strText),
        Token(line)
  {
    // std::cout << "construct StrToken\n";
  }

  bool isString(void) { return true; }
  std::string getStrText(void) { return m_nStrText; }

  std::string getText(void) { return m_nStrText; }
  ~StrToken()
  {
    // std::cout << "destory StrToken\n";
  }
};

#endif