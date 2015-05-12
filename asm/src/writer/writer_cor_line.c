/*
** writer_cor_line.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  1 14:37:43 2014 Laurent Fourrier
** Last update Sat Apr  5 14:10:44 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include "writer.h"
#include "checker.h"
#include "op.h"
#include "utils.h"

void	writer_cor_line(t_file *file, t_cor_line *line, t_label *label)
{
  char	*buffer;
  int	it;
  op_t	op;

  op = get_op(line->instruction);
  buffer = xmalloc(1);
  buffer[0] = op.code;
  write_data(file, buffer, 1);
  free(buffer);
  if (line_has_parambyte(op.code))
    writer_cor_parambyte(file, line->args);
  it = 0;
  while (it < op.nbr_args)
    writer_cor_arg(file, line->p_args[it++]);
}
