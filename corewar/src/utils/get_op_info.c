/*
** get_op_info.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr 12 10:37:36 2014 Laurent Fourrier
** Last update Sun Apr 13 12:35:54 2014 Laurent Fourrier
*/

#include "op.h"

op_t	get_op_info(char opcode)
{
  int	it;

  it = 0;
  while (op_tab[it].code)
    {
      if (op_tab[it].code == opcode)
	return (op_tab[it]);
      it++;
    }
  return (op_tab[it]);
}
