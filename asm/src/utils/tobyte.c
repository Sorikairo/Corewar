/*
** tobyte.c for corewer in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Mar 30 18:57:24 2014 Laurent Fourrier
** Last update Mon Mar 31 16:41:51 2014 Laurent Fourrier
*/

#include "utils.h"

void	*short_tobyte(short data)
{
  char	*rtn;

  rtn = xmalloc(2);
  rtn[0] = (data) & 0xFF;
  rtn[1] = (data >> 8) & 0xFF;
  return (rtn);
}

void	*int_tobyte(int data)
{
  char	*rtn;

  rtn = xmalloc(4);
  rtn[0] = (data) & 0xFF;
  rtn[1] = (data >> 8) & 0xFF;
  rtn[2] = (data >> 16) & 0xFF;
  rtn[3] = (data >> 24) & 0xFF;
  return (rtn);
}
