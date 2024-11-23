#include <stdlib.h>
#include <string.h>
#include "cmds_mngr.h"
#include "parser.h"

/* lut between strings and enums */
char* g_cmd_strings[] = 
{
	[e_cmd_jobs] = "jobs",
	[e_cmd_cd] = "cd",
	[e_cmd_exit] = "exit",
};

/* get the first word from a string not including spaces */
char* extract_first_word(char* input, int* return_size)
{
	// locate first space or newline
	char *p_delim;
	*return_size = 0;

	// skip leading spaces
	while (*input == ' ')
    	input++;

    p_delim = strchr(input, ' ');
    if (p_delim != NULL)
        *return_size = p_delim - input;
    else 
	{
        p_delim = strchr(input, '\n');
        if ((p_delim != NULL) && (p_delim >= (input+1))) // handle case where only word in \n
            *return_size = p_delim - input;
        else
            return NULL; 
    }
	
	return input;
}

/* check is a command ends with '&'*/
bool get_is_bg(char* user_input)
{
	char* p_delim;
	p_delim = strchr(user_input, '\n');
        if (p_delim != NULL && (p_delim > user_input))
		{
            return ('&' == *(p_delim-1));
		}
	return false;
}

/* cast the first word into the e_cmd enum */
e_cmd get_cmd_type(char* user_input)
{
	if (user_input == NULL)
		return e_cmd_invalid;
    
	if (user_input[0] == '\n')
		return e_cmd_none;

	int wordsize;
	char* first_word = extract_first_word(user_input, &wordsize);

	// check if the input is one of our internal commands or not
	for (e_cmd cmd = e_cmd_jobs ; cmd < e_cmd_none ; cmd++)
	{
		if ((strlen(g_cmd_strings[cmd]) == wordsize) && (memcmp(g_cmd_strings[cmd],first_word,wordsize) == 0))
			return cmd;
	}

	return e_cmd_external;
}

/* parse a command string into the command struct */
void parse_cmd_to_struct(char* input, int input_size, st_command* cmd)
{
	cmd->is_background = get_is_bg(input);
	cmd->cmd_type = get_cmd_type(input);
	memcpy(cmd->cmd_str, input, input_size);
	cmd->is_finished = false;

	int curr_word_size;
	char* curr_word = extract_first_word(input,&curr_word_size);
	
	while(curr_word != NULL)
	{
		(cmd->cmd_args)[cmd->num_args] = (char*)malloc(curr_word_size*sizeof(char) + 1);
		memcpy(cmd->cmd_args[cmd->num_args], curr_word, curr_word_size*sizeof(char));
		cmd->cmd_args[cmd->num_args][curr_word_size+1] = '\0';
		cmd->num_args++;
		while (*input == ' ')
    		input++;
		input += curr_word_size;

		curr_word = extract_first_word(input,&curr_word_size);
	}

}