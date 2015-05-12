/*
** loop.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 16:42:42 2014 Laurent Fourrier
** Last update Sun Apr 13 14:31:23 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tlist.h>
#include "utils.h"
#include "arena.h"
#include "asm_func.h"
#include "op.h"

t_list		*process_routine(t_list *list, t_list *cur, void *param)
{
  char		*byte;
  t_arena	*arena;
  t_process	*proc;

  arena = param;
  proc = cur->data;
  if (proc->cycles_left > 0)
    proc->cycles_left--;
  else
    {
      if (proc->cycles_left == 0)
	call_asm_func(arena, proc);
      byte = get_memory_data(arena, proc->pc, 1);
      proc->cycles_left = get_op_info(*byte).nbr_cycles;
      free(byte);
    }
  return (list);
}

t_list		*check_champion(t_list *list, t_list *cur, void *param)
{
  t_arena	*arena;
  t_champion	*champ;

  arena = param;
  champ = cur->data;
  if (champ->alive)
    {
      champ->life++;
      if (champ->life >= arena->cycle_to_die)
	kill_champion(arena, champ);
    }
  return (list);
}

void		arena_loop(t_arena *arena)
{
  while (arena->playing)
    {
      arena->processes = tl_iterate(arena->processes, arena, &process_routine);
      arena->champions = tl_iterate(arena->champions, arena, &check_champion);
    }
}
