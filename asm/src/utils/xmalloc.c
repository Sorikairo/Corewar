/*
** xmalloc.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 15:59:38 2014 Laurent Fourrier
** Last update Tue Mar 25 16:35:08 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>

void	*xmalloc(int size)
{
  void	*rtn;

  rtn = malloc(size);
  if (rtn == NULL)
    {
      write_str(g_fstdout, "Can't perform malloc\n");
      flush_file(g_fstdout);
      close_fstd();
      exit(0);
    }
  return (rtn);
}
