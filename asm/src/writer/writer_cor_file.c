/*
** writer_cor_file.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 10:38:04 2014 Laurent Fourrier
** Last update Tue Apr  1 15:19:05 2014 Laurent Fourrier
*/

#include "utils.h"
#include "writer.h"
#include "checker.h"

void		writer_cor_file(t_file *file, t_cor_file *cor, t_label *label)
{
  t_cor_line	*line;

  writer_cor_header(file, cor);
  line = cor->first_line;
  while (line)
    {
      writer_cor_line(file, line, label);
      line = line->next;
    }
}
