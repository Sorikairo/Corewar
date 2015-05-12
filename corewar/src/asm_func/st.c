/*
** st.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  9 10:45:27 2014 Laurent Fourrier
** Last update Sun Apr 13 14:39:39 2014 Laurent Fourrier
*/

#include "arena.h"
#include "command.h"
#include "champion.h"

void	asm_st(t_arena *arena, t_process *caller, t_command *cmd)
{
  if (cmd->args[1].type == T_REG)
    {
      caller->reg[cmd->args[1].u_value.idx % REG_NUMBER] =
	caller->reg[cmd->args[0].u_value.idx % REG_NUMBER];
    }
  else if (cmd->args[1].type == T_IND)
    {
      write_memory_data_be(arena, &caller->reg[cmd->args[0].u_value.idx
					       % REG_NUMBER],
			   caller->pc + (cmd->args[1].u_value.addr % IDX_MOD),
			   4);
    }
}
