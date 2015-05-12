/*
** kill_champion.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 04:20:16 2014 Laurent Fourrier
** Last update Sun Apr 13 12:56:12 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tlist.h>
#include "arena.h"
#include "champion.h"

t_list		*kill_processes(t_list *list, t_list *cur, void *param)
{
  t_process	*proc;
  t_champion	*champ;

  champ = param;
  proc = cur->data;
  if (proc->parent == champ)
    {
      free(proc);
      return (tl_rm_elem(list, cur));
    }
  return (list);
}

void	kill_champion(t_arena *arena, t_champion *champion)
{
  arena->processes = tl_iterate(arena->processes, champion, &kill_processes);
  champion->alive = 0;
  update_game_state(arena);
}
