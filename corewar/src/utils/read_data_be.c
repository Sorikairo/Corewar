/*
** read_data_be.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Mon Apr  7 13:42:49 2014 Laurent Fourrier
** Last update Tue Apr  8 21:24:09 2014 Laurent Fourrier
*/

#include <tio.h>
#include "utils.h"

void	*read_data_be(t_file *file, void *data, int size)
{
  read_data(file, data, size);
  if (!is_big_endian())
    invert_endianness(data, size);
  return (data);
}
