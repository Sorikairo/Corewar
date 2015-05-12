/*
** and.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  9 16:36:00 2014 Laurent Fourrier
** Last update Sun Apr 13 14:28:09 2014 Laurent Fourrier
*/

#include "arena.h"
#include "command.h"
#include "champion.h"

void	asm_and(t_arena *arena, t_process *caller, t_command *cmd)
{
  caller->reg[cmd->args[2].u_value.idx % REG_NUMBER] =
    caller->reg[cmd->args[0].u_value.idx % REG_NUMBER] &
    caller->reg[cmd->args[1].u_value.idx % REG_NUMBER];
  caller->carry = !(caller->reg[cmd->args[2].u_value.idx % REG_NUMBER]);
}
