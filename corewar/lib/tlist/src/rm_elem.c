/*
** rm_elem.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Jan 23 09:39:24 2014 Laurent Fourrier
** Last update Thu Jan 23 10:11:42 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tlist.h"

t_list		*list_remover(t_list *list, t_list *elem, void *param)
{
  if (elem == param)
    {
      if (elem->next == elem)
	{
	  free(elem);
	  return (NULL);
	}
      else
	{
	  elem->prev->next = elem->next;
	  elem->next->prev = elem->prev;
	  free(elem);
	}
    }
  return (list);
}

t_list	*tl_rm_elem(t_list *list, t_list *elem)
{
  return (tl_iterate(list, elem, &list_remover));
}
