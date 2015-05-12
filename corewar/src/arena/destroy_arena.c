/*
** destroy_arena.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 13:33:59 2014 Laurent Fourrier
** Last update Tue Apr  8 15:52:26 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tlist.h>
#include "arena.h"

t_list		*destroy_champion_list(t_list *list, t_list *cur, void *param)
{
  t_champion	*cur_champ;

  cur_champ = cur->data;
  free(cur_champ->name);
  free(cur_champ);
  free(cur);
  return (list);
}

t_list		*destroy_process_list(t_list *list, t_list *cur, void *param)
{
  free(cur->data);
  free(cur);
  return (list);
}

void		destroy_arena(t_arena *arena)
{
  arena->processes = tl_iterate(arena->processes, NULL, &destroy_process_list);
  arena->champions = tl_iterate(arena->champions, NULL, &destroy_champion_list);
}
