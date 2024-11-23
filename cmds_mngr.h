#pragma once
#include "defines.h"

typedef struct
{
    bool is_background;
    bool is_finished;
	e_cmd cmd_type;
    int pid;
    char cmd_str[MAX_LINE_LENGTH];
	char* cmd_args[MAX_NUM_ARGUMENTS];
	int num_args;
}
st_command;

void init_cmds (void);
st_command* get_bg_ch(void);
st_command* get_fg_ch(void);
int remove_command();

