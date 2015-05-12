/*
** sti.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 11 17:27:43 2014 Laurent Fourrier
** Last update Sun Apr 13 14:41:59 2014 Laurent Fourrier
*/

#include "arena.h"
#include "command.h"
#include "champion.h"
#include "op.h"

void	asm_sti(t_arena *arena, t_process *caller, t_command *cmd)
{
  int	address;

  if (cmd->args[1].type == T_REG)
    address = caller->reg[cmd->args[1].u_value.idx % REG_NUMBER];
  else if (cmd->args[1].type == T_DIR)
    address = cmd->args[1].u_value.nbr;
  else if (cmd->args[1].type == T_IND)
    address = get_indirect_value(arena, caller->pc +
				 (cmd->args[1].u_value.addr % IDX_MOD));
  if (cmd->args[2].type == T_REG)
    address += caller->reg[cmd->args[2].u_value.idx % REG_NUMBER];
  else if (cmd->args[2].type == T_DIR)
    address += cmd->args[2].u_value.nbr;
  write_memory_data_be(arena,
		       &caller->reg[cmd->args[0].u_value.idx % REG_NUMBER],
		       caller->pc + (address % IDX_MOD), 4);
}
