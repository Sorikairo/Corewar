/*
** read_cor_line.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 20 14:27:09 2014 Laurent Fourrier
** Last update Wed Mar 26 16:50:19 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include <tutils.h>
#include "reader.h"

char	*read_cor_string(char *str)
{
  char	*rtn;
  char	**arr;

  arr = fmt_str_to_wordarr(str, " \t");
  if (arr == NULL)
    return (NULL);
  if (arr[0] == NULL || arr[1] == NULL)
    {
      destroy_wordarr(arr);
      return (NULL);
    }
  rtn = utl_strcpy(arr[1]);
  destroy_wordarr(arr);
  return (rtn);
}

int	read_cor_line(t_file *file, t_cor_file *cor, int line_nbr)
{
  char	*line;
  int	rtn;

  line = read_line(file);
  if (line == NULL)
    rtn = 0;
  else if (utl_strncmp(line, ".name", 5) == 0)
    {
      cor->name = read_cor_string(line);
      rtn = (cor->name == NULL) ? -1 : 1;
    }
  else if (utl_strncmp(line, ".comment", 8) == 0)
    {
      cor->comment = read_cor_string(line);
      rtn = (cor->comment == NULL) ? -1 : 1;
    }
  else
    rtn = read_cor_instruct(line, cor, line_nbr);
  free(line);
  return (rtn);
}
