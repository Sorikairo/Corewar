/*
** is_valid_args.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Mar 26 16:56:46 2014 Laurent Fourrier
** Last update Sun Apr 13 16:04:14 2014 Laurent Fourrier
*/

#include <stddef.h>
#include "checker.h"
#include "op.h"

char		get_arg_type(char *arg)
{
  if (arg[0] == DIRECT_CHAR)
    return (T_DIR);
  else if (arg[0] == 'r')
    return (T_REG);
  else if ((arg[0] >= '0' && arg[0] <= '9') || arg[0] == '-' ||
	   arg[0] == LABEL_CHAR)
    return (T_IND);
  return (0);
}

int		is_valid_args(char *mnemonic, char **args)
{
  char		arg_type;
  int		it;
  op_t		op;

  it = 0;
  op = get_op(mnemonic);
  while (args[it] != NULL)
    {
      arg_type = get_arg_type(args[it]);
      if ((op.type[it] & arg_type) == 0)
	return (0);
      it++;
    }
  return (1);
}
