/*
    What this program should be able to do:
        - Read a line of text from the user
        - Parse/ Separate the command and arguments
        - Execute the command; fork() + execvp()
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
    //while (1 || sig)
    //get_command();
    //parse_command();
    //exec_command();
    
    while(1)
    {
        cmd = get_command();
        count = word_count(cmd);
        parsedCmd = parse_command(cmd, count);
        exec_command(parsedCmd);

        free(cmd);
        for(int i = 0; i < count; i++)
        {
            free(*(parsedCmd+i));
        }
        free(parsedCmd);
    }

    return 0;
}