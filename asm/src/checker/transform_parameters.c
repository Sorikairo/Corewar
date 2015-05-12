/*
** transform_parameters.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  2 12:50:13 2014 Laurent Fourrier
** Last update Sat Apr  5 15:26:11 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "utils.h"
#include "reader.h"
#include "checker.h"

char		*g_param_error[] =
  {
    "unknown error. Shit happened.\n",
    "register is not a number\n",
    "register is out of bounds and does not exists\n",
    "label does not exists\n",
    "direct value is not a number\n",
    "indirect value is not a number\n",
    NULL
  };

int		get_param_error_size()
{
  int		rtn;

  rtn = 0;
  while (g_param_error[rtn] != NULL)
    rtn++;
  return (rtn);
}

void		param_error(int err_id, int line)
{
  char		*line_str;
  int		size;

  size = get_param_error_size();
  if (err_id < 0 || err_id >= size)
    err_id = 0;
  write_str(g_fstdout, "Error line ");
  line_str = utl_itoa(line);
  write_str(g_fstdout, line_str);
  free(line_str);
  write_str(g_fstdout, ": ");
  write_str(g_fstdout, g_param_error[err_id]);
  flush_file(g_fstdout);
}

int		transform_parameters_line(t_cor_line *line, t_label *label)
{
  int		it;
  int		len;

  len = get_wordarr_len(line->args);
  line->p_args = xmalloc(len * sizeof(t_cor_arg));
  it = 0;
  while (it < len)
    {
      line->p_args[it] = to_cor_arg(line->args[it], line->mempos, label);
      if (line->p_args[it].type == T_ERR)
	{
	  param_error(line->p_args[it].val, line->nbr);
	  return (-1);
	}
      it++;
    }
  return (0);
}

int		transform_parameters(t_cor_file *file, t_label *label)
{
  t_cor_line	*line;

  line = file->first_line;
  while (line)
    {
      if (transform_parameters_line(line, label) == -1)
	return (-1);
      line = line->next;
    }
  return (0);
}
