/*
** byte_toshort_be.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 06:08:19 2014 Laurent Fourrier
** Last update Sun Apr 13 06:10:46 2014 Laurent Fourrier
*/

#include "utils.h"

short	byte_toshort_be(char *byte)
{
  short	rtn;

  rtn = 0;
  if (is_big_endian())
    {
      rtn |= (byte[0] << 8) & 0xFF;
      rtn |= (byte[1]) & 0xFF;
    }
  else
    {
      rtn |= (byte[0]) & 0xFF;
      rtn |= (byte[1] << 8) & 0xFF;
    }
  return (rtn);
}
