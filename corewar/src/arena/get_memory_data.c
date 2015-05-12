/*
** get_memory_data.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 21:08:18 2014 Laurent Fourrier
** Last update Sun Apr 13 14:12:00 2014 Laurent Fourrier
*/

#include "utils.h"
#include "arena.h"
#include "op.h"

void	*get_memory_data(t_arena *arena, int address, int size)
{
  char	*rtn;
  int	it;

  rtn = xmalloc(size);
  it = 0;
  while (it < size)
    {
      address %= MEM_SIZE;
      rtn[it++] = arena->memory[address++];
    }
  return (rtn);
}

void	*get_memory_data_be(t_arena *arena, int address, int size)
{
  char	*rtn;

  rtn = get_memory_data(arena, address, size);
  if (!is_big_endian())
    invert_endianness(rtn, size);
  return (rtn);
}
