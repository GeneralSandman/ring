#ifndef READER_H
#define READER_H

#include <iostream>
#include <fstream>
#include <string>
class Reader
{
private:
  std::string m_nFile;
  std::ifstream m_nFileStream;
  std::size_t m_nLine;
  std::size_t m_nCurrLine;

  void m_fCountLine(void);

public:
  Reader(const std::string &f);
  std::string readLine(void);
  size_t getCurrLineNu(void) { return m_nCurrLine; }
  size_t getLineNu(void) { return m_nLine; }
  bool haveMore(void) { return m_nLine > m_nCurrLine; }
  void resetToHead(void);
};

#endif // !READER_H
