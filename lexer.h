#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <queue>
using namespace std;
class Lexer
{
private:

public:
  Lexer(shared_ptr<Reader> read);
  ~Lexer();
};

#endif