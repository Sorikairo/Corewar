/*
** is_valid_args_nbr.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 18:32:14 2014 Laurent Fourrier
** Last update Tue Mar 25 18:54:21 2014 Laurent Fourrier
*/

#include <tutils.h>
#include "checker.h"
#include "op.h"

int		is_valid_args_nbr(char *mnemonic, char **args)
{
  int		args_nbr;
  op_t		op;

  op = get_op(mnemonic);
  args_nbr = get_wordarr_len(args);
  if (args_nbr != op.nbr_args)
    return (0);
  return (1);
}
