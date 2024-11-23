#pragma once
#include <stdbool.h>
/* ~~~~~~~~~~~~~~~ defines ~~~~~~~~~~~~~~~ */

// prompt strings
#define TERMINAL_PROMPT "hw1shell$ "
#define INVALID_COMMAND_MSG "hw1shell: invalid command\n"
#define TOO_MANY_COMMANDS_MSG "hw1shell: too many background commands running\n"

// print macros
#define PROCESS_STARTED(pid) ("hw1shell: pid %d started\n", pid) // use inside a printf
#define PROCESS_FINISHED(pid) ("hw1shell: pid %d finished\n", pid) // use inside a printf
#define PROCESS_ERROR(name,errno) ("hw1shell: %s failed, errno %d", name, errno) // use inside a printf

// CONSTANTS
#define BACKGOUND_FLAG_CHAR '&'
#define MAX_LINE_LENGTH 1024 
#define MAX_NUM_ARGUMENTS 64 
#define MAX_NUM_BG_COMMANDS 4

/* ~~~~~~~~~~~~~~~ structs ~~~~~~~~~~~~~~~ */

typedef enum 
{
    e_cmd_jobs = 0,
    e_cmd_cd,
    e_cmd_exit,
	e_cmd_none,	
	e_cmd_invalid,

    e_cmd_external,
}e_cmd;
