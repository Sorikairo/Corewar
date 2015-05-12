/*
** get_op.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 18:33:32 2014 Laurent Fourrier
** Last update Tue Mar 25 18:35:57 2014 Laurent Fourrier
*/

#include <tutils.h>
#include "op.h"

op_t	get_op(char *mnemonic)
{
  int	it;

  it = 0;
  while (op_tab[it].mnemonique != 0)
    {
      if (utl_strcmp(op_tab[it].mnemonique, mnemonic) == 0)
	return (op_tab[it]);
      it++;
    }
  return (op_tab[it]);
}
