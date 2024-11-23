#include <stdlib.h>
#include "cmds_mngr.h"
	
st_command bg_cmds[MAX_NUM_BG_COMMANDS];
st_command fg_cmd;

/* set all commands empty */
void init_cmds (void)
{
	for(int i = 0 ; i < MAX_NUM_BG_COMMANDS ; i++)
	{
		bg_cmds[i].is_finished = true;
		bg_cmds[i].num_args=0;

		for(int j = 0 ; j < MAX_NUM_ARGUMENTS ; j++)
		{
			bg_cmds[i].cmd_args[j] = 0;
		}
	}
}

/* get background command-handle */
st_command* get_bg_ch(void)
{
	for(int i = 0 ; i < MAX_NUM_BG_COMMANDS ; i++)
	{
		if (bg_cmds[i].is_finished == true)
			return &(bg_cmds[i]);
	}
	
	return NULL;
}

/* get forground command-handle */
st_command* get_fg_ch(void)
{
	return &fg_cmd;
}

/* clean all malloc'd strings */
int remove_command( st_command* command)
{
	command->is_finished = true;
	command->num_args = 0;
	for(int i = 0 ; i < MAX_NUM_ARGUMENTS ; i++)
	{
		if(command->cmd_args[i] != NULL)
			free(command->cmd_args[i]);
	}

	return 0;
}