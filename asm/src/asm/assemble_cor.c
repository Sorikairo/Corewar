/*
** assemble_cor.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 04:22:47 2014 Laurent Fourrier
** Last update Sun Mar 30 17:52:38 2014 Laurent Fourrier
*/

#include <tio.h>
#include "asm.h"

int		print_file_error(char *file, char *msg)
{
  write_str(g_fstdout, "Error: ");
  write_str(g_fstdout, file);
  write_str(g_fstdout, ": ");
  write_str(g_fstdout, msg);
  write_char(g_fstdout, '\n');
  flush_file(g_fstdout);
  return (-1);
}

int		assemble_cor(char *input, char *output)
{
  t_file	*f_input;
  t_file	*f_output;

  f_input = open_file(input, FILE_R);
  if (!is_readable(f_input))
    return (print_file_error(input, "cannot read file\n"));
  f_output = open_file(output, FILE_W);
  if (!is_writable(f_output))
    return (print_file_error(output, "cannot write file\n"));
  assemble_fcor(f_input, f_output);
  close_file(f_input);
  close_file(f_output);
  return (0);
}
