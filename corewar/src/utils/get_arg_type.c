/*
** get_arg_type.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 21:54:21 2014 Laurent Fourrier
** Last update Tue Apr  8 22:01:43 2014 Laurent Fourrier
*/

#include "op.h"

char	get_arg_type(char parambyte, char arg_nbr)
{
  arg_nbr = 4 - arg_nbr;
  parambyte = (parambyte >> (2 * arg_nbr)) & 0x03;
  if (parambyte == 1)
    return (T_REG);
  if (parambyte == 2)
    return (T_DIR);
  if (parambyte == 3)
    return (T_IND);
  return (0);
}
