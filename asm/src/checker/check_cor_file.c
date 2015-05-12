/*
** check_cor_file.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 17:22:33 2014 Laurent Fourrier
** Last update Wed Mar 26 16:28:14 2014 Laurent Fourrier
*/

#include "reader.h"
#include "checker.h"

int		check_cor_file(t_cor_file *cor)
{
  t_cor_line	*line;

  if (check_cor_header(cor) == -1)
    return (-1);
  line = cor->first_line;
  while (line)
    {
      if (check_cor_line(line) == -1)
	return (-1);
      line = line->next;
    }
  return (0);
}
