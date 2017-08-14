#include <boost/regex.hpp>
#include <iostream>
#include <string>
using namespace std;



int main()
{
    string space_pattern = "\\s*";
    string number_pattern = "[0-9]+";
    string id_pattern = "[a-z_A-Z][a-z_A-Z0-9]*";
    string string_pattern = "\"(\"|\\\\|\n|[^\"])*\"";
    string punct_pattern = "\\p{Punct}";

    string space = "   ";
    string number = "12333";
    string id = "_a123";
    string str = "\"lizhenhu say:\"hello world!\"\n\"";
    string punct = ",";

    boost::regex space_regex(space_pattern);
    boost::regex number_regex(number_pattern);
    boost::regex id_regex(id_pattern);
    boost::regex string_regex(string_pattern);
    boost::regex punct_regex(punct_pattern);

    if (boost::regex_match(space, space_regex))
        cout << "is space" << endl;

    if (boost::regex_match(number, number_regex))
        cout << "is number" << endl;

    if (boost::regex_match(id, id_regex))
        cout << "is id" << endl;

    if (boost::regex_match(str, string_regex))
        cout << "is string" << endl;

    if (boost::regex_match(punct, punct_regex))
        cout << "is punct\n";

    string a1 = "\\s*((//.*)|([0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")";
    string a2 = "|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\||\\p{Punct})?";

    string b1 = "(([0-9]+)|(\"(\\\\\"|\\\\\\\\|\\\\n|[^\"])*\")";
    string b2 = "|[A-Z_a-z][A-Z_a-z0-9]*|==|<=|>=|&&|\\|\\||\\p{Punct})?";

    string all_pattern = b1 + b2;
    string all = "int";
    boost::regex all_regex(all_pattern);

    cout << "-----\n";
    boost::cmatch matcher;
    bool r = boost::regex_match(all.c_str(), matcher, all_regex);
    if (r)
    {
        int i = 0;
        for (auto t = matcher.begin(); t != matcher.end(); t++, i++)
        {
            cout << i << ":" << *t << endl;
        }
    }

    return 0;
}