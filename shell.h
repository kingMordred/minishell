#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


char* get_command();
int word_count(const char*);
char** parse_command(const char*, const int);
int exec_command(char**);




#endif