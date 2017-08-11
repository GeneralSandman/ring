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
using namespace std;

int token;           // current token
char *src, *old_src; // pointer to source code string;
int poolsize;        // default size of text/data/stack
int line;            // line number
string identifier;
int token_val;
string string_result;
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
            identifier += token;

            while ((*src >= 'a' && *src <= 'z') ||
                   (*src >= 'A' && *src <= 'Z') ||
                   (*src >= '0' && *src <= '9') ||
                   (*src == '_'))
            {
                identifier += *src;
                src++;
            }
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
            char string_start=token;
            string_result="";
            while (*src != 0 &&
                   *src != '\'' &&
                   *src != '"')
            {
                string_result+=*src;
                src++;
            }
            if(*src!=string_start)
                 string_result="";
            src++;
        }
        else if(token=='='){

        }
        else if(token=='!'){

        }
        else if(token=='+'){

        }
        else if(token =='-'){

        }
        else if(token =='*'){

        }
        else if(token=='<'){

        }
        else if(token=='>'){

        }
        else if(token=='|'){

        }
        else if(token=='&'){

        }
        else if(token=='^'){

        }
        else if(token=='%'){
            
        }
        
    }
}

void program()
{
    next(); // get next token
    while (token > 0)
    {
        // printf("token is: %c\n", token);
        next();
    }
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

    cout << "line:" << line << endl;
    cout << "identifier:" << identifier << endl;
    cout << "number:" << token_val << endl;
    cout << "string:" << string_result << endl;
    return 0;
}
