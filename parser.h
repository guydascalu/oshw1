#pragma once
#include "cmds_mngr.h"

bool get_is_bg(char* user_input);
char* extract_first_word(char* input, int* return_size);
e_cmd get_cmd_type(char* user_input);
void parse_cmd_to_struct(char* input, int input_size, st_command* cmd);
