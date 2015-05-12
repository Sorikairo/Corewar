/*
** writer_cor_register.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  2 10:45:39 2014 Laurent Fourrier
** Last update Sat Apr  5 10:22:09 2014 Laurent Fourrier
*/

#include <tio.h>
#include <tutils.h>

void		writer_cor_register(t_file *file, int reg)
{
  char		w_reg;

  w_reg = (char)(reg & 0xFF);
  write_data(file, &w_reg, 1);
}
