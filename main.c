/*
    To do:
        - Handle simple buit-in commands like cd and exit
        - Handle exit/ sigint cleanly; allow the user to type exit to quit
        ┌────────────┐
        │ Print Prompt│
        └─────┬──────┘
              ↓
        ┌────────────┐
        │ Read Input │
        └─────┬──────┘
              ↓
        ┌──────────────┐
        │ Parse Command│
        └─────┬────────┘
              ↓
        ┌─────────────┐
        │ fork() Child│
        └─────┬───────┘
              ↓
        ┌────┴─────┐
        │ In child │ execvp() program
        └────┬─────┘
             ↓
        ┌────┴─────┐
        │ In parent│ waitpid() child
        └──────────┘
*/


#include "shell.h"

int main(int argc, char *argv[])
{
    int count = 0;
    char *cmd;
    char **parsedCmd;
    int ret;
    
    while(1)
    {
        cmd = get_command();
        count = word_count(cmd);
        parsedCmd = parse_command(cmd, count);
        ret = exec_command(parsedCmd);
        if(ret == 0) break;
        else if(ret == 1)
        {
            chdir(parsedCmd[1]);
        }

        free(cmd);
        for(int i = 0; i < count; i++)
        {
            free(*(parsedCmd+i));
        }
        free(parsedCmd);
    }

    return 0;
}