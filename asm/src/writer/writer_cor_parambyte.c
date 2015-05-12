/*
** writer_cor_parambyte.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  1 15:19:18 2014 Laurent Fourrier
** Last update Tue Apr  1 15:24:58 2014 Laurent Fourrier
*/

#include <tio.h>
#include "op.h"

void	writer_cor_parambyte(t_file *file, char **args)
{
  char	parambyte;
  int	it;

  it = 0;
  parambyte = 0;
  while (args[it])
    {
      if (args[it][0] == 'r')
	parambyte += 1 << (2 * (3 - it));
      else if (args[it][0] == '%')
	parambyte += 2 << (2 * (3 - it));
      else
	parambyte += 3 << (2 * (3 - it));
      it++;
    }
  write_char(file, parambyte);
}
