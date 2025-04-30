#include "shell.h"

char* get_command()
{
    char *line = NULL;
    size_t len = 0;
    size_t nread;

    printf("$ ");
    nread = getline(&line, &len, stdin);
    
    //get input
    printf("Retrieved line of length %zd:\n", nread);
    fwrite(line, nread, 1, stdout);
    
    return line;
 
}

int word_count(const char* cmd)
{
    int count = 0;
    int inWord = 0;

    while(*cmd)
    {
        if(*cmd == ' ' || *cmd == '\t' || *cmd == '\n') inWord = 0;
        else if(inWord == 0)
        {
            inWord = 1;
            count++;
        }
        cmd++;
    }

    return count;
}

char** parse_command(const char* cmd, const int count)
{
    char *str = strdup(cmd);
    char **parsedCmd;
    int index = 0;

    parsedCmd = (char**) malloc(count * sizeof(char*));
    if(!parsedCmd)
    {
        perror("error allocating parsed command");
    }

    char *token = strtok(str, " ");

    while(token != NULL)
    {
        *(parsedCmd+index) = strdup(token);
        token = strtok(NULL, " ");
        //printf("parsed word is %s\n", *(parsedCmd+index));
        index++;
    }

    free(str);
    return parsedCmd;
}