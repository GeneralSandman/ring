#include "../reader.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Reader reader = Reader("source.rg");
    cout << "line number:" << reader.getLineNu() << endl;

    while (reader.haveMore())
    {
        cout << reader.getCurrLineNu() << ":" << reader.readLine();
    }

    cout<<"reader again\n";
    reader.resetToHead();

    while (reader.haveMore())
    {
        cout << reader.getCurrLineNu() << ":" << reader.readLine();
    }
}