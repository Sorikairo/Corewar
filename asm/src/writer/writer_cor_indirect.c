/*
** writer_cor_indirect.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 10:23:07 2014 Laurent Fourrier
** Last update Sat Apr  5 13:39:56 2014 Laurent Fourrier
*/

#include "utils.h"

void	writer_cor_indirect(t_file *file, int ind)
{
  short	w_ind;

  w_ind = (short)(ind & 0xFFFF);
  write_data_be(file, &w_ind, 2);
}
