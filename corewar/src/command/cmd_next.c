/*
** cmd_next.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 11 22:20:39 2014 Laurent Fourrier
** Last update Sun Apr 13 12:56:36 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "arena.h"
#include "champion.h"
#include "command.h"

t_command	cmd_next(t_arena *arena, t_process *process)
{
  char		*buf;
  int		size;

  buf = get_memory_data(arena, process->pc, 2);
  if (cmd_has_parambyte(buf[0]))
    {
      size = cmd_get_size(buf[1]);
      free(buf);
      return (cmd_parse_wparam(arena, process, size));
    }
  free(buf);
  return (cmd_parse_woparam(arena, process));
}
