/*
** new_cor_line.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 15:30:00 2014 Laurent Fourrier
** Last update Sat Apr  5 10:54:53 2014 Laurent Fourrier
*/

#include <tsys.h>
#include "reader.h"

t_cor_line	*new_cor_line()
{
  t_cor_line	*rtn;

  if ((rtn = ts_malloc(sizeof(t_cor_line))) == NULL)
    return (NULL);
  rtn->label = NULL;
  rtn->instruction = NULL;
  rtn->args = NULL;
  rtn->p_args = NULL;
  rtn->next = NULL;
  return (rtn);
}
