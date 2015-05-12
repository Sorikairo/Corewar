/*
** assemble_fcor.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 04:02:18 2014 Laurent Fourrier
** Last update Sat Apr  5 10:10:23 2014 Laurent Fourrier
*/

#include <tio.h>
#include "asm.h"
#include "writer.h"

int		assemble_fcor(t_file *input, t_file *output)
{
  t_parseinfo	parseinfo;

  parseinfo = parse_cor_file(input);
  if (!parseinfo.cor_file)
    {
      if (parseinfo.label_list)
	destroy_label_list(parseinfo.label_list);
      return (-1);
    }
  writer_cor_file(output, parseinfo.cor_file, parseinfo.label_list);
  flush_file(output);
  free_cor_file(parseinfo.cor_file);
  if (parseinfo.label_list)
    destroy_label_list(parseinfo.label_list);
  return (0);
}
