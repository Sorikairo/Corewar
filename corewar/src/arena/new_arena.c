/*
** new_arena.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 16:13:00 2014 Laurent Fourrier
** Last update Tue Apr  8 21:17:26 2014 Laurent Fourrier
*/

#include <stddef.h>
#include "arena.h"
#include "op.h"

void		reset_memory(char *memory)
{
  int		it;

  it = 0;
  while (it < MEM_SIZE)
    memory[it++] = 0;
}

t_arena		new_arena()
{
  t_arena	rtn;

  reset_memory(rtn.memory);
  rtn.last_id = 0;
  rtn.playing = 1;
  rtn.live_count = 0;
  rtn.cycle_to_die = CYCLE_TO_DIE;
  rtn.processes = NULL;
  rtn.champions = NULL;
  return (rtn);
}
