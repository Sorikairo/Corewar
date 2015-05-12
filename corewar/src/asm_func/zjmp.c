/*
** zjmp.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  9 16:57:18 2014 Laurent Fourrier
** Last update Sat Apr 12 22:49:15 2014 Laurent Fourrier
*/

#include "arena.h"
#include "command.h"
#include "champion.h"
#include "op.h"

void	asm_zjmp(t_arena *arena, t_process *caller, t_command *cmd)
{
  if (caller->carry)
    caller->pc += (cmd->args[0].u_value.nbr % IDX_MOD);
}
