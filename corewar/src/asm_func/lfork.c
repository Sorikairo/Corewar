/*
** lfork.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 01:01:39 2014 Laurent Fourrier
** Last update Sun Apr 13 01:04:20 2014 Laurent Fourrier
*/

#include <tsys.h>
#include "utils.h"
#include "arena.h"
#include "command.h"
#include "champion.h"
#include "op.h"

/*
**         |---
** --------|---  < THIS IS A TRIDENT ( not a fork >:( )
**         |---
*/
void		asm_lfork(t_arena *arena, t_process *caller, t_command *cmd)
{
  t_process	*to_add;

  to_add = xmalloc(sizeof(t_process));
  to_add->carry = caller->carry;
  to_add->cycles_left = 0;
  ts_memcpy(caller->reg, to_add->reg, REG_NUMBER * sizeof(int));
  to_add->pc = caller->pc + cmd->args[0].u_value.nbr;
  arena->processes = tl_add_elem(arena->processes, to_add);
}
