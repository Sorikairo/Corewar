/*
** writer_cor_arg.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat Apr  5 13:16:24 2014 Laurent Fourrier
** Last update Sat Apr  5 15:26:35 2014 Laurent Fourrier
*/

#include "reader.h"
#include "writer.h"
#include "op.h"

void	writer_cor_arg(t_file *file, t_cor_arg arg)
{
  if (arg.type == T_REG)
    writer_cor_register(file, arg.val);
  else if (arg.type == T_DIR)
    writer_cor_direct(file, arg.val);
  else if (arg.type == T_IND)
    writer_cor_indirect(file, arg.val);
}
