/*
** is_valid_mnemonic.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 17:26:39 2014 Laurent Fourrier
** Last update Tue Mar 25 18:39:06 2014 Laurent Fourrier
*/

#include "checker.h"
#include "op.h"

int		is_valid_mnemonic(char *mnemonic)
{
  op_t		op;

  op = get_op(mnemonic);
  return (op.mnemonique != 0);
}
