/*
** get_indirect_value.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 21:27:58 2014 Laurent Fourrier
** Last update Sat Apr 12 22:22:39 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "arena.h"

int	get_indirect_value(t_arena *arena, int address)
{
  int	*buf;
  int	rtn;

  buf = get_memory_data_be(arena, address, 4);
  rtn = *buf;
  free(buf);
  return (rtn);
}
