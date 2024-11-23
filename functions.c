#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "defines.h"
#include "functions.h"

char* g_cmd_strings[] = 
{
	[e_cmd_jobs] = "jobs",
	[e_cmd_cd] = "cd",
	[e_cmd_exit] = "exit",
};

e_cmd get_cmd_type(char* user_input, int size)
{
	if ((user_input == NULL) || (user_input[0] == ' '))
		return e_cmd_invalid;
    
	if (user_input[0] == '\n')
		return e_cmd_none;



	// locate first space or newline
	char *p_delim;
	int delim_idx;

	// skip leading spaces
	while (*user_input == ' ')
    	user_input++;

    p_delim = strchr(user_input, ' ');
    if (p_delim != NULL) {
        delim_idx = p_delim - user_input;
    } else {
        p_delim = strchr(user_input, '\n');
        if (p_delim != NULL) {
            delim_idx = p_delim - user_input;
        } else {
            return e_cmd_invalid; 
        }
    }

	// check if the input is one of our internal commands or not
	for (e_cmd cmd = e_cmd_jobs ; cmd < e_cmd_none ; cmd++)
	{
		if ((strlen(g_cmd_strings[cmd]) == delim_idx) && (memcmp(g_cmd_strings[cmd],user_input,delim_idx) == 0))
			return cmd;
	}

	return e_cmd_external;
}