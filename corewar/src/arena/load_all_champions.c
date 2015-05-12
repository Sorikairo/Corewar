/*
** load_all_champions.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 16:37:49 2014 Laurent Fourrier
** Last update Sun Apr 13 17:11:37 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include "arena.h"
#include "op.h"

void		put_unreadable_error(char *file)
{
  write_str(g_fstdout, "Error: file ");
  write_str(g_fstdout, file);
  write_str(g_fstdout, " is unreadable\n");
  flush_file(g_fstdout);
  exit(0);
}

int		load_all_champions(t_arena *arena, int chmp_nbr, char **chmp)
{
  int		it;
  int		offset;
  t_file	*file;

  it = 0;
  while (it < chmp_nbr)
    {
      offset = (MEM_SIZE / chmp_nbr) * it;
      file = open_file(chmp[it], FILE_R);
      if (!file || !is_readable(file))
	{
	  put_unreadable_error(chmp[it]);
	  if (file)
	    close_file(file);
	  return (-1);
	}
      if (load_champion(arena, file, chmp[it], offset) == -1)
	return (-1);
      it++;
    }
  return (0);
}
