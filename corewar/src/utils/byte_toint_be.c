/*
** byte_toint_be.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr 12 11:17:57 2014 Laurent Fourrier
** Last update Sat Apr 12 11:20:37 2014 Laurent Fourrier
*/

#include "utils.h"

int	byte_toint_be(char *byte)
{
  int	rtn;

  rtn = 0;
  if (is_big_endian())
    {
      rtn |= (byte[0] << 24) & 0xFF;
      rtn |= (byte[1] << 16) & 0xFF;
      rtn |= (byte[2] << 8) & 0xFF;
      rtn |= (byte[3]) & 0xFF;
    }
  else
    {
      rtn |= (byte[0]) & 0xFF;
      rtn |= (byte[1] << 8) & 0xFF;
      rtn |= (byte[2] << 16) & 0xFF;
      rtn |= (byte[3] << 24) & 0xFF;
    }
  return (rtn);
}
