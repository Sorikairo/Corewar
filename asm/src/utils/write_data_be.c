/*
** write_data_be.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/asm
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Thu Mar 27 16:52:32 2014 Laurent Fourrier
** Last update Tue Apr  1 14:24:16 2014 Laurent Fourrier
*/

#include <stdlib.h>
#include <tio.h>
#include "utils.h"

char	is_big_endian()
{
  char	*bytes;
  short	checker;

  checker = 1;
  bytes = (char*)(&checker);
  if (bytes[0] == 1)
    return (0);
  return (1);
}

/*
** This is the most beautiful function I ever saw in my life
*/
void	*invert_endianness(void *data, int size)
{
  char	*cdata;
  char	*crtn;
  int	it;

  crtn = xmalloc(size);
  cdata = data;
  it = 0;
  while (it <= (size - 1))
    {
      crtn[it] = cdata[size - it - 1];
      it++;
    }
  return (crtn);
}

void	write_data_be(t_file *file, void *data, int size)
{
  void	*vdata;

  if (is_big_endian())
    write_data(file, data, size);
  else
    {
      vdata = invert_endianness(data, size);
      write_data(file, vdata, size);
      free(vdata);
    }
}
