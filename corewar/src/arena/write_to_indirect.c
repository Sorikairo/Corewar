/*
** write_to_indirect.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  9 11:08:48 2014 Laurent Fourrier
** Last update Sun Apr 13 05:58:22 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "arena.h"
#include "utils.h"

void	write_to_indirect(t_arena *arena, int pc, int address, int value)
{
  short	*addr_ptr;

  addr_ptr = get_memory_data_be(arena, address, 2);
  write_memory_data_be(arena, &value, pc + *addr_ptr, 4);
  free(addr_ptr);
}
