/*
** new_cor_file.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 14:20:48 2014 Laurent Fourrier
** Last update Thu Mar 20 15:54:33 2014 Laurent Fourrier
*/

#include <tsys.h>
#include "reader.h"

t_cor_file	*new_cor_file()
{
  t_cor_file	*rtn;

  if ((rtn = ts_malloc(sizeof(t_cor_file))) == NULL)
    return (NULL);
  rtn->name = NULL;
  rtn->comment = NULL;
  rtn->first_line = NULL;
  return (rtn);
}
