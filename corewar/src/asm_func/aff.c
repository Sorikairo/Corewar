/*
** aff.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 01:04:53 2014 Laurent Fourrier
** Last update Sun Apr 13 14:43:59 2014 Laurent Fourrier
*/

#include <tio.h>
#include "arena.h"
#include "command.h"
#include "champion.h"

void	asm_aff(t_arena *arena, t_process *caller, t_command *cmd)
{
  write_char(g_fstdout, (char)(caller->reg[cmd->args[0].u_value.idx
					   % REG_NUMBER] & 0xFF));
  flush_file(g_fstdout);
}
