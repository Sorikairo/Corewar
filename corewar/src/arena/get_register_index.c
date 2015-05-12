/*
** get_register_index.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 22:23:36 2014 Laurent Fourrier
** Last update Tue Apr  8 22:30:43 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include "arena.h"

char	get_register_index(t_arena *arena, int address)
{
  char	rtn;
  char	*rtn_ptr;

  rtn_ptr = get_memory_data(arena, address, 1);
  rtn = *rtn_ptr;
  free(rtn_ptr);
  rtn--;
  if (rtn < 0 || rtn >= REG_NUMBER)
    rtn = 0;
  return (rtn);
}
