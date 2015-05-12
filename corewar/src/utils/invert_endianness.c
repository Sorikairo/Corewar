/*
** invert_endianness.c for corewar in /home/fourri_l/Projects/CPE_2014_corewar/corewar
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Tue Apr  8 21:22:32 2014 Laurent Fourrier
** Last update Tue Apr  8 21:23:53 2014 Laurent Fourrier
*/

void	invert_endianness(void *vdata, int size)
{
  char	buf;
  char	*data;
  int	it;

  data = vdata;
  it = 0;
  while (it < (size / 2))
    {
      buf = data[size - it - 1];
      data[size - it - 1] = data[it];
      data[it] = buf;
      it++;
    }
}
