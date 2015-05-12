/*
** add_elem.c for tlist in /home/fourri_l/Projects/lib/tlist
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Jan 22 09:28:30 2014 Laurent Fourrier
** Last update Thu Jan 23 09:38:13 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include "tlist.h"

t_list		*new_list(void *data)
{
  t_list	*rtn;

  if ((rtn = ts_malloc(sizeof(t_list))) == NULL)
    return (NULL);
  rtn->prev = rtn;
  rtn->data = data;
  rtn->next = rtn;
  return (rtn);
}

t_list		*pushback_elem(t_list *list, void *data)
{
  t_list	*rtn;

  if ((rtn = ts_malloc(sizeof(t_list))) == NULL)
    return (NULL);
  rtn->prev = list->prev;
  rtn->data = data;
  rtn->next = list;
  list->prev->next = rtn;
  list->prev = rtn;
  return (list);
}

t_list	*tl_add_elem(t_list *list, void *data)
{
  return ((list == NULL) ? new_list(data) : pushback_elem(list, data));
}
