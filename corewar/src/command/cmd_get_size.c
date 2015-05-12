/*
** cmd_get_size.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri Apr 11 22:28:27 2014 Laurent Fourrier
** Last update Fri Apr 11 22:32:33 2014 Laurent Fourrier
*/

#include "op.h"

int	cmd_get_size(char parambyte)
{
  char	cur_param;
  int	it;
  int	rtn;

  it = 0;
  rtn = 2;
  while (it < 3)
    {
      cur_param = parambyte >> (6 - it++) & 3;
      if (cur_param == 1)
	rtn++;
      else if (cur_param == 2)
	rtn += DIR_SIZE;
      else if (cur_param == 3)
	rtn += IND_SIZE;
    }
  return (rtn);
}
