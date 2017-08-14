#include "../regex.h"
#include "../token.h"
#include "../reader.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string a1 = "\\s*((//.*)|([0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")";
    string a2 = "|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\||\\p{Punct})?";
    string all_pattern = a1 + a2;

    Regex regex = Regex(all_pattern);
    queue<Token *> result;

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
        Token *tmp = result.front();
        tmp->printType();
        result.pop();
        delete tmp;
    }
}