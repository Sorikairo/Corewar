/*
** check_cor_header.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Mar 25 17:19:57 2014 Laurent Fourrier
** Last update Tue Mar 25 17:22:18 2014 Laurent Fourrier
*/

#include <stddef.h>
#include "reader.h"

int	check_cor_header(t_cor_file *cor)
{
  if (cor->name == NULL)
    {
      write_str(g_fstdout, "Error: your champion don't have a name\n");
      flush_file(g_fstdout);
      return (-1);
    }
  if (cor->comment == NULL)
    {
      write_str(g_fstdout, "Error: your champion don't have a comment\n");
      flush_file(g_fstdout);
      return (-1);
    }
  return (0);
}
