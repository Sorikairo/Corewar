/*
** destroy_list.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 16:46:38 2014 Laurent Fourrier
** Last update Tue Mar 25 16:53:36 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "checker.h"

void		destroy_label_list(t_label *list)
{
  t_label	*next;

  while (list)
    {
      next = list->next;
      free(list);
      list = next;
    }
}
