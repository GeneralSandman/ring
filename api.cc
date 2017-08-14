#include "api.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
void handle_error(const char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(-1);
}

void handle_error(const std::string &msg){
    const char *m=msg.c_str();
    handle_error(m);
}