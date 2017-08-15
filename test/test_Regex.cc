#include "../regex.h"
#include "../token.h"
#include "../reader.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

static Token *Eof = new Token(-1);
static std::string Eol = "\n";

int main()
{
    string a1 = "\\s*((//.*)|([0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")";
    string a2 = "|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\||\\p{Punct})?";
    string all_pattern = a1 + a2;
    Regex regex = Regex(all_pattern);
    deque<shared_ptr<Token>> result(0);
    
    Reader reader = Reader("source.rg");
    
    cout << "line number:" << reader.getLineNu() << endl;

    while (reader.haveMore())
    {
        string cur = reader.readLine();
        // cout << reader.getCurrLineNu() << ":" << cur;
        regex.regex_match(1, cur, result);
    }
    cout << "queue.size()=" << result.size() << endl;
    while (!result.empty())
    {
        shared_ptr<Token> tmp = result.front();
        // tmp->printType();
        result.pop_front();
    }
}
