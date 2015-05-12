/*
** get_asm_func.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun Apr 13 01:50:10 2014 Laurent Fourrier
** Last update Sun Apr 13 06:19:00 2014 Laurent Fourrier
*/

#include <stddef.h>
#include "asm_func.h"
#include "op.h"

t_asm_func	g_asm_func[] =
  {
    {1, &asm_live},
    {2, &asm_ld},
    {3, &asm_st},
    {4, &asm_add},
    {5, &asm_sub},
    {6, &asm_and},
    {7, &asm_or},
    {8, &asm_xor},
    {9, &asm_zjmp},
    {10, &asm_ldi},
    {11, &asm_sti},
    {12, &asm_fork},
    {13, &asm_lld},
    {14, &asm_lldi},
    {15, &asm_lfork},
    {16, &asm_aff},
    {0, NULL}
  };

t_asm_func	get_asm_func(char opcode)
{
  int		it;

  it = 0;
  while (g_asm_func[it].opcode)
    {
      if (g_asm_func[it].opcode == opcode)
	return (g_asm_func[it]);
      it++;
    }
  return (g_asm_func[it]);
}
