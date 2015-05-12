/*
** label_list_append.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 15:57:13 2014 Laurent Fourrier
** Last update Tue Mar 25 16:51:26 2014 Laurent Fourrier
*/

#include <stddef.h>
#include "utils.h"
#include "checker.h"

t_label		*label_list_append(t_label *list, char *name, int mem_pos)
{
  t_label	*rtn;
  t_label	*current;

  rtn = xmalloc(sizeof(t_label));
  rtn->name = name;
  rtn->mem_pos = mem_pos;
  rtn->next = NULL;
  if (list == NULL)
    return (rtn);
  current = list;
  while (current->next)
    current = current->next;
  current->next = rtn;
  return (list);
}
