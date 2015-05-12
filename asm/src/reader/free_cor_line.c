/*
** free_cor_line.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 15:31:36 2014 Laurent Fourrier
** Last update Sat Apr  5 10:31:20 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tutils.h>
#include "reader.h"

void	free_cor_line(t_cor_line *line)
{
  free(line->label);
  free(line->instruction);
  destroy_wordarr(line->args);
  free(line->p_args);
  free(line);
}
