/*
** lldi.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 00:57:14 2014 Laurent Fourrier
** Last update Sun Apr 13 14:43:15 2014 Laurent Fourrier
*/

#include "arena.h"
#include "command.h"
#include "champion.h"
#include "op.h"

void	asm_lldi(t_arena *arena, t_process *caller, t_command *cmd)
{
  int	value;

  value = 0;
  if (cmd->args[0].type == T_REG)
    value = caller->reg[cmd->args[0].u_value.idx % REG_NUMBER];
  else if (cmd->args[0].type == T_DIR)
    value = cmd->args[0].u_value.nbr;
  else if (cmd->args[0].type == T_IND)
    value = get_indirect_value(arena, caller->pc + cmd->args[0].u_value.addr);
  if (cmd->args[1].type == T_REG)
    value += caller->reg[cmd->args[1].u_value.idx % REG_NUMBER];
  else if (cmd->args[1].type == T_DIR)
    value += cmd->args[1].u_value.nbr;
  caller->reg[cmd->args[2].u_value.idx % REG_NUMBER] = value;
  caller->carry = !(caller->reg[cmd->args[2].u_value.idx % REG_NUMBER]);
}
