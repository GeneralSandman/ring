#ifndef REGEX_H
#define REGEX_H
#include <iostream>
#include <queue>
#include <boost/regex.hpp>

class Token;
class Regex
{
private:
  std::string m_nPattern;
  boost::regex m_nRegex;
  int m_nLine;

  void setLineNu(int );
  bool m_fLookAt(const std::string &sou, int &begin, boost::regex reg, boost::cmatch &mat);
  void m_fFillQueue(boost::cmatch &, std::queue<Token *> &);

public:
  Regex(const std::string &pattern);

  void regex_match(int,const std::string &, std::queue<Token *> &);

  ~Regex();
};

#endif // !REGEX_H
