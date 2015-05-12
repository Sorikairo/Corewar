/*
** write_memory_data.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  9 10:54:01 2014 Laurent Fourrier
** Last update Sun Apr 13 14:11:41 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tsys.h>
#include "utils.h"
#include "arena.h"
#include "op.h"

void	write_memory_data(t_arena *arena, void *data, int address, int size)
{
  char	*cdata;
  int	it;

  it = 0;
  cdata = data;
  while (it < size)
    {
      address %= MEM_SIZE;
      arena->memory[address++] = cdata[it++];
    }
}

void	write_memory_data_be(t_arena *arena, void *data, int address, int size)
{
  char	*tmp;

  tmp = xmalloc(size);
  ts_memcpy(data, tmp, size);
  if (!is_big_endian())
    invert_endianness(tmp, size);
  write_memory_data(arena, tmp, address, size);
  free(tmp);
}
