/*
** change_filext.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Mar 29 11:22:52 2014 Laurent Fourrier
** Last update Sun Mar 30 17:49:21 2014 Laurent Fourrier
*/

#include <tutils.h>
#include "utils.h"

char	*create_filename(char *base, char *new_ext, int base_size)
{
  char	*rtn;
  int	it;
  int	size;

  size = base_size + utl_strlen(new_ext) + 2;
  rtn = xmalloc(size);
  it = 0;
  while (it < base_size)
    {
      rtn[it] = base[it];
      it++;
    }
  while (*new_ext)
    rtn[it++] = *new_ext++;
  rtn[it] = '\0';
  return (rtn);
}

char	*change_filext(char *filename, char *new_ext)
{
  int	it;
  int	new_size;

  it = 0;
  new_size = 0;
  while (filename[it])
    {
      if (filename[it] == '.')
	new_size = it;
      it++;
    }
  if (new_size == 0)
    new_size = it;
  return (create_filename(filename, new_ext, new_size));
}
