/*
** lld.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 00:45:00 2014 Laurent Fourrier
** Last update Sun Apr 13 14:42:49 2014 Laurent Fourrier
*/

#include "utils.h"
#include "arena.h"
#include "command.h"
#include "champion.h"
#include "op.h"

void	asm_lld(t_arena *arena, t_process *caller, t_command *cmd)
{
  int	value;

  if (cmd->args[0].type == T_REG)
    value = caller->reg[cmd->args[0].u_value.idx % REG_NUMBER];
  else if (cmd->args[0].type == T_IND)
    value = get_indirect_value(arena, caller->pc + (cmd->args[0].u_value.addr));
  caller->reg[cmd->args[1].u_value.idx % REG_NUMBER] = value;
  caller->carry = !(caller->reg[cmd->args[1].u_value.idx % REG_NUMBER]);
}
