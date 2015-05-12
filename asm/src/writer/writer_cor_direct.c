/*
** writer_cor_direct.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr  2 11:16:43 2014 Laurent Fourrier
** Last update Sat Apr  5 13:39:38 2014 Laurent Fourrier
*/

#include "utils.h"

void		writer_cor_direct(t_file *file, int dir)
{
  write_data_be(file, &dir, 4);
}
