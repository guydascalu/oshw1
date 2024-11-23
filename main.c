#include <stdio.h>
#include <stdbool.h>
#include "defines.h"
#include "functions.h"

int main (void)
{
    char user_input[MAX_LINE_LENGTH] = {'\0'};

    // st_command bg_cmds[MAX_NUM_BG_COMMANDS];
	// st_command fg_cmd;


    while(true)
    {
        printf(TERMINAL_PROMPT);
        // read line into buffer
		if ((fgets(user_input,MAX_LINE_LENGTH,stdin) == NULL) /*&& validate_input() */)
		{
			printf(INVALID_COMMAND_MSG);
		}
		else{
			// printf("user entered: %s",user_input);
			e_cmd type = get_cmd_type(user_input,MAX_LINE_LENGTH); 

			switch (type)
			{
				case e_cmd_none:
				break;
				case e_cmd_cd:
				{
					printf("TODO: Implement cd :)\n");
				}
				break;
				case e_cmd_jobs:
				{
					printf("TODO: Implement jobs :)\n");
				}
				break;
				case e_cmd_exit:
				{
					printf("TODO: Implement exit :)\n");
				}
				break;
				case e_cmd_external:
				{
					printf("TODO: Implement external :)\n");
				}
				break;
				case e_cmd_invalid:
				default:
				{
					printf(INVALID_COMMAND_MSG);
				}
			}

			// fork and exec command

				// if child, execute command and exit
				// if parent, store pid and argument in buffer
		}

        // check all oher
    }
    return 0;
}