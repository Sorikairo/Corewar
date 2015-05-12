/*
** label_exists.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 02:58:29 2014 Laurent Fourrier
** Last update Sat Mar 29 02:59:19 2014 Laurent Fourrier
*/

#include <tutils.h>
#include "checker.h"

char		label_exists(t_label *list, char *name)
{
  while (list)
    {
      if (utl_strcmp(list->name, name) == 0)
	return (1);
      list = list->next;
    }
  return (0);
}
