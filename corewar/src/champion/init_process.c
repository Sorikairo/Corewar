/*
** init_process.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 16:58:51 2014 Laurent Fourrier
** Last update Sun Apr 13 03:22:21 2014 Laurent Fourrier
*/

#include "champion.h"
#include "op.h"

void	reset_registers(int *reg)
{
  int	it;

  it = 0;
  while (it < REG_NUMBER)
    reg[it++] = 0;
}

void	init_process(t_process *proc)
{
  proc->pc = 0;
  proc->carry = 0;
  proc->cycles_left = -42;
  reset_registers(proc->reg);
}
