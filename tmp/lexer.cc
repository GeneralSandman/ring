#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int token;           // current token
char *src, *old_src; // pointer to source code string;
int poolsize;        // default size of text/data/stack
int line;            // line number
string identifier;
int token_val;
string string_result;

enum
{
    Number,
    Id,
    //String,
    If,
    Else,
    While,
    For,
    Incre,
    Decre, //++,--
    Add,
    Sub,
    Multi,
    Div,
    Mod,   //+,-,*,/,%
    Power, // ^^
    Assign,
    AddAssign,
    SubAssign,
    MultiAssign,
    DivAssign,
    ModAssign,
    //=,+=,-=,*=,/=,%=
    Eq,
    Ne,
    Lt,
    Gt,
    Le,
    Ge,
    //==,!=,<,>,<=,>=
    And,
    Or,
    Not,
    Xor,
    //bits:&,|,~,^
    LAnd,
    LOr,
    //logic:&&,||
    ShiftLeft,
    ShiftRight,
    BracketLeft, //[
    BracketRight //]
};

typedef enum
{
    Global,
    Local
}LocationType;

typedef enum{
    Int,
    String,
    Double,
    Struct,    
    List,
    Dict,
    Function,
    Class
}DataType;

set<string>ForbIdenti={"int","string","double","struct",
                        "list","dict","class"};

class Identifier
{
  public:
    int m_nLocation;
    string m_nFile;
    int m_nHash;
    string m_nName;
    void *m_nValue;
};

vector<Identifier *> IdTable;

void next()
{

    while (token = *src)
    {
        src++;

        if (token == '\n')
        {
            line++;
        }
        else if (token == '/')
        {
            if (*src == '/')
            {
                while (*src != 0 && *src != '\n')
                {
                    src++;
                }
            }
            else
            {
                //divison sign
                return;
            }
        }
        else if (token == '`')
        {
            if (*(src++) == '`' && *(src++) == '`')
            {
                while (*src != 0 && *src != '`')
                {
                    src++;
                }

                if (*(src++) == '`' && *(src++) == '`' && *(src++) == '`')
                {
                    return;
                }
            }
        }
        else if (('a' <= token && token <= 'z') ||
                 ('A' <= token && token <= 'Z') ||
                 (token == '_'))
        {

            string id_name;
            id_name += token;

            while ((*src >= 'a' && *src <= 'z') ||
                   (*src >= 'A' && *src <= 'Z') ||
                   (*src >= '0' && *src <= '9') ||
                   (*src == '_'))
            {
                id_name += *src;
                src++;
            }
            if(ForbIdenti.find(id_name)!=ForbIdenti.end())
            {
                cout<<"this name is forbidden\n";
                exit(-1);
            }
            Identifier *new_id = new Identifier;            
            new_id->m_nName = id_name;
            new_id->m_nFile = "";
            new_id->m_nHash = 0;
            new_id->m_nLocation = 0;
            new_id->m_nValue = 0;

            IdTable.push_back(new_id);
            return;
        }
        else if ('0' <= token && token <= '9')
        {
            token_val = token - '0';
            while ('0' <= *src && *src <= '9')
            {
                token_val = token_val * 10 + *src - '0';
                src++;
            }
        }
        else if (token == '"' || token == '\'')
        {
            char string_start = token;
            string_result = "";
            while (*src != 0 &&
                   *src != '\'' &&
                   *src != '"')
            {
                string_result += *src;
                src++;
            }
            if (*src != string_start)
                string_result = "";
            src++;
        }
        else if (token == '=')
        {
            if (*src == '=')
            {
                src++;
                token = 1; //eq
            }
            else
            {
                token = 2; //assign
            }
            return;
        }
        else if (token == '!')
        {
            if (*src == '=')
            {
                src++;
                token = Ne; //ne
            }
            else
            {
                token = Not;
            }
            return;
        }
        else if (token == '+')
        {
            if (*src == '+')
            {
                src++;
                token = Incre; //incre
            }
            else if (*src == '=')
            {
                token = AddAssign; //add
            }
            else
            {
                token = Add;
            }
            return;
        }
        else if (token == '-')
        {
            if (*src == '-')
            {
                src++;
                token = Decre; //dec
            }
            else if (*src == '=')
            {
                token = SubAssign; //sub
            }
            else
            {
                token = Sub;
            }
            return;
        }
        else if (token == '*')
        {
            if (*src == '=')
            {
                src++;
                token = MultiAssign;
            }
            else
            {
                token = Multi;
            }
            return;
        }
        else if (token == '<')
        {
            if (*src == '=')
            {
                src++;
                token = Le; //le
            }
            else if (*src == '<')
            {
                src++;
                token = ShiftLeft; //shift left
            }
            else
            {
                token = Lt; //lt
            }
            return;
        }
        else if (token == '>')
        {
            if (*src == '=')
            {
                src++;
                token = Ge; //ge
            }
            else if (*src == '>')
            {
                src++;
                token = ShiftRight; //shift righr
            }
            else
            {
                token = Gt; //gt
            }
            return;
        }
        else if (token == '|')
        {
            if (*src == '|')
            {
                src++;
                token = LOr; //lor
            }
            else
            {
                token = Or; //or
            }
            return;
        }
        else if (token == '&')
        {
            if (*src == '&')
            {
                src++;
                token = LAnd; //land
            }
            else
            {
                token = And; //and
            }
            return;
        }
        else if (token == '^')
        {
            if (*src == '^')
            {
                src++;
                token = Power;
            }
            else
            {
                token = Xor; //
            }
            return;
        }
        else if (token == '%')
        {
            token = Mod;
            return;
        }
        else if (token == '[')
        {
            token = BracketLeft;
            return;
        }
        else if (token == ']')
        {
            token = BracketRight;
            return;
        }
        else if (token == '~')
        {
            token = Not;
            return;
        }
        else if (token == ',' ||
                 token == ';' ||
                 token == ':' ||
                 token == '(' ||
                 token == ')' ||
                 token == '{' ||
                 token == '}')
        {
            return; //return directly
        }
    }
}

void program()
{
    do
    {
        next();
    } while (token > 0);
}

int main(int argc, char **argv)
{
    int i, fd;
    argc--;
    argv++;
    poolsize = 256 * 1024; // arbitrary size
    line = 1;
    if ((fd = open(*argv, 0)) < 0)
    {
        printf("could not open(%s)\n", *argv);
        return -1;
    }
    if (!(src = old_src = (char *)malloc(poolsize)))
    {
        printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
    }
    // read the source file
    if ((i = read(fd, src, poolsize - 1)) <= 0)
    {
        printf("read() returned %d\n", i);
        return -1;
    }
    src[i] = 0; // add EOF character
    close(fd);
    program();
    free(old_src);

    for (auto t : IdTable)
    {
        cout << t->m_nName << endl;
        delete t;
        t = nullptr;
    }

    IdTable.erase(IdTable.begin(), IdTable.end());

    return 0;
}
