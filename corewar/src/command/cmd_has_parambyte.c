/*
** cmd_has_parambyte.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 11 22:33:53 2014 Laurent Fourrier
** Last update Sat Apr 12 10:27:15 2014 Laurent Fourrier
*/

#include "op.h"

char	g_no_parambyte[] =
  {
    0x01, 0x09, 0x0C, 0x0F, 0x00
  };

char	cmd_has_parambyte(char opcode)
{
  int	it;

  it = 0;
  while (g_no_parambyte[it])
    {
      if (g_no_parambyte[it++] == opcode)
	return (0);
    }
  return (1);
}
