#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "defines.h"
#include "cmds_mngr.h"
#include "parser.h"

/* main */
int main (void)
{
    char user_input[MAX_LINE_LENGTH] = {'\0'};
	init_cmds();
	st_command* curr_command = NULL;
	int command_length = 0;
	bool is_need_exec = false;

    while(true)
    {
		is_need_exec = false;
        printf(TERMINAL_PROMPT);
        // read line into struct
		if (fgets(user_input,MAX_LINE_LENGTH,stdin) == NULL)
		{
			printf(INVALID_COMMAND_MSG);
		}
		else{
			command_length = strlen(user_input);
			bool is_bg = get_is_bg(user_input);
			e_cmd type = get_cmd_type(user_input); 
			
			switch (type)
			{
				case e_cmd_cd:
				case e_cmd_jobs:
				case e_cmd_exit:
				case e_cmd_external:
				{
					// needs handling -> cast into struct
					if(is_bg)
					{
						curr_command = get_bg_ch();
						if(curr_command == NULL)
						{
							printf(TOO_MANY_COMMANDS_MSG);
							break;
						}
					}
					else
						curr_command = get_fg_ch();
					
					parse_cmd_to_struct(user_input,command_length,curr_command);
					is_need_exec = true;
				}
				break;
				case e_cmd_none:
				break;
				case e_cmd_invalid:
				default:
				{
					printf(INVALID_COMMAND_MSG);
				}
			}

			if(is_need_exec)
			{

			// fork and exec command

				// if child, execute command and exit
				// if parent, store pid and argument in buffer. don't forget!!
			
			}
		}

        // check all bg processes and reap them if needed
		// if reaped, print appropriate prompt 
    }
    return 0;
}