/*
** xmalloc.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Apr  7 13:47:08 2014 Laurent Fourrier
** Last update Mon Apr  7 13:51:59 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>

void	*xmalloc(int size)
{
  void	*rtn;

  if ((rtn = malloc(size)) == NULL)
    {
      write_str(g_fstdout, "Error: can't malloc\n");
      flush_file(g_fstdout);
      exit(0);
    }
  return (rtn);
}
