/*
** read_cor_instruct.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 15:28:56 2014 Laurent Fourrier
** Last update Sat Apr  5 14:06:02 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "reader.h"

void		add_cor_line(t_cor_file *cor, t_cor_line *line)
{
  t_cor_line	*cur;

  if (cor->first_line == NULL)
    cor->first_line = line;
  else
    {
      cur = cor->first_line;
      while (cur->next)
	cur = cur->next;
      cur->next = line;
    }
}

char		rcor_line_is_empty(t_cor_line *line)
{
  return (utl_strcmp(line->label, "") == 0 &&
	  utl_strcmp(line->instruction, "") == 0);
}

char		rcor_is_label(char *str)
{
  while (*str)
    {
      if (*str == ':')
	return (1);
      else if (*str == ' ' || *str == '\t')
	return (0);
      str++;
    }
  return (0);
}

void		rcor_format_args(char **args)
{
  while (*args)
    {
      utl_strdelc(*args, " \t");
      args++;
    }
}

int		read_cor_instruct(char *line, t_cor_file *cor, int line_nbr)
{
  char		*args;
  t_cor_line	*rtn;

  if ((rtn = new_cor_line()) == NULL)
    return (-1);
  if (rcor_is_label(line))
    {
      rtn->label = get_next_word(line, ":", &line);
      line++;
    }
  else
    rtn->label = utl_strcpy("");
  rtn->instruction = get_next_word(line, " \t", &line);
  args = utl_strcpy(line);
  rtn->args = str_to_wordarr(args, ",");
  rcor_format_args(rtn->args);
  rtn->nbr = line_nbr;
  free(args);
  if (rcor_line_is_empty(rtn))
    free_cor_line(rtn);
  else
    add_cor_line(cor, rtn);
  return (1);
}
