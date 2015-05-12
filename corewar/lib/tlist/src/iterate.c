/*
** iterate.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Jan 23 09:46:41 2014 Laurent Fourrier
** Last update Tue Apr  8 14:50:03 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "tlist.h"

t_list		*tl_iterate(t_list *list, void *param, it_func func)
{
  int		first;
  t_list	*cur;
  t_list	*next;

  first = 1;
  cur = list;
  while (cur != NULL && list != NULL && (first || cur != list))
    {
      next = cur->next;
      list = func(list, cur, param);
      cur = next;
      first = 0;
    }
  return (list);
}
