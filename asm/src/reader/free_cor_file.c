/*
** free_cor_file.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 14:23:56 2014 Laurent Fourrier
** Last update Thu Mar 20 19:51:12 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "reader.h"

void		free_cor_file(t_cor_file *file)
{
  t_cor_line	*next;

  free(file->name);
  free(file->comment);
  while (file->first_line)
    {
      next = file->first_line->next;
      free_cor_line(file->first_line);
      file->first_line = next;
    }
  free(file);
}
