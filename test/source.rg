#include <iostream>
#include <string>
#include <fstream>

void readLine()
{
    std::ifstream fin("data.txt");
    std::string s;
    while (getline(fin, s))
    {
        std::cout << "Read from file: " << s << std::endl;
    }
}

int main(){

    readLine();
    return 0;
}