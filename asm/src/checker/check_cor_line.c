/*
** check_cor_line.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 17:25:41 2014 Laurent Fourrier
** Last update Wed Mar 26 17:08:10 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tio.h>
#include <tutils.h>
#include "reader.h"
#include "checker.h"

int	put_syntax_error(char *err, int line_nbr)
{
  write_str(g_fstdout, "Syntax error at line ");
  write_str(g_fstdout, utl_itoa(line_nbr));
  write_str(g_fstdout, ": ");
  write_str(g_fstdout, err);
  write_char(g_fstdout, '\n');
  flush_file(g_fstdout);
  return (-1);
}

int	check_cor_line(t_cor_line *line)
{
  if (line->instruction != NULL && utl_strcmp(line->instruction, ""))
    {
      if (!is_valid_mnemonic(line->instruction))
	return (put_syntax_error("instruction not recognized", line->nbr));
      if (!is_valid_args_nbr(line->instruction, line->args))
	return (put_syntax_error("number of arguments invalid", line->nbr));
      if (!is_valid_args(line->instruction, line->args))
	return (put_syntax_error("bad arguments", line->nbr));
    }
  return (0);
}
