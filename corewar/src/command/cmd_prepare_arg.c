/*
** cmd_prepare_arg.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr 12 11:05:04 2014 Laurent Fourrier
** Last update Sun Apr 13 06:13:28 2014 Laurent Fourrier
*/

#include "command.h"

t_cmd_args	cmd_prepare_arg(char parambyte, int arg_nbr)
{
  char		param;
  t_cmd_args	rtn;

  param = (parambyte >> (6 - (arg_nbr * 2))) & 3;
  if (param == 1)
    rtn.type = T_REG;
  else if (param == 2)
    rtn.type = T_DIR;
  else if (param == 3)
    rtn.type = T_IND;
  else
    rtn.type = 0;
  rtn.type = 0;
  return (rtn);
}
