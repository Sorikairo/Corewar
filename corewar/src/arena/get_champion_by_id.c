/*
** get_champion_by_id.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 21:00:27 2014 Laurent Fourrier
** Last update Tue Apr  8 21:05:17 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tlist.h>
#include "arena.h"
#include "champion.h"

t_champion	*get_champion_by_id(t_arena *arena, int id)
{
  t_list	*first;
  t_list	*cur;
  t_champion	*rtn;

  cur = arena->champions;
  first = NULL;
  while (cur != first)
    {
      if (!first)
	first = cur;
      rtn = cur->data;
      if (rtn->id == id)
	return (rtn);
      cur = cur->next;
    }
  return (NULL);
}
