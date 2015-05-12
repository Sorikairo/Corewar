/*
** read_cor_file.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 14:13:36 2014 Laurent Fourrier
** Last update Sun Apr 13 17:24:14 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include <tio.h>
#include <tutils.h>
#include "reader.h"

void		print_syntax_error(int line_count)
{
  write_str(g_fstdout, "Error: bad syntax at line ");
  write_str(g_fstdout, utl_itoa(line_count));
  write_char(g_fstdout, '\n');
  flush_file(g_fstdout);
}

void		print_too_big()
{
  write_str(g_fstdout, "Error: file is too big\n");
  flush_file(g_fstdout);
  exit(0);
}

t_cor_file	*read_cor_file(t_file *file)
{
  int		line_rtn;
  int		line_count;
  t_cor_file	*rtn;

  if ((rtn = new_cor_file()) == NULL)
    return (NULL);
  line_count = 1;
  while ((line_rtn = read_cor_line(file, rtn, line_count)) != 0)
    {
      if (line_rtn == -1)
	{
	  print_syntax_error(line_count);
	  free_cor_file(rtn);
	  return (NULL);
	}
      line_count++;
      if (line_count >= 10000)
	print_too_big();
    }
  return (rtn);
}
